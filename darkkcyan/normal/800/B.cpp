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

#define pp complex<double>
#define x real()
#define y imag()

double caldis(const pp& a, const pp& b, const pp& u) {
    pp ab = b - a; ab = pp(-ab.y, ab.x);
    return abs(ab.x * (u.x - a.x) + ab.y * (u.y - a.y)) / abs(ab);
}

int n;
ve<pp> a;

int main() {
    cin >> n;
    a.resize(n);
    rep(i, n) {
        int u, v; cin >> u >> v;
        a[i] = pp(u, v);
    } 

    double ans = inf(long);
    int pre = n - 2, nxt = 0;
    rep(u, n) {
        if (++pre == n) pre = 0;
        if (++nxt == n) nxt = 0;
        ans = min(ans, caldis(a[pre], a[nxt], a[u]));
    }
    cout << fixed << setprecision(12) << ans / 2;

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}