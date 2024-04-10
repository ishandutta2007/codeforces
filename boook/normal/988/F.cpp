/*input
10 1 1
0 9
1 5
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m , k , rain[MAX] , u[MAX] , dp[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , m + 1){
        int ql , qr;
        cin >> ql >> qr;
        REP(j , ql , qr) rain[j] = 1;
    }
    REP(i , 0 , n + 1) u[i] = INF;
    REP(i , 1 , k + 1){
        int idx , val;
        cin >> idx >> val;
        u[idx] = min(u[idx] , val);
    }
    REP(i , 1 , n + 1) dp[i] = INF;
    dp[0] = 0;
    REP(i , 0 , n){
        if(rain[i] == 0) dp[i + 1] = min(dp[i + 1] , dp[i]);
        REP(j , i + 1 , n + 1) dp[j] = min(dp[j] , dp[i] + (j - i) * u[i]);
    }
    int ans = dp[n];
    cout << (ans >= INF ? -1 : ans) << endl;
    return 0;
}