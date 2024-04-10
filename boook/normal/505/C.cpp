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
#define MAX 30900
#define INF 0x3f3f3f3f

int n , m;
int dp[MAX][600] , val[MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1){
        int tmp; cin >> tmp;
        val[tmp] ++;
    }
    MEM(dp , -1);
    dp[0][300] = 0;
    int ans = 0;
    REP(i , 0 , MAX){
        REP(j , 1 , 590){
            if(dp[i][j] < 0) continue;
            int step = j - 300 + m;
            if(step <= 0) continue;
            REP(k , -1 , 2){
                if(i == 0 && k != 0) continue;
                if(step + k > 0 && i + step + k < MAX && j + k >= 0 && j + k < 600){
                    dp[i + step + k][j + k] = max(dp[i + step + k][j + k] , dp[i][j] + val[i + step + k]);
                    ans = max(ans , dp[i + step + k][j + k]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}