#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#define INF 1000000000
#define fi first
#define se second
#define N 83
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int dp[2][N][N][N];
vector<pii> G[N];
inline void upd(int &x, int y)
{
    if (x == -1)
        x = y;
    else x = min(x, y);
}

void prob(int x, int i, int j, int l, int s)
{
    int nxt;
    for (pii lane : G[x])
    {
        nxt = lane.first;
        if (nxt <= i || nxt >= j)
            continue;
        upd(dp[1][i][nxt][l + 1], dp[s][i][j][l] + lane.second);
        upd(dp[0][nxt][j][l + 1], dp[s][i][j][l] + lane.second);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, k, i, j, m, l, s;
    cin >> n >> k;
    cin >> m;
    for (i = 1; i <= n; i++)
    {
        G[0].push_back(MP(i, 0));
        G[n + 1].push_back(MP(i, 0));
    }
    int a, b, c;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back(MP(b, c));
    }
    dp[0][0][n + 1][0] = 0;
    for (i = 0; i <= n; i++)
        for (j = n + 1; j; j--)
            for (l = 0; l < k; l++)
                for (s = 0; s <= 1; s++)
                    if (dp[s][i][j][l] != -1)
                    {
                        if (s == 0)
                            prob(i, i, j, l, s);
                        else
                            prob(j, i, j, l, s);
                    }

    int ans = -1;
    for (i = 0; i <= n; i++)
        for (j = n + 1; j; j--)
            for (s = 0; s <= 1; s++)
                if (dp[s][i][j][k] != -1)
                    upd(ans, dp[s][i][j][k]);
    cout << ans << endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/