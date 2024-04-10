//  228

#include<bits/stdc++.h>
#define PI acos(-1)
#define fi first
#define se second
#define endl '\n'
#define m_p make_pair
#define P pair<int,int>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
//typedef __int64 ll;
typedef unsigned int uint;
const int maxn = 100 + 10;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll mod = 999911659 ,G = 3;



char s[maxn];
int n;
int dp[maxn][maxn][2];
int main()
{
    IOS;
    for(int i = 0;i <= maxn - 1; ++i)
    {
        for(int j = 0;j <= maxn - 1; ++j)
        {
            dp[i][j][1] = dp[i][j][0] = -INF;
        }
    }
    dp[0][0][1] = 0;
    dp[0][0][0] = 0;
    cin >> s + 1;
    cin >> n;
    for(int i = 1;i <= strlen(s + 1); ++i)
    {
        for(int j = 0;j <= n; ++j)
        {
            for(int h = 0;h <= j; ++h)
            { 
                if(s[i] == 'F')
                {
                    if(h & 1)//
                    {
                        dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - h][0]);
                        dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - h][1]);
                    }
                    else//
                    {
                        dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - h][1] + 1);
                        dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - h][0] - 1);
                    }
                }
                else
                {
                    if(h % 2 == 0)//
                    {
                        dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - h][0]);
                        dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - h][1]);
                    }
                    else
                    {
                        dp[i][j][1] = max(dp[i][j][1],dp[i - 1][j - h][1] + 1);
                        dp[i][j][0] = max(dp[i][j][0],dp[i - 1][j - h][0] - 1);
                    }
                }
            }
        }
    }
    int len = strlen(s + 1);
    int ans = max(dp[len][n][1],dp[len][n][0]);
    cout << ans << endl;
    return 0;
}