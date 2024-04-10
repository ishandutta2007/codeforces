#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int dp[102][102][2];

void solve()
{
    int n; cin >> n;
    int a = 0, b = 0;
    for(int i=1;i<=n;i++)
    {
        int x; cin >> x;
        if(x%2 == 0) b++;
        else a++;
    }
    
    dp[0][0][0] = 1;
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i == 0 && j == 0) continue;
            int asdf = i + j + 100 - n;
            if(asdf%2 == 0)
            {
                dp[i][j][0] = 0;
                if(i > 0) dp[i][j][0] |= dp[i-1][j][1];
                if(j > 0) dp[i][j][0] |= dp[i][j-1][0];
                dp[i][j][1] = 0;
                if(i > 0) dp[i][j][1] |= dp[i-1][j][0];
                if(j > 0) dp[i][j][1] |= dp[i][j-1][1];
            }
            else
            {
                dp[i][j][0] = 1;
                if(i > 0) dp[i][j][0] &= dp[i-1][j][0];
                if(j > 0) dp[i][j][0] &= dp[i][j-1][0];
                
                dp[i][j][1] = 1;
                if(i > 0) dp[i][j][1] &= dp[i-1][j][1];
                if(j > 0) dp[i][j][1] &= dp[i][j-1][1];
            }
        }
    }
    
    if(dp[a][b][0]) cout << "Alice\n";
    else cout << "Bob\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}