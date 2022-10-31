#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

struct Edge {
    int u, v;
    long long cap, cost;

    Edge(int _u, int _v, long long _cap, long long _cost){
        u = _u; v = _v; cap = _cap; cost = _cost;
    }
};

struct MinCostFlow {
    int n, s, t;
    long long flow, cost;
    vector<vector<int> > graph;
    vector<Edge> e;
    vector<long long> dist;
    vector<int> parent;

    MinCostFlow(int _n){
        // 0-based indexing
        n = _n;
        graph.assign(n, vector<int> ());
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed = true){
        graph[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));

        graph[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));

        if(!directed)
            addEdge(v, u, cap, cost, true);
    }

    pair<long long, long long> getMinCostFlow(int _s, int _t){
        s = _s; t = _t;
        flow = 0, cost = 0;
        while(SPFA()){
            flow += sendFlow(t, 1LL<<62);
        }
        return make_pair(flow, cost);
    }

    // not sure about negative cycle
    bool SPFA(){
        parent.assign(n, -1);
        dist.assign(n, 1LL << 62);      dist[s] = 0;
        vector<int> queuetime(n, 0);    queuetime[s] = 1;
        vector<bool> inqueue(n, 0);     inqueue[s] = true;
        queue<int> q;                   q.push(s);
        bool negativecycle = false;

        while(!q.empty() && !negativecycle){
            int u = q.front(); q.pop(); inqueue[u] = false;
            for(int i = 0; i < graph[u].size(); i++){
                int eIdx = graph[u][i];
                int v = e[eIdx].v;
                long long w = e[eIdx].cost, cap = e[eIdx].cap;
                if(dist[u] + w < dist[v] && cap > 0){
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;

                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v] = true;

                        if(queuetime[v] == n+2){
                            negativecycle = true;
                            break;
                        }
                    }
                }
            }
        }

        return dist[t] != (1LL << 62);
    }

    long long sendFlow(int v, long long curFlow){
        if(parent[v] == -1)
            return curFlow;
        int eIdx = parent[v];
        int u = e[eIdx].u;
        long long w = e[eIdx].cost;
        long long f = sendFlow(u, min(curFlow, e[eIdx].cap));
        cost += f * w;
        e[eIdx].cap -= f;
        e[eIdx ^ 1].cap += f;
        return f;
    }
    void findFlow() {
        bool h = 0;
    	for(auto ed : e) {
    		if(h) {
    			// flow = ed.cap from ed.v -> ed.u
    		}
    		h ^= 1;
    	}
    }
};


int main() {fio;
	int N, K;
	cin >> N >> K;
	vector <int> A(1 << N);
	for(int i = 0; i < (1 << N); i++) {
		cin >> A[i];
	}
	vector <pair <pair <int, int>, int> > edges;
	for(int i = 0; i < (1 << N); i++) {
		if(__builtin_popcountll(i) % 2) continue;
		for(int B = 0; B < N; B++) {
			edges.push_back({{i, i ^ (1 << B)}, A[i] + A[i ^ (1 << B)]});
		}
	}
	sort(all(edges), [&](auto a, auto b){
		return a.second > b.second;
	});

	int ITER = N * K * 2;
	set <int> elements;
	for(int i = 0; i < min(ITER, (int)edges.size()); i++) {
		elements.insert(edges[i].first.second);
		elements.insert(edges[i].first.first);
	}
	map <int, int> f;
	int c = 0;
	for(auto e : elements) {
		f[e] = c;
		c++;
	}
	int SZ = elements.size() + 3;
	MinCostFlow mcmf(SZ);
	int src = SZ - 1, sd = SZ - 2, snk = SZ - 3;
	int G = 0;
	for(auto u : edges) {
		int e1 = f[u.first.first];
		int e2 = f[u.first.second];
		int w = u.second;
		mcmf.addEdge(e1, e2, 1, -w);
		G++;
		if(G >= ITER) {
		    break;
		}
	}
	mcmf.addEdge(src, sd, K, 0);
	for(int e : elements) {
		if(__builtin_popcountll(e) % 2 == 0) {
			mcmf.addEdge(sd, f[e], 1, 0);
		} else {
			mcmf.addEdge(f[e], snk, 1, 0);
		}
	}
	cout << -mcmf.getMinCostFlow(src, snk).second << endl;
    return 0;
}