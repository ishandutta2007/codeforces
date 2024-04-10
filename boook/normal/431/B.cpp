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
#define MAX 10
#define INF 0x3f3f3f3f

int v[MAX][MAX];
int ans = 0;
vector<int> sol;
void check(){
    int tmp = 0;
    int a = sol[0] , b = sol[1] , c = sol[2] , d = sol[3] , e = sol[4];
    tmp += v[a][b] + v[b][a] + v[c][d] + v[d][c];
    tmp += v[b][c] + v[c][b] + v[d][e] + v[e][d];
    tmp += v[c][d] + v[d][c];
    tmp += v[d][e] + v[e][d];
    ans = max(ans , tmp);
}
int32_t main(){
    REP(i , 1 , 5 + 1) REP(j , 1 , 5 + 1) cin >> v[i][j];
    REP(i , 1 , 5 + 1) sol.pb(i);
    check();
    while(next_permutation(ALL(sol))){
        check();
        // for(auto to : sol) cout << to << " " ; cout << endl;
    }
    cout << ans << endl;
    return 0;
}