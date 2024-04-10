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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , k;
int an , bn , a[MAX] , b[MAX] , c;
int dp[2][MAX][60][60];
void U(int &now, int val){ now = max(now , val); }
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    cin >> an;
    REP(i , 1 , an + 1) cin >> c , a[c] = 1;
    cin >> bn;
    REP(i , 1 , bn + 1) cin >> c , b[c] = 1;

    if((m / 2) * k >= n){
        int cnt = 0;
        REP(i , 1 , n + 1) if(a[i] || b[i]) cnt ++;
        return cout << cnt << endl , 0;
    }
    else {
        // cout << "here" << endl;
        REP(j , 0 , m + 1) REP(ii , 0 , k + 1) REP(jj , 0 , k + 1)
            dp[0][j][ii][jj] = -INF;
        dp[0][0][0][0] = 0;

        REP(id , 0 , n){
            int i = id % 2 , nxt = (id + 1) % 2;

            REP(j , 0 , m + 1) REP(ii , 0 , k + 1) REP(jj , 0 , k + 1)
                dp[nxt][j][ii][jj] = -INF;

            REP(j , 0 , m + 1){
                REP(ii , 0 , k + 1){
                    REP(jj , 0 , k + 1){
                        if(dp[i][j][ii][jj] < 0) continue;  
                        // cout << id << " ";
                        // DB4(j , ii , jj , dp[i][j][ii][jj]);
                        U(dp[nxt][j + 0][     0][     0] , dp[i][j][ii][jj]);
                        U(dp[nxt][j + 1][     0][     1] , dp[i][j][ii][jj] + b[id + 1]);
                        U(dp[nxt][j + 1][     1][     0] , dp[i][j][ii][jj] + a[id + 1]);
                        U(dp[nxt][j + 2][     1][     1] , dp[i][j][ii][jj] + (a[id + 1] | b[id + 1]));
                        
                        if(ii){
                        U(dp[nxt][j + 0][ii + 1][     0] , dp[i][j][ii][jj] + a[id + 1]);
                        U(dp[nxt][j + 1][ii + 1][     1] , dp[i][j][ii][jj] + (a[id + 1] | b[id + 1]));
                        }
                        if(jj){
                        U(dp[nxt][j + 0][     0][jj + 1] , dp[i][j][ii][jj] + b[id + 1]);
                        U(dp[nxt][j + 1][     1][jj + 1] , dp[i][j][ii][jj] + (a[id + 1] | b[id + 1]));
                        }
                        if(ii && jj){
                        U(dp[nxt][j + 0][ii + 1][jj + 1] , dp[i][j][ii][jj] + (a[id + 1] | b[id + 1]));
                        }                        
                        
                    }
                }
            }
        }
        int ans = 0;
        REP(j , 0 , m + 1) REP(ii , 0 , k + 1) REP(jj , 0 , k + 1){
            // cout << n << " ";
            // DB4(j , ii , jj , dp[n % 2][j][ii][jj]);
            ans = max(ans , dp[n % 2][j][ii][jj]);
        }
        cout << ans << endl;
    }
    return 0;
}