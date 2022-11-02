/*input
1 2 7
6 7
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
#define MAX 110
#define INF 0x3f3f3f3f

int n , m , k , x[MAX][MAX];
vector<int> sol;
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> x[i][j];
    REP(i , 1 , n + 1) REP(j , 1 , m + 1){
        if(abs(x[i][j] - x[1][1]) % k != 0){
            return cout << -1 << endl , 0;
        }
        sol.pb(x[i][j]);
    }
    sort(ALL(sol));
    int ans = 0 , nn = (sol.size() + 1) / 2 - 1;
    REP(i , 0 , sol.size()){
        int tmp = abs(sol[i] - sol[nn]);
        ans += tmp / k;
    }
    cout << ans << endl;
    return 0;
}