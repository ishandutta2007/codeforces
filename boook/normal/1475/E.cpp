#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007ll
#define maxn 1010

int c[maxn][maxn], t, n, k, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	
    for (int i = 0; i < maxn; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            if (j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    cin >> t;
    while (t --) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        sort(x + 1, x + 1 + n, greater<int>());
        int v1 = 0, v2 = 0;
        for (int i = 1; i <= n; ++ i) {
            if (x[i] == x[k]) v1 ++;
            if (x[i] == x[k] && i <= k) v2 ++;
        }
        cout << c[v1][v2] << "\n";
    }
    return 0;
}