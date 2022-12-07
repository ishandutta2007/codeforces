#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 998244353;

const int maxn = 200005;
int n;
pair<pair<int, int>, int> a[maxn];
ll cnt[maxn];
ll tag[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    ll cur = 0;
    for (int i = n; i >= 1; --i) {
        int x = a[i].fi.fi, y = a[i].fi.se, s = a[i].se;
        if (s) ++cnt[i];
        cur = (cur + tag[i]) % M;
        cnt[i] = (cnt[i] + cur) % M;
        int l = 0, r = i;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (a[m].fi.fi > y)
                r = m;
            else
                l = m;
            // cout << "d " << a[m].fi.fi << " " << y << "\n";
            // cout << "c " << l << " " << r << " " << m << "\n";
        }
        // cout << "r: " << r << "\n";
        tag[r - 1] = (tag[r - 1] - cnt[i] + M) % M;
        tag[i - 1] = (tag[i - 1] + cnt[i]) % M;
        ans = (ans + cnt[i] * (x - y)) % M;
        // scout << i << ": " << cnt[i] << "\n";
    }
    ans = (ans + a[n].fi.fi + 1) % M;
    cout << ans << "\n";
    return 0;
}