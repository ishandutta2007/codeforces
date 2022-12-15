#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 2e5 + 5;

ll a[MAXn], qr[MAXn], ans[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> qr[i];
        ll cur = 0;
        vector<pll> v;
        for (int i = 0; i < n; i++) {
            cur += a[i];
            if (!SZ(v) || cur > v.back().X)
                v.pb({cur, i});
        }
        for (int i = 0; i < m; i++) {
            ll t = qr[i];
            if (t > v.back().X && cur <= 0)
                ans[i] = -1;
            else if (t <= v.back().X) {
                auto it = lower_bound(ALL(v), make_pair(t, -1LL));
                ans[i] = it->Y;
            } else {
                ll bs = (t - v.back().X - 1) / cur + 1;
                t -= bs * cur;
                auto it = lower_bound(ALL(v), make_pair(t, -1LL));
                ans[i] = it->Y + bs * n;
            }
        }
        for (int i = 0; i < m; i++)
            cout << ans[i] << " \n"[i == m - 1];
    }
    
}