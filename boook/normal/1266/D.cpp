#include <bits/stdc++.h>
using namespace std;
#define maxn 300000 + 10
#define int long long

int n, m, x[maxn][3], o[maxn], ans[maxn][3];
int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) cin >> x[i][0] >> x[i][1] >> x[i][2];

    for (int i = 1; i <= m; ++ i) o[x[i][0]] += x[i][2];
    for (int i = 1; i <= m; ++ i) o[x[i][1]] -= x[i][2];

    int pos = 1, anspo = 0;
    
    for (int i = 1; i <= n; ++ i) {
        while (o[i] > 0) {
            while (o[pos] >= 0) pos ++;
            int sml = min(-o[pos], o[i]);
            ans[anspo][0] = i;
            ans[anspo][1] = pos;
            ans[anspo][2] = sml;
            anspo ++;
            o[pos] += sml;
            o[i] -= sml;
        }
    }
    cout << anspo << "\n";
    for (int i = 0; i < anspo; ++ i)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    return 0;
}