/*input
4 9
PP.-PPPS-S.S
PSP-PPSP-.S.
.S.-S..P-SS.
P.S-P.PP-PSP
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
#define int int_fast64_t
#define MAX 4040
#define INF 0x3f3f3f3f

string s;
int n , m , dp[MAX][MAX] , ok[10] , ans = 0 , pos , pa[MAX][MAX];
string dd[MAX][5];
void solve(string now , int id , int sum){
    if(id == now.size()){
        int val = 0;
        REP(i , 0 , now.size()){
            if(now[i] == 'S'){
                if(i != 0 & now[i - 1] == 'x') val ++;
                if(i + 1 != now.size() && now[i + 1] == 'x') val ++;
                
            }
        }
        ok[sum] = min(ok[sum] , val);
        if(ok[sum] == val) dd[pos][sum] = now;
    }
    else {
        if(now[id] == 'P' || now[id] == 'S') solve(now , id + 1 , sum);
        else {
            solve(now , id + 1 , sum);
            now[id] = 'x';
            solve(now , id + 1 , sum + 1);
        }
    }
}
void counts(string now){
    REP(i , 0 , now.size()){
        if(now[i] == 'S'){
            if(i != 0 && now[i - 1] != '.') ans ++;
            if(i + 1 != now.size() && now[i + 1] != '.') ans ++;
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , MAX) REP(j , 0 , MAX) dp[i][j] = INF;
    dp[0][0] = 0;
    REP(times , 1 , n + 1){
        cin >> s;
        string a = s.substr(0 , 3);
        string b = s.substr(4 , 4);
        string c = s.substr(9 , 3);
        // DB4("s = " , a , b , c);
        pos ++;
        REP(i , 0 , 5) ok[i] = INF; solve(a , 0 , 0) , counts(a);
        // REP(i , 0 , 5) cout << ok[i] << " " ; cout << endl;
        RREP(i , MAX - 1 , 0) REP(j , 0 , 5) 
            if(i - j >= 0 && dp[pos - 1][i - j] + ok[j] < dp[pos][i]) 
                dp[pos][i] = dp[pos - 1][i - j] + ok[j] , pa[pos][i] = j;

        // REP(i , 0 , 5) cout << dp[pos][i] << " " ; cout << endl;

        pos ++;
        REP(i , 0 , 5) ok[i] = INF; solve(b , 0 , 0) , counts(b);
        // REP(i , 0 , 5) cout << ok[i] << " " ; cout << endl;
        RREP(i , MAX - 1 , 0) REP(j , 0 , 5) 
            if(i - j >= 0 && dp[pos - 1][i - j] + ok[j] < dp[pos][i]) 
                dp[pos][i] = dp[pos - 1][i - j] + ok[j] , pa[pos][i] = j;
        // REP(i , 0 , 5) cout << dp[pos][i] << " " ; cout << endl;
        
        pos ++;
        REP(i , 0 , 5) ok[i] = INF; solve(c , 0 , 0) , counts(c);
        // REP(i , 0 , 5) cout << ok[i] << " " ; cout << endl;
        RREP(i , MAX - 1 , 0) REP(j , 0 , 5) 
            if(i - j >= 0 && dp[pos - 1][i - j] + ok[j] < dp[pos][i]) 
                dp[pos][i] = dp[pos - 1][i - j] + ok[j] , pa[pos][i] = j;
        // REP(i , 0 , 5) cout << dp[pos][i] << " " ; cout << endl;

    }
    vector<string> v;
    int now = m , cnt = 0;
    RREP(i , pos , 1){
        int tmp = pa[i][now];
        // DBGG("tmp = " , tmp);
        v.pb(dd[i][tmp]);
        now -= tmp;
    }
    // DBGG("ans = " , ans);
    cout << dp[pos][m] + ans << endl;
    RREP(i , v.size() - 1 , 0){
        cnt ++;
        cout << v[i];
        if(cnt % 3 == 0) cout << endl;
        else cout << "-";
    }
    return 0;
}