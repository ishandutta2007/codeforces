#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
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

int n , m , k , x[MAX] , N;
int use[MAX] , scc[MAX] , sccpo = 0;
vector<int> G1[MAX] , G2[MAX] , g;
map<int , int> cc;
inline int TR(int now){ return now < n ? now + n : now - n; }
void ADD(int a , int b){
    if(a == b) return;
    G1[a].pb(b) , G2[b].pb(a);
    // DBGG(a , b);
}
void DFS1(int now){
    if(use[now]) return ;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    g.pb(now);
}
void DFS2(int now){
    if(scc[now]) return ;
    scc[now] = sccpo;
    for(auto to : G2[now]) DFS2(to);
}
int solve(){
    REP(i , 0 , n + n) DFS1(i);
    RREP(i , g.size() - 1 , 0){
        if(scc[g[i]] == 0) sccpo ++ , DFS2(g[i]);
    }
    REP(i , 0 , n)
        if(scc[i] == scc[TR(i)]) return 0;
    return 1;
}
int32_t main(){
    cin >> n >> m >> k;
    REP(i , 0 , n) cin >> x[i];
    REP(i , 0 , n) cc[x[i]] = i;
    int ok = 1;
    REP(i , 0 , n){
        int a = -1 , b = -1;
        if(cc.find(m - x[i]) != cc.end()) a = cc[m - x[i]];
        if(cc.find(k - x[i]) != cc.end()) b = cc[k - x[i]];

        if(a == -1 && b == -1) ok = 0;
        else if(a == -1){
            ADD(i , TR(i)) , ADD(b , TR(b));
        }
        else if(b == -1){
            ADD(TR(i) , i) , ADD(TR(a) , a);
        }
        else{
            ADD(i , a);
            ADD(TR(i) , TR(a));
            ADD(i , b);
            ADD(TR(i) , TR(b));
        }
    }
    if(ok) ok = solve();
    if(ok == 0) cout << "NO" << endl;
    else{
        cout << "YES" << endl; 
        REP(i , 0 , n){
            if(scc[i] > scc[i + n]) cout << 0 << " " ;
            else cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}