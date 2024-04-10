#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace Solution {

#define maxn 201010
int n, m;
ii a[maxn], b[maxn];

int main() {
    cin >> n;
    int al = -inf(int), ar = inf(int);
    int bl = -inf(int), br = inf(int);
    rep (i, n) {
        cin >> a[i].xx >> a[i].yy;
        al = max(al, a[i].xx);
        ar = min(ar, a[i].yy);
    }
    cin >> m;
    rep (i, m) {
        cin >> b[i].xx >> b[i].yy;
        bl = max(bl, b[i].xx);
        br = min(br, b[i].yy);
    }
    long ans = 0;
    rep (i, n) {
        if (a[i].xx > br) ans = max(ans, (long)a[i].xx - br);
        if (a[i].yy < bl) ans = max(ans, (long)bl - a[i].yy);
    }
    rep (i, m) {
        if (b[i].xx > ar) ans = max(ans, (long)b[i].xx - ar);
        if (b[i].yy < al) ans = max(ans, (long)al - b[i].yy);
    }
    cout << ans;

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    return Solution::main();
}