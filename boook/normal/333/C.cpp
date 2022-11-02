/*input
0 3
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 10000
#define INF 0x3f3f3f3f

vector<int> v[MAX + 100];
void solveinit(int now , int val){
    vector<int> sol[4][4];
    RREP(i , 3 , 0){
        sol[i][i].pb(now % 10) , now /= 10;
    }
    sol[0][1].pb(sol[0][0][0] * 10 + sol[1][1][0]);
    sol[1][2].pb(sol[1][1][0] * 10 + sol[2][2][0]);
    sol[2][3].pb(sol[2][2][0] * 10 + sol[3][3][0]);

    sol[0][2].pb(sol[0][1][0] * 10 + sol[2][2][0]);
    sol[1][3].pb(sol[1][2][0] * 10 + sol[3][3][0]);
    sol[0][3].pb(sol[0][2][0] * 10 + sol[3][3][0]);

    REP(i , 1 , 4){
        REP(j , 0 , 4 - i){
            int l = j , r = j + i;
            REP(k , l , r){
                for(auto a : sol[l][k + 0]){
                    for(auto b : sol[k + 1][r]){
                        sol[l][r].pb(a + b);
                        sol[l][r].pb(a - b);
                        sol[l][r].pb(a * b);
                    }
                }
            }
        }
    }
    sort(ALL(sol[0][3]));
    sol[0][3].resize(unique(ALL(sol[0][3])) - sol[0][3].begin());
    for(auto to : sol[0][3]) if(to >= 0) v[to].pb(val);
    //     cout << val << "get = " ;
    // for(auto to : sol[0][3]) if(to >= 0) cout << to << " ";
    //     cout << endl;
}
int n , m;
set<int> ans;
int32_t main(){
    REP(i , 0 , MAX) solveinit(i , i);
    cin >> n >> m;
    REP(i , 0 , MAX){
        // a + i == n;
        // a - i == n;
        for(auto tmp : {n - i , n + i}){
            if(tmp >= 0 && tmp < MAX){
                for(auto to : v[tmp]){
                    if(ans.size() == m) break;
                    ans.insert(i * MAX + to);
                }
            }
        }
        if(ans.size() == m) break;
    }
    if(ans.size() != m) cout << "WA" << endl;
    else {
        for(auto to : ans) printf("%08d\n", to);
    }
    return 0;
}