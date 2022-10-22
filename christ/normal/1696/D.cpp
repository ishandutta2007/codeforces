#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5, MOD = 1e9 + 7;
int treeMN[MN<<1], treeMX[MN<<1];
void update (int i, int v, int* tree) {
    for (tree[i += MN - 1] = v; i > 1; i >>= 1)
        tree[i>>1] = min(tree[i],tree[i^1]);
}
int query (int l, int r, int *tree) {
    int ret = MOD;
    for (l += MN-1, r += MN; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = min(ret,tree[l++]);
        if (r&1) ret = min(ret,tree[--r]);
    }
    return ret;
}
void solve () {
    int n; scanf ("%d",&n);
    for (int i = 1; i <= n; i++) {
        update(i,MOD,treeMN);
        update(i,MOD,treeMX);
    }
    vector<int> a(n+1), dist(n+1);
    vector<int> stkMN, stkMX;
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        while (!stkMN.empty() && a[stkMN.back()] > a[i]) {
            int j = stkMN.back();
            stkMN.pop_back();
            update(j,MOD,treeMN);
        }
        while (!stkMX.empty() && a[stkMX.back()] < a[i]) {
            int j = stkMX.back();
            stkMX.pop_back();
            update(j,MOD,treeMX);
        }
        int prvlt = 0, prvgt = 0;
        if (!stkMN.empty()) prvlt = stkMN.back();
        if (!stkMX.empty()) prvgt = stkMX.back();
        if (i == 1) dist[i] = 0;
        else dist[i] = min(query(prvgt+1,i-1,treeMN), query(prvlt+1,i-1,treeMX))+1;
        assert(dist[i] < MOD);
        update(i,dist[i],treeMN);
        update(i,dist[i],treeMX);
        stkMN.push_back(i);
        stkMX.push_back(i);
    }
    printf ("%d\n",dist[n]);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}