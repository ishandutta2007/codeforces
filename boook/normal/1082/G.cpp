/*input
3 3
9 7 8
1 2 1
2 3 2
1 3 3
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 5010
#define INF 100000000000000000LL

struct N{ int from , to , cap , flow; };
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
    	memset(use , 0 , sizeof use);
    	memset(dep , 0 , sizeof dep);
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
        	memset(res , 0 , sizeof res);
            flow += DFS(s , 0x3f3f3f3f);
        }
        return flow;
    }
}dc;
int n , m , x[MAX] , e[MAX][3];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	int all = 0;
	int s = n + m + 10 , t = s + 1;
	REP(i , 1 , m + 1){
		cin >> e[i][0] >> e[i][1] >> e[i][2];
		dc.ADDE(i , e[i][0] + m , INF);
		dc.ADDE(i , e[i][1] + m , INF);
		all += e[i][2];
	}
	REP(i , 1 , m + 1) dc.ADDE(s , i + 0 , e[i][2]);
	REP(i , 1 , n + 1) dc.ADDE(i + m , t , x[i]);

	cout << all - dc.FLOW(s , t) << endl;
    return 0;
}