/*input
6 7
1 2
2 3
1 3
4 5
4 6
5 6
2 4
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , ans[MAX][2] , use[MAX] , low[MAX] , dep[MAX];
vector<PII> v[MAX];
void DFS(int now , int fa , int deep){
    use[now] = 1;
    low[now] = deep;
    dep[now] = deep;
    for(auto i : v[now]){
        int to = i.A , id = i.B;
        if(to == fa) continue;
        if(use[to] == 0 || dep[to] < dep[now]) ans[id][0] = now , ans[id][1] = to;        
        if(use[to]) low[now] = min(low[now] , dep[to]);
        else {
            DFS(to , now , deep + 1);
            if(low[to] > dep[now]){
                cout << 0 << endl;
                exit(0);
            }
            low[now] = min(low[now] , low[to]);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , m){
        int a , b;
        cin >> a >> b;
        v[a].pb(mp(b , i));
        v[b].pb(mp(a , i));
    }
    DFS(1 , 0 , 0);
    REP(i , 0 , m) cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}