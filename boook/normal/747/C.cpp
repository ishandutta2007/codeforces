/*input
1 10
4 1 1
9 1 1
10 1 1
12 1 1
13 1 1
15 1 1
16 1 1
18 1 1
19 1 1
20 1 1
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
#define MAX 1004000
#define INF 0x3f3f3f3f

vector<int> v[MAX];
int n , m , a[MAX][3] , use[MAX];
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , m + 1) REP(j , 0 , 3) cin >> a[i][j];
    REP(i , 1 , m + 1) v[a[i][0] + a[i][2]].pb(i);
    int po = 1;
    REP(t , 0 , MAX){
        if(v[t].size()){
            for(auto to : v[t]){
                REP(i , 1 , n + 1) if(use[i] == to) use[i] = 0;
            }
        }
        if(po <= m && a[po][0] == t){
            vector<int> ok;
            REP(i , 1 , n + 1){
                if(use[i] == 0) ok.pb(i);
            }
            if(ok.size() < a[po][1]) cout << -1 << endl;
            else {
                int res = 0;
                REP(i , 0 , a[po][1]){
                    res += ok[i];
                    use[ok[i]] = po;
                }
                cout << res << endl;
            }
            po ++;
            // REP(i , 1 , n + 1) cout << use[i] << " " ; cout << endl;
        }
    }
    return 0;
}