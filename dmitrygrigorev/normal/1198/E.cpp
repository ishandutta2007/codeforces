#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
struct Polygon{int l1; int r1; int l2; int r2;};
vector<Polygon> p;
const int INF = 1e9+7, FLOW = 1e15;
int F(vector<int> &x, int val){
	for (int i=0; i < x.size(); i++) if (x[i] == val) return i;
}
int A, B;
bool used[150][150];
struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 215; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }

    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = (1 << 30); minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x, y;
    x.push_back(0);
    x.push_back(n);
    y.push_back(0);
    y.push_back(n);
    for (int i=0; i < m; i++){
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;
    	a--, b--, c--, d--;
    	p.push_back({a, b, c+1, d+1});
    	x.push_back(a);
    	x.push_back(c+1);
    	y.push_back(b);
    	y.push_back(d+1);
    }
    sort(x.begin(), x.end());
    auto last = std::unique(x.begin(), x.end());
    x.erase(last, x.end()); 
    sort(y.begin(), y.end());
    last = std::unique(y.begin(), y.end());
    y.erase(last, y.end()); 
    A = x.size()-1, B = y.size()-1;
    vector<int> szx, szy;
    for (int i=0; i < A; i++) for (int j=0; j < B; j++) used[i][j] = false;
    for (int i=0; i < A; i++){
    	szx.push_back(x[i+1] - x[i]);
    	//cout << x[i] << " " << x[i+1] << endl;
    }
    //cout << endl;
    for (int i=0; i < B; i++){
    	szy.push_back(y[i+1] - y[i]);
    	//cout << y[i] << " " << y[i+1] << endl;
    }
    for (int i=0; i < m; i++){
    	p[i].l1 = F(x, p[i].l1);
    	p[i].l2 = F(x, p[i].l2) - 1;
    	//cout << p[i].l1 << " " << p[i].l2 << endl;
    	p[i].r1 = F(y, p[i].r1);
    	p[i].r2 = F(y, p[i].r2) - 1;
    	for (int kek=p[i].l1; kek <= p[i].l2; kek++) for (int tet=p[i].r1; tet <= p[i].r2; tet++){
    		used[kek][tet] = true;
    	}
    }
    Dinic new_dinic;
    int vert = A+B+2;
    for (int i=0; i < A; i++) new_dinic.addEdge(0, i+1, szx[i]);
    for (int i=0; i < B; i++) new_dinic.addEdge(A+1+i, vert-1, szy[i]);
    for (int i=0; i < A; i++) for (int j=0; j < B; j++){
    	if (!used[i][j]) continue;
    	new_dinic.addEdge(i+1, A+j+1, FLOW);
    }
    cout << new_dinic.dinic(0, vert-1);
}