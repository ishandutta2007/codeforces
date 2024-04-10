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

int n , x[MAX] , dp[MAX] , sum[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    x[0] = -100000;
    REP(i , 1 , n + 1){
        dp[i] = INF;
        int a = lower_bound(x , x + n + 1 , x[i] - 89) - x;
        int b = lower_bound(x , x + n + 1 , x[i] - 1439) - x;
        dp[i] = min(dp[i - 1] + 20 , min(dp[a - 1] + 50 , dp[b - 1] + 120));
    }
    // REP(i , 1 , n + 1) cout << dp[i] << " " ; cout << endl;
    REP(i , 1 , n + 1){
        cout << dp[i] - dp[i - 1] << endl;
    }
    return 0;
}