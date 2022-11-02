/*input
6
0 1 1 0 4 4
7
1 1
1 2
2 1
2 2
4 1
5 1
6 1
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , dep[MAX];
vector<int> v[MAX];
vector<PII> sol;
int sp[MAX][20] , in[MAX] , out[MAX] , po = 1;
void DFS(int now , int fa , int deep){
    sol.pb(mp(deep , po));
    in[now] = po ++;
    dep[now] = deep;
    sp[now][0] = fa;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS(to , now , deep + 1);
    }
    out[now] = po;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) v[x[i]].pb(i);

    DFS(0 , 0 , 1);
    REP(j , 1 , 20) REP(i , 1 , n + 1){
        sp[i][j] = sp[sp[i][j - 1]][j - 1];
    }
    sort(ALL(sol));

    // for(auto to : sol) cout << to.A << " "; cout << endl;
    // for(auto to : sol) cout << to.B << " "; cout << endl;

    cin >> m;
    REP(times , 1 , m + 1){
        int dot , dis;
        cin >> dot >> dis;
        int deep = dep[dot];
        RREP(i , 19 , 0){
            if(dis - (1 << i) >= 0){
                dot = sp[dot][i];
                dis -= (1 << i);
            }
        }
        if(dot == 0) cout << 0 << " ";
        else {
            int l = in[dot] , r = out[dot];
            cout << max(0 , lower_bound(ALL(sol) , mp(deep , r))
                  - lower_bound(ALL(sol) , mp(deep , l)) - 1) << " ";
        }
    }
    cout << endl;
    return 0;
}