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
#define rep(i,n) for(int i = -1; ++i < n; )

namespace sol {
// actual solution start here

#define maxn 101010
#define ep ((double)1e-7)
int n, p;
long a[maxn], b[maxn];

bool can(double time) {
    double tc = 0;
    rep(i, n) {
        double x = b[i] - time * a[i];
        if (x > -ep) continue;
        tc += -x;
    }
    double toctime = p * time;
    if (tc > toctime - ep) return false;
    return true;
}

int main() {
    cin >> n >> p;
    rep(i, n) cin >> a[i] >> b[i];
    if (can(1e15)) cout << -1, exit(0);
    double l = 0, r = 1e16;
    rep(step, 100) {
        double mid = l + (r - l) / 2;
        if (can(mid)) l = mid;
        else r = mid;
    }
    cout << r;

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}