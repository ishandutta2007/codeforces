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

int n;
vi l, r;

int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    cin >> n;
    l.resize(n); r = l;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    int s = accumulate(l.bb, l.ee, 0) - accumulate(r.bb, r.ee, 0);
    ii ans(s, 0);
    for (int i = 0; i < n; ++i) {
        int t = s + 2 * (r[i] - l[i]);
        if (abs(ans.xx) < abs(t)) ans = ii(t, i + 1);
    }

    cout << ans.yy;


    return 0;
}