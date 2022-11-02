#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn (1 << 18)
#define ls (now << 1)
#define rs (now << 1 | 1)
#define inf 0x3f3f3f3f

int n, m, x[maxn], u[maxn], ans, nn;

int dp[maxn][4], siz[maxn];

void DFS(int now, int l, int r, int siz) {

    dp[now][0] = dp[now][1] = dp[now][2] = dp[now][3] = -inf;

    if (l + 3 == r) {
        int val = u[l] + u[l + 1] + u[l + 2] + u[l + 3];
        if (val >= 2) val = 2;

        if (val == 0) dp[now][0] = 0;
        else if (val == 1) {
            dp[now][1] = 1;
            dp[now][2] = 2;
        }
        else if (val == 2) dp[now][3] = 3;
    }
    else {
        DFS(ls, l, l + siz - 1, siz >> 1);
        DFS(rs, r - siz + 1, r, siz >> 1);

        for (int i = 0; i <= 3; ++ i) {
            for (int j = 0; j <= 3; ++ j) {
                if (i == 0) 
                    dp[now][j] = max(dp[now][j], dp[ls][i] + dp[rs][j] + j);
                else if (j == 0)
                    dp[now][i] = max(dp[now][i], dp[ls][i] + dp[rs][j] + i);
                else if (i == 3) 
                    dp[now][i] = max(dp[now][i], dp[ls][i] + dp[rs][j] + 3);
                else if (j == 3) 
                    dp[now][j] = max(dp[now][j], dp[ls][i] + dp[rs][j] + 3);
                else if (i == 2 && j == 2)
                    dp[now][2] = max(dp[now][2], dp[ls][i] + dp[rs][j] + 2);
                else if (i == 1 && j == 2)
                    dp[now][3] = max(dp[now][3], dp[ls][i] + dp[rs][j] + 3);
                else if (i == 2 && j == 1)
                    dp[now][3] = max(dp[now][3], dp[ls][i] + dp[rs][j] + 3);
                else if (i == 1 && j == 1) {
                    dp[now][1] = max(dp[now][1], dp[ls][i] + dp[rs][j] + 1);
                    dp[now][3] = max(dp[now][3], dp[ls][i] + dp[rs][j] + 4);
                }
                else assert(0);
            }
        }
    }
    // cout << now << " " << dp[now][0] << " " << dp[now][1] << " " << dp[now][2] << " " << dp[now][3] << endl;
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i)
        cin >> x[i], u[x[i]] = 1;

    nn = (1 << n);
    for (int i = 1; i <= nn; i += 2)
        ans += u[i] | u[i + 1];
    int cnt = 0;
    for (int i = 1; i <= nn; i += 1)
        cnt += u[i];

    if (cnt) ans ++;
    // cout << "[ans] = " << ans << "\n";
    DFS(1, 1, nn, nn / 2);

    int big = 0;
    big = max(big, dp[1][0]);
    big = max(big, dp[1][1]);
    big = max(big, dp[1][2]);
    big = max(big, dp[1][3]);
    cout << big + ans << "\n";
    return 0;
}