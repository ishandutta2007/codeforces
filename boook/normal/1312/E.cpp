/*input

*/
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 520
#define inf 0x3f3f3f3f

int n, x[maxn], ok[maxn][maxn], val[maxn][maxn], dp[maxn];

int Dp(int l, int r) {
    if (ok[l][r] != 0) return ok[l][r];
    if (val[l][r] == -1) return ok[l][r] = -1;
    if (l == r) return ok[l][r] = 1;
    ok[l][r] = -1;
    for (int i = l; i < r; ++ i) {
        int v1 = Dp(l, i), v2 = Dp(i + 1, r);
        if (v1 != -1 && v2 != -1 && v1 == v2) ok[l][r] = 1;
    }
    return ok[l][r];
}

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    for (int i = 1; i <= n; ++ i) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j = i; j <= n; ++ j) {
            pq.push(x[j]);
            while (pq.size() >= 2) {
                int v1 = pq.top(); pq.pop();
                int v2 = pq.top(); pq.pop();
                if (v1 == v2) pq.push(v1 + 1);
                else {
                    pq.push(v1), pq.push(v2);
                    break;
                }
            }
            val[i][j] = pq.size() == 1 ? pq.top() : -1;
        }
    }
    for (int i = 1; i <= n; ++ i)
        for (int j = i; j <= n; ++ j) 
            Dp(i, j);
//    for (int i = 1; i <= n; ++ i) for (int j = i; j <= n; ++ j) if(ok[i][j] != -1) cout << i << " -- " << j << endl;
    memset(dp, inf, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            if (ok[j][i] == 1) dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}