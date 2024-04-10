#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define long long long
#define inf(type) (numeric_limits<type>::max())

long n;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    ii ans;
    for (int i = 1; i <= n; ++i) {
        long cnt = 1, cur = i;
        for (; cur <= n; cur += cnt + i, ++cnt);
        ans = max(ans, ii(cnt - 1, i));
    }

    cout << ans.xx << '\n';
    for (int i = 0; i < ans.xx - 1; ++i) cout << ans.yy + i << ' ', n -= ans.yy + i;
    cout << n;



    return 0;
}