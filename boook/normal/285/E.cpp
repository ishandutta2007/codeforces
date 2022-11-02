/*input
7 4
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int int_fast64_t
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , dp[MAX][MAX][2][2] , c[MAX][MAX] , gi[MAX] , x[MAX];
void U(int &now , int val){ now = (now + val) % mod; }
int32_t main(){
    IOS;
    cin >> n >> m;
    // dp[1][1][1][0] = 1;
    // dp[1][0][1][1] = 1;
    dp[0][0][0][1] = 1;
    REP(i , 1 , n + 1) REP(j , 0 , n + 1){

        if(j) U(dp[i][j][0][0] , dp[i - 1][j - 1][1][0]); // use i + 1
        if(j) U(dp[i][j][0][0] , dp[i - 1][j - 1][0][0]); // use i + 1

        if(j) U(dp[i][j][0][1] , dp[i - 1][j - 1][1][0]); // use i - 1
              U(dp[i][j][0][1] , dp[i - 1][j - 0][1][0]); // use others
              U(dp[i][j][0][1] , dp[i - 1][j - 0][0][0]); // use others

        if(j) U(dp[i][j][1][0] , dp[i - 1][j - 1][0][1]); // use i + 1
        if(j) U(dp[i][j][1][0] , dp[i - 1][j - 1][1][1]); // use i + 1

        if(j) U(dp[i][j][1][1] , dp[i - 1][j - 1][1][1]); // use i - 1
              U(dp[i][j][1][1] , dp[i - 1][j - 0][0][1]); // use others
              U(dp[i][j][1][1] , dp[i - 1][j - 0][1][1]); // use others

        // DB4("i = " , i , "j = " , j);
        // DB4(dp[i][j][0][0] , dp[i][j][0][1] , dp[i][j][1][0] , dp[i][j][1][1]);
    }

    REP(i , 0 , n + 1) REP(j , 0 , i + 1){
        if(j == 0 || i == j) c[i][j] = 1;
        else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    gi[0] = 1;
    REP(i , 1 , n + 1) gi[i] = gi[i - 1] * i % mod;

    REP(i , 0 , n + 1) x[i] = (dp[n][i][0][1] + dp[n][i][1][1]) % mod;
    REP(i , 0 , n + 1) x[i] = x[i] * gi[n - i] % mod;

    // REP(i , 0 , n + 1) DB4("get val = " , i , x[i] , "");
    // cout << " ----- " << endl;
    RREP(i , n - 1 , 0){
        REP(j , i + 1 , n + 1){
            x[i] = (x[i] - x[j] * c[j][i]) % mod;
            x[i] = (x[i] + mod) % mod;
        }
    }
    // REP(i , 0 , n + 1) DB4("get val = " , i , x[i] , "");
    cout << x[m] << endl;
    return 0;
}