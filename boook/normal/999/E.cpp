/*input
5 4 5
1 2
2 3
3 4
4 1
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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , m , k , e[MAX][2] , can[MAX];
vector<int> v[MAX] , G1[MAX] , G2[MAX] , p;
int use[MAX] , scc[MAX] , sccpo;
void DFS(int now){
    can[now] = 1;
    for(auto to : v[now]) if(can[to] == 0) DFS(to);
}
void DFS1(int now){
    if(use[now]) return ;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    p.pb(now);
}
void DFS2(int now){
    if(scc[now]) return ;
    scc[now] = sccpo;
    for(auto to : G2[now]) DFS2(to);
}
int out[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        e[i][0] = a , e[i][1] = b;
        v[a].pb(b);
    }
    DFS(k);
    int ans = -1;
    REP(i , 1 , m + 1){
        int a = e[i][0] , b = e[i][1];
        if(can[a] == 0 && can[b] == 0){
            ans = a;
            G1[a].pb(b);
            G2[b].pb(a);
        }
    }
    REP(i , 1 , n + 1) if(can[i] == 0) DFS1(i);;// , DBGG("add = " , i);
    RREP(i , p.size() - 1 , 0){
        if(scc[p[i]] == 0){
            sccpo ++;
            DFS2(p[i]);
        }
    }
    REP(i , 1 , sccpo + 1) out[i] = 1;
    REP(i , 1 , m + 1){
        int a = e[i][0] , b = e[i][1];
        if(can[a] == 0 && can[b] == 0){
            if(scc[a] != scc[b]) out[scc[b]] = 0;
        }
    }
    int cnt = 0;
    REP(i , 1 , sccpo + 1) cnt += out[i];
    cout << cnt << endl;
    return 0;
}