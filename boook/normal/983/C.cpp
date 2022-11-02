/*input
2
5 3
3 5
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , x[MAX][2] , dp[MAX][10][10][10][10];
inline void U(int &now , int val){ now = min(now , val); }
int32_t main(){
    IOS;
    cin >> n;
    MEM(dp , INF);
    REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
    dp[0][0][0][0][1] = 0;
    REP(i , 0 , n + 1){
        int from = x[i + 1][0] , to = x[i + 1][1];
        RREP(a , 9 , 0) RREP(b , 9 , 0) RREP(c , 9 , 0){
            REP(now , 1 , 10){
                if(a != 0) U(dp[i][0][b][c][a] , dp[i][a][b][c][now] + abs(now - a));
                if(b != 0) U(dp[i][a][0][c][b] , dp[i][a][b][c][now] + abs(now - b));
                if(c != 0) U(dp[i][a][b][0][c] , dp[i][a][b][c][now] + abs(now - c));

                if(a != 0 && b != 0 && c != 0){
                    U(dp[i + 1][to][b][c][a] , dp[i][a][b][c][now] + abs(now - from) + abs(from - a));
                    U(dp[i + 1][a][to][c][b] , dp[i][a][b][c][now] + abs(now - from) + abs(from - b));
                    U(dp[i + 1][a][b][to][c] , dp[i][a][b][c][now] + abs(now - from) + abs(from - c));
                    U(dp[i + 1][a][b][c][to] , dp[i][a][b][c][now] + abs(now - from) + abs(from - to));
                }
                else if(a == 0) U(dp[i + 1][to][b][c][from] , dp[i][a][b][c][now] + abs(now - from));
                else if(b == 0) U(dp[i + 1][a][to][c][from] , dp[i][a][b][c][now] + abs(now - from));
                else if(c == 0) U(dp[i + 1][a][b][to][from] , dp[i][a][b][c][now] + abs(now - from));
            }
        }
    }
    int ans = dp[n][0][0][0][1];
    REP(i , 1 , 9 + 1) ans = min(ans , dp[n][0][0][0][i]);
    cout << ans + n + n << endl;
    return 0;
}