#include <bits/stdc++.h>
using namespace std;
#define maxn 4000

int t, n, m, k, x[maxn], p[maxn];
int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++ i) 
            cin >> x[i];
        k = min(k, m - 1);
        int las = m - 1, ans = 0;
        for (int i = 0; i <= las; ++ i)
            p[i] = max(x[i + 1], x[n - (las - i)]);

        // for (int i = 0; i <= las; ++ i)
        //     cout << x[i + 1] << " " << x[n - (las - i)] << endl;

        for (int i = 0; i <= k; ++ i) {
            int big = 2000000000;
            for (int j = i; j <= las - (k - i); ++ j)
                big = min(big, p[j]);
            ans = max(ans, big);
        }
        cout << ans << "\n";
    }
    return 0;
}