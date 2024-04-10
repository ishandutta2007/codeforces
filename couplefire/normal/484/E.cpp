#include <bits/stdc++.h>
using namespace std;
#define MAXN 131072

struct node{
    int siz, len, pre, suf;
    node *l, *r;
    node(int val){
        siz = 1;
        if(val) len = pre = suf = 1;
        else len = pre = suf = 0;
        l = r = NULL;
    }
    int getsiz(node *x){return x?x->siz:0;}
    int getlen(node *x){return x?x->len:0;}
    int getpre(node *x){return x?x->pre:0;}
    int getsuf(node *x){return x?x->suf:0;}
    node(node* ll, node* rr){
        l = ll, r = rr;
        siz = getsiz(l) + getsiz(r);
        len = max({getlen(l), getlen(r), getsuf(l) + getpre(r)});
        pre = (getpre(l) == getsiz(l))?getpre(l)+getpre(r):getpre(l);
        suf = (getsuf(r) == getsiz(r))?getsuf(r)+getsuf(l):getsuf(r);
    }
};

array<int, 4> merge(array<int, 4> a, array<int, 4> b){
    array<int, 4> res;
    res[0] = a[0]+b[0];
    res[1] = max({a[1], b[1], a[3]+b[2]});
    res[2] = (a[2] == a[0])?a[2]+b[2]:a[2];
    res[3] = (b[3] == b[0])?b[3]+a[3]:b[3];
    return res;
}

node* build(int tl = 0, int tr = MAXN-1){
    if(tl == tr) return new node(0);
    int tm = (tl+tr)/2;
    return new node(build(tl, tm), build(tm+1, tr));
}

node* upd(int ind, node* v, int tl = 0, int tr = MAXN-1){
    if(tl == tr) return new node(1);
    int tm = (tl+tr)/2;
    if(ind <= tm) return new node(upd(ind, v->l, tl, tm), v->r);
    return new node(v->l, upd(ind, v->r, tm+1, tr));
}

array<int, 4> query(int l, int r, node* v, int tl = 0, int tr = MAXN-1){
    if(tl > r || tr < l) return {0, 0, 0, 0};
    if(l <= tl && tr <= r) return {v->siz, v->len, v->pre, v->suf};
    int tm = (tl+tr)/2;
    return merge(query(l, r, v->l, tl, tm), query(l, r, v->r, tm+1, tr));
}

int n;
pair<int, int> arr[MAXN];
vector<node*> roots;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i].first; arr[i].second = i;
    }
    sort(arr+1, arr+n+1);
    reverse(arr+1, arr+n+1);
    roots.push_back(build());
    for(int i = 1; i<=n; i++) roots.push_back(upd(arr[i].second, roots.back()));
    // cout << query(5, 5, roots[1])->len << endl;
    int m; cin >> m;
    while(m--){
        int l, r, w; cin >> l >> r >> w;
        int lo = 1, hi = n;
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            if(query(l, r, roots[mid])[1] >= w) hi = mid;
            else lo = mid+1;
        }
        cout << arr[lo].first << endl;
    }
}