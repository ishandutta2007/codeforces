#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

char str[220][220];

class Edge{
public:
    Int from, to, rev;
    Int cost, lim;
    Edge(Int from, Int to, Int cost, Int lim = -1, Int rev = -1):
        from(from),to(to),cost(cost),lim(lim),rev(rev){}
};


class Graph{
public:
    Int n;
    Int m;
    vector<vector<Edge>> edge;
    Graph(Int n = 0):n(n),m(0){
        edge = vector<vector<Edge>>(n);
    }
    void add_edge(Int from, Int to, Int cost = 1, Int lim = -1)
        {
            if(lim == -1){
                edge[from].push_back(Edge(from, to, cost));
                return;
            }
            edge[from].push_back(Edge(from, to, cost, lim, edge[to].size()));
            edge[to].push_back(Edge(to, from, -cost, 0, edge[from].size() - 1));
        }
};



class Dinic{
public:
    Graph *g;
    vector<int> iter, level, come;

    Dinic(){};
    void bfs(int s){
        queue<int> q;
        fill(level.begin(), level.end(), INF);
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int x = q.front();q.pop();
            for(auto e:g->edge[x]){
                if(level[e.to] != INF)continue;
                if(e.lim <= 0)continue;
                level[e.to] = level[x] + 1;
                q.push(e.to);
            }
        }
    }

    Int dfs(int s, int t, Int f){
        if(s == t)return f;
        if(come[s])return 0;
        come[s] = true;
        for(int &i = iter[s];i < g->edge[s].size();i++){
            Edge &e = g->edge[s][i];
            if(e.lim <= 0)continue;
            Int tmp = dfs(e.to, t, min(f, e.lim));
            if(tmp == 0)continue;
            e.lim -= tmp;
            g->edge[e.to][e.rev].lim += tmp;
            return tmp;
        }
        return 0;
    }
    Int max_flow(Graph &_g, int s, int t){
        g = &_g;
        iter = vector<int>(g->n);
        level = vector<int>(g->n);
        come = vector<int>(g->n, 0);
        Int res = 0;
        while(true){
            bfs(s);
            if(level[t] == INF)break;
            fill(iter.begin(), iter.end(), 0);
            while(true){
                fill(come.begin(), come.end(), false);
                Int tmp = dfs(s, t, INF);
                if(tmp == 0)break;
                else res += tmp;
            }
        }
        return res;   
    }  
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    Graph g(n * m * 3 + 2);
    for(int i = 0;i < n;i++){
        scanf(" %s", str[i]);
    }
    int S = n * m * 3;
    int T = S + 1;
    int p = n * m;
    int edge = 0;
    int total = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(str[i][j] == '.')continue;
            total++;
            int ind = i * m + j;
            if(i > 0 && str[i-1][j] == '#'){
                edge++;
                int ind2 = (i-1)*m+j;
                int w = p++;
                g.add_edge(S, w, 1, 1);
                g.add_edge(w, ind, 1, 1);
                g.add_edge(w, ind2, 1, 1);
            }
            if(j > 0 && str[i][j-1] == '#'){
                edge++;
                int ind2 = i*m+j-1;
                int w = p++;
                g.add_edge(w, T, 1, 1);
                g.add_edge(ind, w, 1, 1);
                g.add_edge(ind2, w, 1, 1);
            }
        }
    }
    Dinic d;
    int min_cut = d.max_flow(g, S, T);
    cout << total - (edge - min_cut) << endl;
    return 0;
}