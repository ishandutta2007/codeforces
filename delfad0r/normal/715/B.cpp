#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> LLI;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
	out << "[";
	for (T x : vec) out << x << ", ";
	out << "]";
	return out;
}

#if DEBUG && !ONLINE_JUDGE
	ifstream input_from_file("input.txt");
	#define cin input_from_file
	#define dbg_var(x) cerr << #x << ": " << x << endl;
#else
	#define dbg_var(x)
#endif

struct edge_t {
    int to;
    LL w;
    bool erased;
};

int N, M;
LL L;
int S, T;
vector<edge_t> G[2000];
bool done = false;
LL dist[2000];
bool visited[2000];

void dijkstra(int n0, int u, int v) {
    memset(visited, 0, sizeof(visited));
    fill(dist, dist + N, 1LL << 60);
    dist[n0] = 0;
    priority_queue<LLI, vector<LLI>, greater<LLI>> Q;
    Q.emplace(0, n0);
    while(Q.size()) {
        int n = Q.top().second;
        Q.pop();
        if(visited[n]) {
            continue;
        }
        visited[n] = true;
        if(visited[u] && visited[v] && visited[T]) {
            return;
        }
        for(auto& e : G[n]) {
            if((n == u && e.to == v) || (n == v && e.to == u)) {
                continue;
            }
            if(dist[e.to] > dist[n] + e.w) {
                Q.emplace(dist[e.to] = dist[n] + e.w, e.to);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    cin >> N >> M >> L >> S >> T;
    while(M--) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(edge_t{b, max(1, w), w == 0});
        G[b].push_back(edge_t{a, max(1, w), w == 0});
    }
    for(int n = 0; n < N && !done; ++n) {
        for(auto& e : G[n]) {
            if(!e.erased || done || e.to < n) {
                continue;
            }
            LL d0, d1, du, dv;
            dijkstra(S, n, e.to);
            d0 = dist[T];
            du = dist[n];
            dv = dist[e.to];
            dijkstra(T, n, e.to);
            d1 = e.w + min(du + dist[e.to], dv + dist[n]);
            if(d0 < L) {
                e.w = L + 1;
            } else if(d0 == L) {
                e.w = L + 1;
                done = true;
            } else if(d1 > L) {
                done = true;
            } else {
                e.w += L - d1;
                done = true;
            }
            for(auto& e1 : G[e.to]) {
                if(e1.to == n) {
                    e1.w = e.w;
                    break;
                }
            }
        }
    }
    dijkstra(S, S, S);
    if(dist[T] == L) {
        cout << "YES\n";
        for(int n = 0; n < N; ++n) {
            for(auto& e : G[n]) {
                if(n <= e.to) {
                    cout << n << ' ' << e.to << ' ' << e.w << '\n';
                }
            }
        }
    } else {
        cout << "NO\n";
    }
}