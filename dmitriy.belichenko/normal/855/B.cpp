#include<cstring>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
vector<vector<int>>g;
bool used[100005];
int l = 0, r = 0;
ll INF = 1LL << 62;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> c(3);
    cin >> c[0] >> c[1] >> c[2];
    vector<ll> a(n);
    ll dp[n  + 1][4];
    for(int i = 0; i< n  + 1; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        
        for(int j = 0; j < 4; j++)
        {
            if(dp[i][j] == -INF)
            {
                continue;
            }
            dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
            if(j + 1 < 4)
                dp[i][j + 1] = max(dp[i][j+1] , dp[i][j] + c[j] * a[i]);
        }
    }
    
    cout << dp[n][3]  << "\n";
    return 0;
}