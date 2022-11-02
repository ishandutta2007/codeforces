/*input
1 1 5
1 1
1 1
1 1
1 1
1 1
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
#define MAX 5000
#define INF 0x3f3f3f3f

struct N{
    int from , to , cap , flow;
};
struct dinic{
    int s , t , dep[MAX] , use[MAX] , res[MAX];
    vector<int> g[MAX];
    vector<N> e;
    void init(){
        REP(i , 0 , MAX) g[i].clear();
        e.clear();
    }
    int ADDE(int f , int t , int c){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0});
        return e.size() - 2;
    }
    int BFS(){
        MEM(use , 0) , MEM(dep , 0);
        queue<int> qu;
        qu.push(s) , dep[s] = use[s] = 1;
        while(qu.size()){
            int now = qu.front(); qu.pop();
            for(auto i : g[now]){
                N to = e[i];
                if(use[to.to] == 0 && to.cap > to.flow){
                    use[to.to] = 1;
                    dep[to.to] = dep[now] + 1;
                    qu.push(to.to);
                }
            }
        }
        return use[t];
    }
    int DFS(int now , int lim){
        if(lim == 0 || now == t) return lim;
        int flow = 0 , tmp;
        for(int &i = res[now] ; i < g[now].size() ; i ++){
            N to = e[g[now][i]];
            if(dep[to.to] == dep[now] + 1){
                tmp = DFS(to.to , min(lim , to.cap - to.flow));
                if(tmp > 0){
                    e[g[now][i] ^ 0].flow += tmp;
                    e[g[now][i] ^ 1].flow -= tmp;
                    flow += tmp;
                    lim -= tmp;
                    if(lim == 0) break;
                }
            }
        }
        return flow;
    }
    int FLOW(int s , int t){
        this -> s = s , this -> t = t;
        int flow = 0;
        while(BFS()){
            MEM(res , 0);
            flow += DFS(s , 0x3f3f3f3f);
        }
        return flow;
    }
}dc;
int n , m , k , o[MAX][2] , idx[MAX][2];
vector<int> sol[MAX];
vector<PII> edge;
int32_t main(){
    IOS;
    cin >> n >> m >> k;

    int pos = 0;
    int s = ++pos;
    int t = ++pos;
    REP(i , 1 , n + 1) idx[i][0] = ++pos;
    REP(i , 1 , m + 1) idx[i][1] = ++pos;

    REP(i , 1 , k + 1){
        int a , b;
        cin >> a >> b;
        o[a][0] ++;
        o[b][1] ++;
        edge.pb(dc.ADDE(idx[a][0] , idx[b][1] , 1) , i);
    }
    int sml = INF;
    REP(i , 1 , n + 1) sml = min(sml , o[i][0]);
    REP(i , 1 , m + 1) sml = min(sml , o[i][1]);


    REP(i , 1 , n + 1) dc.ADDE(s , idx[i][0] , o[i][0] - sml);
    REP(i , 1 , m + 1) dc.ADDE(idx[i][1] , t , o[i][1] - sml);

    RREP(ii , sml , 0){
        dc.FLOW(s , t);
        for(auto to : edge) if(dc.e[to.A].flow == 0) sol[ii].pb(to.B);

        REP(i , 1 , n + 1) dc.ADDE(s , idx[i][0] , 1);
        REP(i , 1 , m + 1) dc.ADDE(idx[i][1] , t , 1);
    }
    REP(i , 0 , sml + 1){
        cout << sol[i].size() << " ";
        for(auto to : sol[i]) cout << to << " " ; cout << endl;
    }
    return 0;
}