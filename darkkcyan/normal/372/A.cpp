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

int n;
vi a;

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    int ans = n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.bb, a.ee);
    int l = 0, r = n - n / 2;
    for (; l < n / 2; ++l) {
        r = max(r, l);
        if (a[l] == -1) continue;
        for (; r < n and a[l] * 2 > a[r]; ++r);
        if (r < n) {
            ans --;

            a[r] = -1;
            ++r;
        }
    }
    cout << ans;
    return 0;
}