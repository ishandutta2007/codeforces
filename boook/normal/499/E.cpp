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
#define MAXN 40000
#define MAX 200
#define INF 0x3f3f3f3f

int no[MAXN] , p[MAXN] , po;
void solveinit(){
    REP(i , 2 , MAXN){
        if(no[i] == 0) p[po ++] = i;
        REP(j , 0 , po){
            if(p[j] * i >= MAXN) continue;
            no[p[j] * i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
struct N{
    int from , to , cap , flow;
};
struct dinic{
    int s , t;
    int dep[MAX] , res[MAX] , use[MAX];
    vector<int> g[MAX];
    vector<N> e;
    void init(){
        MEM(dep , 0) , MEM(res , 0) , MEM(use , 0);
        REP(i , 0 , MAX) g[i].clear();
        e.clear();
    }
    void ADDE(int f , int t , int c){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0});
    }
    int BFS(){
        MEM(use , 0) , MEM(dep , 0);
        queue<int> qu;
        dep[s] = use[s] = 1; qu.push(s);
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
        if(now == t || lim == 0) return lim;
        int flow = 0;
        for(int &i = res[now] ; i < g[now].size() ; i ++){
            N to = e[g[now][i]];
            if(dep[to.to] == dep[now] + 1){
                int tmp = DFS(to.to , min(lim , to.cap - to.flow));
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
    int MAXFLOW(int s , int t){
        this -> s = s , this -> t = t;
        int flow = 0;
        while(BFS()){
            MEM(res , 0);
            flow += DFS(s , INF);
        }
        return flow;
    }
}dc;
int n , m , x[MAX] , a[MAX][2];
int32_t main(){
    solveinit();
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , m + 1) cin >> a[i][0] >> a[i][1];
    REP(i , 1 , m + 1) if(a[i][0] % 2 == 0) swap(a[i][0] , a[i][1]);

    int s = 0 , t = n + 1 , ans = 0;
    REP(i , 0 , po){
        int val = p[i];
        REP(i , 1 , n + 1){
            int cnt = 0;
            while(x[i] % val == 0) x[i] /= val , cnt ++;
            if(i % 2 == 0) dc.ADDE(i , t , cnt);
            if(i % 2 == 1) dc.ADDE(s , i , cnt);
        }
        REP(i , 1 , m + 1){
            dc.ADDE(a[i][0] , a[i][1] , INF);
        }
        ans += dc.MAXFLOW(s , t);
        dc.init();
    }
    REP(i , 1 , n + 1){
        if(i % 2 == 0) dc.ADDE(i , t , 1);
        if(i % 2 == 1) dc.ADDE(s , i , 1);
    }
    REP(i , 1 , m + 1){
        int q = a[i][0] , w = a[i][1];
        if(x[q] == 1 || x[w] == 1) continue;
        if(x[q] == x[w]) dc.ADDE(q , w , 1);
    }
    ans += dc.MAXFLOW(s , t);
    cout << ans << endl;
    return 0;
}