#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f
#define mod 998244353LL

int dp[MAX][MAX];
int a , b , c;
int32_t main(){
    IOS;
    cin >> a >> b >> c;
    REP(i , 0 , MAX) dp[i][0] = dp[0][i] = 1;
    REP(i , 1 , MAX) REP(j , 1 , MAX){
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * j) % mod;
    }
    int ans = dp[a][b] * dp[b][c] % mod * dp[c][a] % mod;
    cout << ans << endl;

    return 0;
}