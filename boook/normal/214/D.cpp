/*input
1
0 0 0 0 0 0 0 0 0 0
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
#define MAX 1010
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , x[MAX] , gi[MAX] , ni[MAX] , dp[MAX][100];
void solveinit(){
    gi[0] = ni[0] = ni[1] = 1;
    REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
}
int C(int a , int b){
    if(a < b || a < 0) return 0;
    return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
int32_t main(){
    solveinit();
    cin >> n;
    REP(i , 0 , 10) cin >> x[i];
    dp[0][10] = 1;
    RREP(i , 9 , 1){
        REP(j , 0 , n + 1){
            REP(k , x[i] , j + 1){
                dp[j][i] = (dp[j][i] + dp[j - k][i + 1] * C(j , k)) % mod;
            }
        }
    }
    REP(j , 0 , n + 1){
        REP(k , x[0] , j){
            dp[j][0] = (dp[j][0] + dp[j - k][1] * C(j - 1 , k)) % mod;
        }
    }
    int ok = 0;
    REP(i , 0 , n + 1) ok = (ok + dp[i][0]) % mod;
    cout << ok << endl;
    return 0;
}