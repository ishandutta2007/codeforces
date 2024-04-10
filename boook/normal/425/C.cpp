/*input
3 4 3006 1000
1 2 3
1 2 4 3
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , s , e;
int a[MAX] , b[MAX] , dp[MAX][310];
vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> s >> e;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , m + 1) cin >> b[i];
    REP(i , 1 , m + 1) v[b[i]].pb(i);
    
    MEM(dp , INF);
    REP(i , 0 , n + 1) dp[i][0] = 0;
    int ans = 0;
    REP(i , 1 , n + 1){
        int po = 0;
        REP(j , 1 , 300){
            dp[i][j] = dp[i - 1][j];
            if(dp[i - 1][j - 1] != INF){
                // cout << "here" << endl;
                int tmp = dp[i - 1][j - 1];
                while(po < v[a[i]].size() && v[a[i]][po] <= tmp) po ++;
                if(po < v[a[i]].size()) dp[i][j] = min(dp[i][j] , v[a[i]][po]); 
            }
            // DB4("dp = " , i , j , dp[i][j]);
            if(dp[i][j] != INF){
                int cost = i + dp[i][j] + j * e;
                if(cost <= s) ans = max(ans , j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}