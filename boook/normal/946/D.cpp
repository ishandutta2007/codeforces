/*input
2 5 0
01001
10110
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
#define MAX 550
#define INF 0x3f3f3f3f

int n , m , k , dp[MAX] , x[MAX] , v[MAX] , sum = 0;
string s;
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , k + 1) dp[i] = 0;
    REP(times , 0 , n){
        cin >> s;
        REP(i , 0 , m + 0) x[i + 1] = s[i] == '1';
        REP(i , 1 , m + 1) x[i] += x[i - 1];

        if(x[m] == 0) continue;

        REP(i , 0 , k + 1) v[i] = INF;
        v[x[m]] = 0;

        REP(i , 1 , m + 1) REP(j , i , m + 1){
            int las = x[m] - (x[j] - x[i - 1]);
            // DB4(i , j , las , "");
            v[las] = min(v[las] , j - i + 1);
        }
        // cout << "---" << endl;

        RREP(i , k , 0){
            int tmp = INF;
            REP(j , 0 , i + 1) tmp = min(tmp , dp[i - j] + v[j]);
            dp[i] = tmp;
        }
        // REP(i , 0 , k + 1) cout << v[i] << " " ;cout << endl;
        // REP(i , 0 , k + 1) cout << dp[i] << " " ;cout << endl;
    }
    cout << dp[k] << endl;
    return 0;
}