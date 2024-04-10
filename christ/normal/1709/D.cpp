#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 7, MM = 1e5;
int tree[MN<<1];
void update (int i, int v) {
    for (tree[i+=MN-1] = v; i > 1; i >>= 1)
        tree[i>>1] = max(tree[i],tree[i^1]);
}
int query (int l, int r) {
    int ret = 0;
    for (l += MN - 1, r += MN; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = max(ret,tree[l++]);
        if (r&1) ret = max(ret,tree[--r]);
    }
    return ret;
}
int main () { //brug
    int n,m; scanf ("%d %d",&n,&m);
    vector<int> a(m+1);
    for (int i = 1; i <= m; i++) scanf ("%d",&a[i]), update(i,a[i]);
    int q; scanf ("%d",&q);
    while (q--) {
        int x,y,x2,y2,k; scanf ("%d %d %d %d %d",&x,&y,&x2,&y2,&k);
        if (abs(x - x2) % k != 0 || abs(y-y2) % k != 0) {
            printf ("NO\n");
            continue;
        }
        if (y > y2) swap(y,y2);
        int jump = (n - x) / k;
        int canGo = x + jump * k;
        if (canGo > query(y,y2)) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}