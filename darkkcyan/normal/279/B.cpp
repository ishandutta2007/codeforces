#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, t;
vi a;

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> t;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = 0;
    int ans = 0;

    for (; r < n; ++r) {
        t -= a[r];
        while (t < 0 and l <= r) {
            t += a[l];
            ++l;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans;

    return 0;
}