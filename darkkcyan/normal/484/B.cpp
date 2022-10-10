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

#define NN (2e6 + 10)
int n;
vi a, cls;

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.bb, a.ee);
    a.resize(unique(a.bb, a.ee) - a.bb);

    cls.resize(NN, -1);
    for (int i = 0; i < sz(a); ++i) cls[a[i] + 1] = a[i];
    for (int i = 1; i < NN; ++i)
        if (cls[i] == -1) cls[i] = cls[i - 1];

    int ans = 0;
    for (int i = 0; i < sz(a); ++i) {
        int x = a[i];
        for (int f = x * 2; f < NN; f += x) {
            int y = cls[f];
            ans = max(ans, (x - (f - y) % x) % x);
        }
    }

    cout << ans;

    return 0;
}