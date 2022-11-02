/*input
3
3 2 1
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX] , ans[MAX][2];
void solve(int op){
    int ok = 1;
    REP(i , 1 , n + 1) if(x[i] != i){
        ok = 0;
        break;
    }
    if(ok){
        cout << op << endl;
        RREP(i , op , 1) cout << ans[i][0] << " " << ans[i][1] << endl;
        exit(0);
    }
    else {
        if(op == 3) return;
        vector<int> sol;
        REP(i , 1 , n + 1) if(x[i] != i){
            if(abs(x[i] - x[i - 1]) > 1 || abs(x[i + 1] - x[i]) > 1) sol.pb(i);
        }

        REP(i , 0 , sol.size()) REP(j , i + 1 , sol.size()){
            ans[op + 1][0] = sol[i] , ans[op + 1][1] = sol[j];
            reverse(x + sol[i] , x + sol[j] + 1);
            solve(op + 1);
            reverse(x + sol[i] , x + sol[j] + 1);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n;
    x[0] = x[n + 1] = -1;
    REP(i , 1 , n + 1) cin >> x[i];
    solve(0);
    return 0;
}