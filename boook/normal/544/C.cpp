#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 800
#define INF 0x3f3f3f3f

int n , m , b , mod , x[MAX];
int dp[2][MAX][MAX];

int32_t main(){
    cin >> n >> m >> b >> mod;
    REP(i , 1 , n + 1) cin >> x[i];
    dp[0][0][0] = 1 % mod;
    int z = 0;
    REP(i , 1 , n + 1){
        REP(fk , 0 , m + 1){
            int qq = (fk == 0) ? b + 1 : x[i];
            REP(j , 0 , qq){
                int tmp = dp[z][0 + fk][j] % mod;
                REP(k , 0 , m + 1){
                    if(k + fk > m) break;
                    if(j + k * x[i] > b) break;
                    dp[z ^ 1][k + fk][j + k * x[i]] = tmp % mod;
                    tmp = (tmp + dp[z][k + 1 + fk][j + (k + 1) * x[i]]) % mod;
                }
            }
        }
        z = 1 - z;
    }
    int ans = 0;
    REP(i , 0 , b + 1){
        ans = (ans + dp[z][m][i]) % mod;
    }
    cout << ans << endl;
    // DB4(i , k + fk , j + k * x[i] , dp[z ^ 1][k + fk][j + k * x[i]]);
    return 0;
}