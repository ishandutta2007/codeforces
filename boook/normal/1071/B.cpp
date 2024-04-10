/*input
7 0
ypnxnnp
pnxonpm
nxanpou
xnnpmud
nhtdudu
npmuduh
pmutsnz
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , k , can[MAX][MAX];
string s[MAX];
int DP(int i , int j){
    if(can[i][j] != -2) return can[i][j];
    if(i == 0 && j == 0){
        can[i][j] = s[i][j] != 'a';
    }
    else {
        can[i][j] = INF;
        if(i != 0 && DP(i - 1 , j) < can[i][j])
            can[i][j] = DP(i - 1 , j) + (s[i][j] != 'a');
        if(j != 0 && DP(i , j - 1) < can[i][j])
            can[i][j] = DP(i , j - 1) + (s[i][j] != 'a');
    }
    return can[i][j];
}
int u[MAX][MAX];
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 0 , n) cin >> s[i];
    
    REP(i , 0 , n) REP(j , 0 , n) can[i][j] = -2;
    REP(i , 0 , n) REP(j , 0 , n) DP(i , j);

    int big = 0;
    REP(i , 0 , n) REP(j , 0 , n) if(can[i][j] <= k) big = max(big , i + j + 1);

    string ans;
    REP(i , 0 , big) ans += "a";

    vector<PII> sol;
    REP(i , 0 , n) REP(j , 0 , n) if(can[i][j] <= k && big == i + j + 1)
        sol.pb(mp(i , j)) , u[i][j] = 1;

    if(ans.size() == 0) ans += s[0][0] , sol.pb(0 , 0);

    while(ans.size() != n + n - 1){
        char sml = 'z';
        vector<PII> nxt;
        for(auto to : sol){
            if(to.A + 1 < n) sml = min(sml , s[to.A + 1][to.B]);
            if(to.B + 1 < n) sml = min(sml , s[to.A][to.B + 1]);
        }
        for(auto to : sol){
            if(to.A + 1 < n && s[to.A + 1][to.B] == sml && u[to.A + 1][to.B] == 0) 
                nxt.pb(to.A + 1 , to.B) , u[to.A + 1][to.B] = 1;
            if(to.B + 1 < n && s[to.A][to.B + 1] == sml && u[to.A][to.B + 1] == 0)
                nxt.pb(to.A , to.B + 1) , u[to.A][to.B + 1] = 1;
        }
        swap(sol , nxt);
        ans += sml;
    }
    cout << ans << endl;
    return 0;
}