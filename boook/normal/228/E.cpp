/*input
3 3
1 2 0
2 3 0
3 1 0
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
#define MAX 10000
#define INF 0x3f3f3f3f

int n , m;
vector<int> G1[MAX] , G2[MAX] , p;
int use[MAX] , scc[MAX] , sccpo = 0;
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
void ADDE(int a , int b){ G1[a].pb(b) , G2[b].pb(a); }
int TR(int now){ return now <= n ? now + n : now - n; }
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , m + 1){
        int a , b , c;
        cin >> a >> b >> c;
        if(c == 0){
            ADDE(a , TR(b));
            ADDE(TR(a) , b);
            ADDE(b , TR(a));
            ADDE(TR(b) , a);
        }
        else {
            ADDE(a , b);
            ADDE(b , a);
            ADDE(TR(a) , TR(b));
            ADDE(TR(b) , TR(a));
        }
    }
    REP(i , 1 , n + n + 1) DFS1(i);
    RREP(i , p.size() - 1 , 0){
        if(scc[i] == 0){
            sccpo ++;
            DFS2(i);
        }
    }
    REP(i , 1 , n + 1) if(scc[i] == scc[i + n]){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> sol;
    REP(i , 1 , n + 1){
        if(scc[i] > scc[i + n]) sol.pb(i);
    }
    cout << sol.size() << endl;
    for(auto to : sol) cout << to << " " ; cout << endl;
    return 0;
}