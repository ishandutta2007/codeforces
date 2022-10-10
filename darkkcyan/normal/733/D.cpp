#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
typedef ve<int> vi;
typedef pair<int, int> ii;
typedef pair<int, vi> ivi;

ii sii(int u, int v) { if (u > v) return ii(v, u); return ii(u, v); }
int min3(int a, int b, int c) { return min(a, min(b, c)); }

map<ii, ii> ma;


int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    int n; cin >> n;

    ivi ans(0, vi());
    for (int i = 0; i < n; ++i) {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        ans = max(ans, ivi(min3(a[0], a[1], a[2]), vi(1, i)));
        vi t(2); t[0] = i;
        for (int f = 0; f < 3; ++f) {
            int g = (f + 1) % 3;
            int h = (g + 1) % 3;
            if (ma.count(sii(a[f], a[g]))) {
                ii x = ma[sii(a[f], a[g])];
                t[1] = x.yy;
                ans = max(ans, ivi(min3(a[f], a[g], x.xx + a[h]), t));
            }
        }
        for (int f = 0; f < 3; ++f) {
            int g = (f + 1) % 3;
            int h = (g + 1) % 3;
            ma[sii(a[f], a[g])] = max(ma[sii(a[f], a[g])], ii(a[h], i));
        }
    }

    cout << ans.yy.size() << '\n';
    for (int i = 0; i < sz(ans.yy); ++i) cout << ans.yy[i] + 1<< ' ';

    return 0;
}