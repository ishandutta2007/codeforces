#include <bits/stdc++.h>
using namespace std;
#define maxn 200090
#define int long long

int t;
int n, m, a, b, p[maxn], d[maxn], suf[maxn];
pair<int, int> x[maxn];


int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n >> m >> a >> b;
        for (int i = 1; i <= n; ++ i) cin >> x[i].second;
        for (int i = 1; i <= n; ++ i) cin >> x[i].first;
        sort(x + 1, x + 1 + n);
        
        for (int i = 1; i <= n; ++ i) suf[i] = suf[i + 1] = 0;
        for (int i = n; i >= 1; -- i) suf[i] += suf[i + 1] + (x[i].second == 0);

//        cout << a << " " << b << endl;
//        for (int i = 1; i <= n; ++ i) cout << x[i].second << " "; cout << endl;
//        for (int i = 1; i <= n; ++ i) cout << x[i].first << " "; cout << endl;
//        for (int i = 1; i <= n; ++ i) cout << suf[i] << " "; cout << endl;

        for (int i = 1; i <= n; ++ i) p[i] = p[i - 1] + (x[i].second == 0 ? a : b);
        int ans = 0;
        for (int i = 1; i <= n; ++ i) {
            if (p[i - 1] < x[i].first) {
                ans = max(ans, (i - 1) + min((x[i].first - p[i - 1] - 1) / a, suf[i]));
            }
        }
        if (p[n] <= m) ans = n;
//        cout << "ans = " ;
        cout << ans << "\n";
    }
    return 0;
}