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

int n, d;
ve<ii> a;

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].xx >> a[i].yy;
    sort(a.bb, a.ee);
    int l = 0, r = 0;
    long ans = 0;
    long t = 0;
    for (; r < n; ++r) {
        t += (long)a[r].yy;
        for (; l < r and a[r].xx - a[l].xx >= d; ++l) t -= (long)a[l].yy;
        ans = max(ans, t);
    }
    cout << ans;

    return 0;
}