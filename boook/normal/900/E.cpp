/*input
14
?abaa?abb?b?a?
3 c
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , ok[MAX][2] , sf[MAX][2] , pr[MAX];
PII dp[MAX];
string s;

int32_t main(){
    IOS;
    cin >> n >> s >> m , s = " " + s;
    REP(i , 1 , n + 1){
        if(s[i] == '?') ok[i][0] = ok[i][1] = 1;
        else if(s[i] == 'a') ok[i][0] = i % 2 == 0 , ok[i][1] = i % 2 == 1;
        else if(s[i] == 'b') ok[i][0] = i % 2 == 1 , ok[i][1] = i % 2 == 0;
    }
    REP(i , 1 , n + 1) pr[i] = pr[i - 1] + (s[i] == '?' ? -1 : 0);
    // REP(i , 1 , n + 1) cout << s[i] ; cout << endl;
    // REP(i , 1 , n + 1) cout << pr[i] << " "; cout << endl;
    REP(i , 1 , n + 1){
        if(ok[i][0]) sf[i][0] = 1 + sf[i - 1][0];
        if(ok[i][1]) sf[i][1] = 1 + sf[i - 1][1];
    }
    // REP(i , 1 , n + 1) cout << sf[i][0] << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << sf[i][1] << " "; cout << endl;
    int now = m % 2;
    REP(i , 1 , n + 1){
        dp[i] = max(dp[i] , dp[i - 1]);
        if(sf[i][now] >= m){
            // DBGG("now = " , i);
            dp[i] = max(dp[i] , mp(dp[i - m].A + 1 , dp[i - m].B + (pr[i] - pr[i - m])));
        }
        now = 1 - now; 
    }
    cout << -dp[n].B << endl;
    return 0;
}


// 14
// ?abaa?abb?b?a?
//          aba
//     aba
//  aba
// 3