#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 3000007
#define MOD 998244353

struct Graph{
	vector<vector<pair<int, int>>> adj;
	vector<long long> d;
	int n, m;
	Graph(){};
	Graph(int nn){n = nn; adj.resize(n); d.resize(n);}
	void ae(int a, int b, int w){
		adj[a].push_back({b, w});
	}
	void dijkstra(int s) {
    	d.assign(n, 1ll*INF*INF);

    	d[s] = 0ll;
    	using pii = pair<long long, int>;
    	priority_queue<pii, vector<pii>, greater<pii>> q;
    	q.push({0ll, s});
    	while (!q.empty()) {
        	int v = q.top().second;
        	long long d_v = q.top().first;
        	q.pop();
        	if (d_v != d[v])
            	continue;

        	for (auto edge : adj[v]) {
            	int to = edge.first;
            	int len = edge.second;

            	if (d[v] + len < d[to]) {
                	d[to] = d[v] + len;
                	q.push({d[to], to});
            	}
        	}
    	}
	}
};

int n, m;
int lm;
vector<pair<int, int>> edges;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	lm = max(1.0, ceil(log2(0.0+m))+0.5);
	for(int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		--a; --b;
		edges.push_back({a, b});
	}
	Graph g1(n*lm);
	for(auto e : edges){
		for(int i = 0; i<lm; i++){
			if(i%2 == 0) g1.ae(e.first+i*n, e.second+i*n, 1);
			else g1.ae(e.second+i*n, e.first+i*n, 1);
		}
	}
	int curpow = 1;
	for(int i = 0; i<lm-1; i++){
		for(int j = 0; j<n; j++) g1.ae(i*n+j, (i+1)*(n)+j, curpow);
		curpow *= 2;
	}
	g1.dijkstra(0);
	long long ans = 1ll*INF*INF;
	for(int i = 0; i<lm; i++){
		ans = min(ans, g1.d[n-1+i*n]);
	}
	// cout << g1.d[3] << endl;
	if(ans != 1ll*INF*INF){
		cout << ans << endl;
		exit(0);
	}
	Graph g2(2*n);
	for(auto e : edges){
		for(int i = 0; i<2; i++){
			if(i%2 == 0) g2.ae(e.first+i*n, e.second+i*n, 1);
			else g2.ae(e.second+i*n, e.first+i*n, 1);
		}
	}
	for(int j = 0; j<n; j++){
		g2.ae(j, j+n, INF);
		g2.ae(j+n, j, INF);
	}
	g2.dijkstra(0);
	ans = min({ans, g2.d[n-1], g2.d[2*n-1]});
	int num = ans/INF;
	curpow = 1;
	while(num--){
		curpow *= 2;
		if(curpow >= MOD) curpow -= MOD;
	}
	ans = ans%INF+curpow-1;
	if(ans >= MOD) ans -= MOD;
	if(ans < 0) ans += MOD;
	cout << ans << endl;
}