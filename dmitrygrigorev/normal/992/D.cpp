#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e18 + 2007;

int a[MAXN];
int go[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    go[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i + 1] != 1) go[i] = i + 1;
        else go[i] = go[i + 1];
    }

    int ans = 0;
    for (int l = 0; l < n; ++l) {
        int r = l;
        ans += (k == 1);

        int f = a[l];
        int s = a[l];
        while (go[r] != n && a[go[r]] <= (INF / f)) {
            f *= a[go[r]];
            s += go[r] - r - 1 + a[go[r]];
            r = go[r];
            int want = -1;
            if (f % k == 0) want = f / k;
            int have = go[r] - r - 1;
            ans += (s <= want && want <= s + have);
        } 
    }

    cout << ans << '\n';
    return 0;
}