#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 100100;
ll a[N];
pii mx[N];
ll sum[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n, s;
        cin >> n >> s;
        pii ans(0, 0);
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            mx[i] = max(pii(a[i], i), mx[i-1]);
            sum[i] = sum[i-1]+a[i];
            if (sum[i] <= s) {
                //cerr << " :: " << sum[i] << " " << i << endl;
                ans = max(ans, pii(i, 0));
            }
            if (sum[i]-mx[i].first <= s) {
                //cerr << " xx " << sum[i] << " - " << mx[i].first << " " << i-1 << endl;
                ans = max(ans, pii(i-1, mx[i].second));
            }
        }
        cout << ans.second << "\n";
    }
    return 0;
}