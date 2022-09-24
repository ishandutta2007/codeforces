#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int dp[N + 5][21];
int dp2[N  + 5][2];
int sum (int a , int b)
{
    a+= b;
    if(a >= MOD)a-= MOD;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    int n = 1e6 + 5;
    vector<bool> prime (n+1, true);
    prime[0] = prime[1] = false;
    vector<int>pr(N);
    for (int i = 2; i <= n; i++)
    {
        if (pr[i] == 0)
        {
            pr[i] = i;
            if (i * 1ll * i <= n)
            {
                for (int j = i * i; j <= n; j += i) pr[j] = i;
            }
        }
        
    }
    dp2[0][0] = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int to = 1 - j;
            dp2[i + 1][to] = sum(dp2[i + 1][to] , dp2[i][j]);
            dp2[i + 1][j] = sum(dp2[i + 1][j] , dp2[i][j]);
            //cout << dp2[i][j] << " ";
        }
//cout << "\n";
    }
    dp[0][0] = 1;
    for(int j = 0; j < N; j++)
    {
       for(int i = 0; i <= 20; i++)
       {
            for(int k = 0; k + i <= 20; k++ )
            {
                dp[j + 1][i + k] = sum(dp[j + 1][i + k] , dp[j][i]);
                
            }
        }
    }
    cin >> q;
    while(q--)
    {
        int x , y;
        cin >> x >> y;
        int p = x;
        map<int , int> div;
        while(x != 1)
        {
            div[pr[x]]++;
            x/= pr[x];
        }
        long long ans = 1;
        for(auto i : div)
        {
            ans = ans * dp[y][i.second];
            //cout << i.first <<  " " << i.second << "\n";
            ans = ans % MOD;
        }
      //  cout << dp2[y][0] << " " << dp2[y][1] << "\n";
        cout << (ans * dp2[y][0]) % MOD<<"\n";
    }
}