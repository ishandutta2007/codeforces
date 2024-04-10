/*input
4 3
1 3 2 8 5 5 8 2 2 8 5 2
1 2 2 5
2 6 7
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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , c[MAX] , h[MAX] , f[MAX] , fc[MAX];
int dp[MAX] , T[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    int N = n * m;
    REP(i , 1 , N + 1) cin >> x[i] , c[x[i]] ++;
    REP(i , 1 , n + 1) cin >> f[i] , fc[f[i]] ++;
    REP(i , 1 , m + 1) cin >> h[i];
    int ans = 0;
    REP(now , 1 , MAX){
        if(fc[now] != 0){
            // DB4("people = " , fc[i] , "card = " , c[i]);
            if(fc[now] * m <= c[now]) ans += fc[now] * h[m];
            else {
                REP(ii , 1 , c[now] + 1) dp[ii] = 0;
                REP(ii , 1 , fc[now] + 1){
                    REP(jj , 0 , c[now] + 1) T[jj] = 0;
                    REP(jj , 0 , c[now] + 1){
                        REP(kk , 1 , m + 1){
                            if(kk + jj > c[now]) break;
                            T[jj + kk] = max(T[jj + kk] , dp[jj] + h[kk]);
                            // DB4("here = " , T[jj + kk] , h[kk] , dp[jj]);
                        }
                    }
                    REP(jj , 0 , c[now] + 1) dp[jj] = T[jj];
                }
                // DBGG("get = " , dp[c[i]]);
                int big = 0;
                REP(ii , 1 , c[now] + 1) big = max(big , dp[ii]);
                ans += big;
                // ans += dp[c[i]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}