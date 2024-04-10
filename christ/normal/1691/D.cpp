#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
array<int,2> tree[MN<<1];
long long treemax[MN<<1],treemin[MN<<1], psa[MN];
void update (int i, int v, int id) {
    for (tree[i+=MN-1]={v,id};i>1;i>>=1)
        tree[i>>1]=max(tree[i],tree[i^1]);
}
array<int,2> query (int l, int r) {
    array<int,2> ret = {INT_MIN,INT_MIN};
    for (l+=MN-1,r+=MN;l<r;l>>=1,r>>=1) {
        if (l&1) ret = max(ret,tree[l++]);
        if (r&1) ret = max(ret,tree[--r]);
    }
    return ret;
}
void updatemax (int i, long long v) {
    for (treemax[i+=MN-1]=v;i>1;i>>=1)
        treemax[i>>1] = max(treemax[i],treemax[i^1]);
}
void updatemin (int i, long long v) {
    for (treemin[i+=MN-1]=v;i>1;i>>=1)
        treemin[i>>1] = min(treemin[i],treemin[i^1]);
}
long long querymax (int l, int r) {
    long long ret = -1e18;
    for (l+=MN-1,r+=MN; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            ret = max(ret,treemax[l++]);
        }
        if (r&1) {
            ret = max(ret,treemax[--r]);
        }
    }
    return ret;
}
long long querymin (int l, int r) {
    long long ret = 1e18;
    for (l += MN-1, r += MN; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = min(ret,treemin[l++]);
        if (r&1) ret = min(ret,treemin[--r]);
    }
    return ret;
}
bool solve (int l, int r) {
    if (l >= r) return false;
    auto [x,i] = query(l,r);
    if (solve(l,i-1) || solve(i+1,r)) return true;
    return querymax(i,r) - querymin(l,i) > x;
}
void solve () {
    int n; scanf ("%d",&n);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        psa[i] = psa[i-1] + a[i];
        updatemin(i,psa[i-1]);
        updatemax(i,psa[i]);
        update(i,a[i],i);
    }
    if (solve(1,n)) printf ("NO\n");
    else printf ("YES\n");
}
int main () {
    for (auto &[l,r] : tree) l = INT_MIN, r = INT_MIN;
    for (auto &v : treemin) v = 1e18;
    for (auto &v : treemax) v = -1e18;
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}