/*input
60
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
#define MAX 30000
#define INF 0x3f3f3f3f

int n , dp[MAX] , T[MAX];

int32_t main(){
    IOS;
    cin >> n;
    if(n > 50){
        int tmp = 2203;
        cout << tmp + (n - 50) * 49 << endl;
        return 0;
    }
    else {
        int all = n * (1 + 5 + 10 + 50);
        dp[0] = 1;
        // REP(i , 1 , all + 1) cout << dp[i] << " "; cout << endl;
        REP(times , 1 , n + 1){
            REP(i , 0 , all + 1) T[i] = 0;
            for(auto to : {1 , 5 , 10 , 50}){
                RREP(j , all , to) if(dp[j - to]) T[j] = 1;
            }
            REP(i , 0 , all + 1) dp[i] = T[i];
        }
        // REP(i , 1 , all + 1) if(dp[i]) DBGG(" = " , i);
        // REP(i , 1 , all + 1) cout << dp[i] << " "; cout << endl;
        int ans = 0;
        REP(i , 1 , all + 1) ans += dp[i];
        cout << ans << endl;
    }
    return 0;
}