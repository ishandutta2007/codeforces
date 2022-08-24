#pragma GCC optimize("unroll-all-loops") 
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int sum = 0;

const int M = 200000;
int st[M];

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 207*207; //count of vertices

    edge e[350000];
    int t = 0;

    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];
    int ptr2[N+7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(t);
        e[t++] = {b, 0, cap};
        g[b].pb(t);
        e[t++] = {a, 0, 0};
    }

    void qaddEdge(int a, int b, int cap){
        g[a].pb(t);
        e[t++] = {b, 0, cap};
        g[b].pb(t);
        e[t++] = {a, 0, cap};
    }

    void rm_edge(int index) {

    	index *= 2;

    	e[index].cap = 0;
    	e[index].flow = 0;

    	e[index^1].cap = 0;
    	e[index^1].flow = 0;

    }

    int minFlow = 1, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;

        int uk = 0;
        int ptr = 0;

        st[ptr++] = start;

        while(uk < ptr){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap > ed.flow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st[ptr++] = ed.to;
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

    vector<bool> used, used2;

    int dfs2(int v, int need, int flow){

    	if (flow == 0) {
    		used[v] = true;

	        if (v == finish) return flow;
	        if (need == v) {
	        	flow = 1;
	        }

	       // cout << v << " " << need << " " << flow << endl;

	        for (; ptr[v] < g[v].size(); ptr[v]++){
	            int to = g[v][ptr[v]];
	            edge ed = e[to];

	            if (flow == 0 && used[ed.to]) continue;
	            if (flow == 1 && used2[ed.to]) continue;

	            if (ed.flow >= minFlow){
	                int add = dfs2(ed.to, need, min(flow, ed.flow));
	                if (add){
	                	//cout << "!!!!!!!! " << v << " " << ed.to << " " << add << endl;
	                    e[to].flow -= add;
	                    e[to ^ 1].flow += add;
	                    return add;
	                }
	            }
	        }
	        return 0;
    	}

    	else {
    		used2[v] = true;

	        if (v == finish) return flow;
	        if (need == v) {
	        	flow = 1;
	        }

	       // cout << v << " " << need << " " << flow << endl;

	        for (; ptr2[v] < g[v].size(); ptr2[v]++){
	            int to = g[v][ptr2[v]];
	            edge ed = e[to];

	            if (flow == 0 && used[ed.to]) continue;
	            if (flow == 1 && used2[ed.to]) continue;

	            if (ed.flow >= minFlow){
	                int add = dfs2(ed.to, need, min(flow, ed.flow));
	                if (add){
	                	                	//cout << "!!!!!!!! " << v << " " << ed.to << " " << add << endl;

	                    e[to].flow -= add;
	                    e[to ^ 1].flow += add;
	                    return add;
	                }
	            }
	        }
	        return 0;
    	}
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        while(bfs()){
            for (int i = 0; i < N; i++) ptr[i] = 0;
            while(int now = dfs(start, (int)2e9 + 7)) {
            	flow += now;
            	sum += now;
            }
            if (flow==2) break;
        }
        return flow;
    }

    void remove_path(int vertex) {

    	int now = 1;

    	while (now) {
    		for (int i = 0; i < N; i++) ptr[i] = 0, ptr2[i] = 0;
    		used.assign(N, false);
    		used2.assign(N, false);

    		now = dfs2(start, vertex, 0);
    		//cout << " === " << now << endl;
    		sum -= now;
    	}

    }
};

int matrix[207][207];
Dinic dinic;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return (matrix[a.x][a.y] < matrix[b.x][b.y]);
}

int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	vector<pair<int, int> > val;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] > 0) val.pb(mp(i, j));
		}
	}

	sort(all(val), cmp);
	for (auto t : val) {
		dinic.addEdge(t.x * n + t.y + 1, n*n + 1, 1e9);
	}

	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j-1 >= 0 && matrix[i][j] > 0 && matrix[i][j-1] > 0) {
				ans += abs(matrix[i][j] - matrix[i][j-1]);
			}

			if (i-1 >= 0 && matrix[i][j] > 0 && matrix[i-1][j] > 0) {
				ans += abs(matrix[i][j] - matrix[i-1][j]);
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (i != n-1 && matrix[i][j] != -1 && matrix[i][j-1] != -1) {
				int A = i * n + j;
				int B = i * n + (j - 1);

				dinic.qaddEdge(A+1, B+1, 1);
			}

			if (j != n-1 && matrix[i-1][j] != -1 && matrix[i][j] != -1) {
				int A = i * n + j;
				int B = (i-1) * n + j;

				//cout << A << " " << B << endl;

				dinic.qaddEdge(A+1, B+1, 1);
			}
		}
	}

	for (int i = 0; i + 1 < val.size(); ++i) {
		//cout << i << endl;
		if (dinic.e[2*i].flow) dinic.remove_path(val[i].x * n + val[i].y + 1);
		dinic.rm_edge(i);

		dinic.addEdge(0, val[i].x * n + val[i].y + 1, 1e9);
		dinic.dinic(0, n*n+1);

		ans += (ll) sum * (ll) (matrix[val[i+1].x][val[i+1].y] - matrix[val[i].x][val[i].y]);

		//cout << val[i].x << " " << val[i].y << " " << sum << endl;

	}

	cout << ans;


}