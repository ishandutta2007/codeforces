#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5, MOD = 1e9 + 7;
struct Node {
    int pre, suf, sum, sz;
} tree[MN<<2];
#define lc ind<<1
#define rc ind<<1|1
char s[MN];
void merge (Node l, Node r, Node &ret) {
    ret = {l.pre == l.sz ? l.pre + r.pre : l.pre, r.suf == r.sz ? r.suf + l.suf : r.suf,
           l.sum + r.sum + (l.suf > 0 && r.pre > 0), l.sz + r.sz};
}
void build (int ind, int l, int r) {
    if (l == r) {
        if (s[l] == '1') tree[ind] = {1,1,0,1};
        else tree[ind] = {0,0,0,1};
        return;
    }
    int mid = (l + r) / 2;
    build(lc,l,mid); build(rc,mid+1,r);
    merge(tree[lc],tree[rc],tree[ind]);
}
Node query (int ind, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return Node{0,0,0,0};
    if (l <= tl && tr <= r) return tree[ind];
    int mid = (tl + tr) / 2;
    Node lq = query(lc,tl,mid,l,r), rq = query(rc,mid+1,tr,l,r);
    merge(lq,rq,lq);
    return lq;
}
int main () {
    int n,q; scanf ("%d %d",&n,&q);
    vector<int> one(q+1), zero(q+1);
    vector<array<int,2>> lr(q+1);
    scanf ("%s",s+1);
    assert((int)strlen(s+1) == n);
    build(1,1,n);
    for (int i = 1; i <= q; i++) {
        scanf ("%d %d",&lr[i][0],&lr[i][1]);
        one[i] = query(1,1,n,lr[i][0],lr[i][1]).sum;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    build(1,1,n);
    for (int i = 1; i <= q; i++) {
        zero[i] = query(1,1,n,lr[i][0],lr[i][1]).sum;
        printf ("%d\n",max(zero[i],one[i]) + 1);
    }
    return 0;
}