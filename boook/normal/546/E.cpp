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
#define MAX 300
#define INF 0x3f3f3f3f

class N{
public:
    int from , to , cap , flow;
    N(int a , int b , int c , int d){
        from = a , to = b , cap = c , flow = d;
    }
};
int p[MAX][MAX];
int n , m , a[MAX] , b[MAX];
class dinic{
public:
    int s , t;
    int dep[MAX] , res[MAX] , use[MAX];
    vector<int> g[MAX];
    vector<N> e;
    void ADDE(int f , int t , int c){
        g[f].pb(e.size());
        e.pb(N(f , t , c , 0));
        g[t].pb(e.size());
        e.pb(N(t , f , 0 , 0));
    }
    int BFS(){
        MEM(use , 0) , MEM(dep , 0);
        queue<int> qu;
        dep[s] = use[s] = 1 , qu.push(s);
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
        for(int &i = res[now] ; i < g[now].size() ; i++){
            N to = e[g[now][i]];
            if(dep[to.to] == dep[now] + 1){
                int tmp = DFS(to.to , min(lim , to.cap - to.flow));
                if(tmp > 0){
                    e[g[now][i] ^ 0].flow += tmp;
                    e[g[now][i] ^ 1].flow -= tmp;
                    lim -= tmp , flow += tmp;
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
    void put(){
        for(auto to : e){
            if(to.from == s || to.to == t || to.cap == 0) continue;
            p[to.from][to.to - 100] = to.flow;
        }
    }
} dc;

int32_t main(){
    cin >> n >> m;
    int sum1 = 0 , sum2 = 0;
    REP(i , 1 , n + 1) cin >> a[i] , sum1 += a[i];
    REP(i , 1 , n + 1) cin >> b[i] , sum2 += b[i];
    int s = 0 , t = 201 , N = 100;
    REP(i , 1 , n + 1){
        dc.ADDE(s , i , a[i]);
        dc.ADDE(i + N , t , b[i]);
        dc.ADDE(i , i + N , INF);
    }
    REP(i , 1 , m + 1){
        int q , w;
        cin >> q >> w;
        dc.ADDE(q , w + N , INF);
        dc.ADDE(w , q + N , INF);
    }
    if(dc.MAXFLOW(s , t) == max(sum1 , sum2)){
        cout << "YES" << endl;
        dc.put();
        REP(i , 1 , n + 1){
            REP(j , 1 , n + 1) cout << p[i][j] << " ";
            cout << endl;
        }
    }
    else cout << "NO" << endl;
    return 0;
}