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

int n;
string s;
vi a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin>> a[i];

    bool hassol = 0;
    for (int i = 0; i < n - 1; ++i)
    if (s[i] == 'R' and s[i + 1] == 'L') {
        hassol = 1;
        break;
    }

    if (!hassol) cout << "-1", exit(0);

    int ans = inf(int);
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) continue;
        if (s[i] == 'L') continue;
        int t = a[i + 1] - a[i];
        ans = min(ans, t / 2);
    }

    cout << ans;

    return 0;
}