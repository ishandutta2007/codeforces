#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, m;
vi mtc, mtd, mts;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    mtc.resize(n, m); mtd = mts = mtc;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int f = 0; f < m; ++f) {
            int d = min(f, m - f);
            if (isalpha(s[f])) mtc[i] = min(mtc[i], d);
            else if (isdigit(s[f])) mtd[i] = min(mtd[i], d);
            else mts[i] = min(mts[i], d);
        }
    }

    int ans = inf(int);
    for (int i = 0; i < n; ++i) {
        for (int f = 0; f < n; ++f) {
            if (f == i) continue;
            for (int g = 0; g < n; ++g) {
                if (g == i or g == f) continue;
                ans = min(ans, mtc[i] + mtd[f] + mts[g]);
            }
        }
    }

    cout << ans;

    return 0;
}