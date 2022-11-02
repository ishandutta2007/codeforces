/*input
4 1
-1000000000 -1000000000 1000000000 1000000000
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
#define int long long 
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m , x[MAX] , dp[MAX];
int judge(int lim){
    REP(i , 2 , n + 1){
        dp[i] = i - 1;
        REP(j , 1 , i){
            if(abs(x[i] - x[j]) <= lim * (i - j)){
                dp[i] = min(dp[i] , dp[j] + i - j - 1);
            }
        }
    }
    int sml = n;
    REP(i , 1 , n + 1) sml = min(sml , dp[i] + n - i);
    // REP(i , 1 , n + 1) cout << dp[i] << " " ; cout << endl;
    // DBGG(lim , sml);
    return sml <= m;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    int ans = 2e9 + 100;
    RREP(i , 30 , 0){
        int to = ans - (1 << i);
        if(to >= 0 && judge(to)) ans = to;
    }
    cout << ans << endl;
    return 0;
}