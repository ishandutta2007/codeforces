#include <bits/stdc++.h>
#define int long long

#define TASKNAME ""

using namespace std;

const int INF = 1e18 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
struct Edge{int f; int c; int to;};
vector<Edge> edges;
int number;
vector<int> d, where;
vector<vector<int> > data;
void bfs(){
    fill(d.begin(), d.end(), INF);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()){
        int V = q.front();
        q.pop();
        for (int i=0; i < data[V].size(); i++){
            int ind = data[V][i];
            int to = edges[ind].to;
            if (edges[ind].f == edges[ind].c) continue;
            if (d[to] != INF) continue;
            d[to] = d[V] + 1;
            q.push(to);
        }
    }
}
int dfs(int vertex, int F){
    //cout << vertex << " " << F << endl;
    if (vertex == number-1 || !F) return F;
    while (where[vertex] < data[vertex].size()){
        int u = where[vertex];
        int ind = data[vertex][u];
        int to = edges[ind].to, c = edges[ind].c, f = edges[ind].f;
        //cout << to << " " << c << " " << f << endl;
        if (d[vertex]+1 != d[to] || c==f){
            where[vertex]++;
            continue;
        }
        int there = dfs(to, min(F, c-f));
        if (!there){
            where[vertex]++;
            continue;
        }
        edges[ind].f += there;
        edges[ind^1].f -= there;
        return there;
    }
    return 0;
}
void dinic(){
    while (true){
        bfs();
        if (d[number-1] == INF) return;
        for (int i=0;i<number;i++) where[i] = 0;
        while (true){
            int flow = dfs(0, INF);
            if (!flow) break;
        }
    }
}
void construct(int u, int v, int c){
    edges.push_back({0, c, v});
    edges.push_back({0, 0, u});
    data[u].push_back(edges.size()-2);
    data[v].push_back(edges.size()-1);
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > nei(n);
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        nei[a].push_back(i);
        nei[b].push_back(i);
    }
    number = n+m+2;
    d.clear(), where.clear(), data.clear();
    edges.clear();
    d.resize(number, 0), where.resize(number, 0), data.resize(number, {});
    for (int i=0; i < n; i++){
        int need = max((int) 0, nei[i].size() - k);
        construct(0, i+1, 2*need);
        for (int j=0; j < nei[i].size(); j++){
            construct(i+1, n+1+nei[i][j], 1);
        }
    }
    for (int i=0; i < m; i++) construct(i+n+1, number-1, 1);
    dinic();
    int ind=0;
    for (int i=0; i < n; i++){
        //cout << edges[ind].f << " " << edges[ind].c << endl;
        if (edges[ind].f != edges[ind].c){
            for (int j=0;j<m;j++) cout << 0 << " ";
            cout << endl;
            return;
        }
        ind +=2;
        for (int j=0; j < nei[i].size(); j++){
            ind+=2;
        }
    }
    vector<int> res(m);
    fill(res.begin(), res.end(), -1);
    int ii = 0, kek=0;
    for (int i=0; i < n; i++){
        ii+=2;
        for (int j=0; j < nei[i].size(); j++){
            if (edges[ii].f){
                //cout << i << "!!" << j << endl;
                int naz = edges[ii].to - n - 1;
                res[naz] = kek/2;
                kek++;
            }
            ii+=2;
        }
    }
    for (int i=0;i<m;i++) if (res[i]==-1){
        res[i] = kek/2;
        kek +=2;
    }
    for (int i=0;i<m;i++) cout << res[i]+1 << " ";
    cout << endl;
}
signed main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int t;
    cin >> t;
    for (int i=0; i < t; i++) solve();
}