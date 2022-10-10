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
vi a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (count(a.begin(), a.end(), 0) == n) return cout << "NO", 0;
    cout << "YES" << '\n';

    ve<ii> ans;
    ans.push_back(ii(0, -1));
    int i;
    for (i = 0; i < n; ++i) {
        ++ans.back().yy;
        if (a[i] != 0) break;
    }

    for (++i; i < n; ++i) {
        if (a[i] != 0) {
            ans.push_back(ii(i, i - 1));
        }
        ++ans.back().yy;
    }

    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].xx + 1<< ' ' << ans[i].yy + 1<< '\n';

    return 0;
}