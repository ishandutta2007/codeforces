/*input
4 6
1 2
1 4
2 3
2 4
3 2
3 4
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

int n , m;
int use[MAX] , scc[MAX] , siz[MAX] , sccpo = 0 , ss[MAX];
vector<int> G1[MAX] , G2[MAX] , p;
struct djs{
    int x[MAX] , siz[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i , siz[i] = 1; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        x[a] = b;
        siz[b] += siz[a];
    }
    int operator[](int now){ return Find(x[now]); }
} ds;
void DFS1(int now){
    if(use[now]) return;
    use[now] = 1;
    for(auto to : G1[now]) DFS1(to);
    p.pb(now);
}
void DFS2(int now){
    if(scc[now]) return;
    scc[now] = sccpo;
    siz[sccpo] ++;
    for(auto to : G2[now]) DFS2(to);
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        G1[a].pb(b);
        G2[b].pb(a);
    }
    REP(i , 1 , n + 1) DFS1(i);
    RREP(i , p.size() - 1 , 0){
        if(scc[p[i]] == 0){
            sccpo ++;
            DFS2(p[i]);
        }
    }
    ds.init();
    REP(i , 1 , n + 1) for(auto to : G1[i]){
        if(ds[scc[i]] != ds[scc[to]]){
            ds.Union(scc[i] , scc[to]);
        }
    }
    REP(i , 1 , n + 1){
        ss[ds[scc[i]]] ++;
    }
    int ans = 0;
    REP(i , 1 , sccpo + 1){
        if(ds[i] == i){
            if(ds.siz[i] == ss[i]) ans += ss[i] - 1;
            else ans += ss[i];
        }
    }
    cout << ans << endl;
    return 0;
}