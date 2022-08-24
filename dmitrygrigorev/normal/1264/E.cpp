#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct MinCostMaxFlow {
    struct Edge{
        int to, cap;
        int flow;
        int cost;
    };

    static const int MAX_V = 3003;
    static const int MAX_E = 2 * 333 * 333;
    static const int INF = 1e9 + 7;
    static const int MAX_COST = 1e9 + 7; // change to ll if it is exceeded in FB

    int sz = 0;
    Edge e[MAX_E];
    vector<int> g[MAX_V];
    int dp[MAX_V];
    pair<int, int> prev[MAX_V];
    int phi[MAX_V];

    void addEdge(int v, int to, int cap, int cost){
    	cost *= -1;
        g[v].push_back(sz);
        e[sz++] = { to, cap, 0, cost };
        g[to].push_back(sz);
        e[sz++] = { v, 0, 0, -cost };
    }

    void calcPhi(int start) {
        // FB for calculating phi, add vertex q and q->v for all v with cost 0
        for (int i = 0; i < MAX_V; ++i) phi[i] = MAX_COST;
        phi[start] = 0;
        for (int k = 0; k < MAX_V; k++) {
            for (int v = 0; v < MAX_V; v++) {
                for (int to : g[v]) {
                    Edge &ed = e[to];
                    if (ed.cap == ed.flow) continue;
                    phi[ed.to] = min(phi[ed.to], phi[v] + ed.cost);
                }
            }
        }
    }

    ll find(int start, int finish, int required_flow) {
        calcPhi(start);

        ll ans = 0;

        while (required_flow) {
            for (int i = 0; i < MAX_V; i++) dp[i] = INF, prev[i] = { -1, -1 };
            dp[start] = 0;

            set< pair<int, int> > se;
            se.insert({ 0, start });

            while (!se.empty()) {
                auto [dist, v] = *se.begin(); se.erase(se.begin());
                for (int to : g[v]) {
                    auto ed = e[to];
                    if (ed.flow < ed.cap && dp[ed.to] > dp[v] + ed.cost - phi[ed.to] + phi[v]) {
                        prev[ed.to] = { v, to };
                        se.erase({ dp[ed.to], ed.to });
                        dp[ed.to] = dp[v] + ed.cost - phi[ed.to] + phi[v];
                        se.insert({ dp[ed.to], ed.to });
                    }
                }
            }

            if (dp[finish] == INF) {
                return -1;
            }

            int max_flow = required_flow;
            int v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                max_flow = min(max_flow, e[now.y].cap - e[now.y].flow);
                v = now.x;
            }
            ans += (dp[finish] + phi[finish]) * (ll)max_flow;

            v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                e[now.y].flow     += max_flow;
                e[now.y ^ 1].flow -= max_flow;
                v = now.x;
            }
            required_flow -= max_flow;

            // recalc phi
            int min_phi = 0;
            for (int i = 0; i < MAX_V; ++i) {
                if (dp[i] == INF) {
                    min_phi = min(min_phi, phi[i]);
                } else {
                    phi[i] += dp[i];
                }
            }
            for (int i = 0; i < MAX_V; ++i) {
                if (dp[i] == INF) {
                    phi[i] -= min_phi;
                }
            }
            //
        }

        return ans;
    }
} min_cost_max_flow;


MinCostMaxFlow kek;

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> out_deg(n, 0);

	map<pair<int, int>, int> was;

	int ans[n][n];
	for (int i=0;i<n;++i) for (int j=0;j<n;++j) ans[i][j] = 0;

	for (int i=0;i<m;++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		out_deg[u]++;
		ans[u][v] = 1;
		if (u > v) swap(u, v);
		was[{u, v}] = -1;
	}

	int rem = n*(n-1)/2 - m;

	int u = 0;

	for (int i=0; i < n; ++i) {
		for (int j=i+1; j < n; ++j){
			if (was.count({i, j})) continue;
			was[{i, j}] = u++;
			kek.addEdge(0, u, 1, 0);
			kek.addEdge(u, rem+1+i, 1, 0);
			kek.addEdge(u, rem+1+j, 1, 0);
		}
	}

	for (int i=0; i < n; ++i){
		for (int j=0; j < n-1-out_deg[i]; ++j){
			int was = (out_deg[i] + j) * (n-1 - out_deg[i] - j);
			int now = (out_deg[i] + j + 1) * (n-1 - out_deg[i] - j - 1);
			int profit = now - was;
			//cout << "=== " << i << " " << was << " " << now << endl;
			kek.addEdge(rem+1+i, rem+1+n, 1, profit);
		}
	}

	int res = kek.find(0, rem+1+n, rem);
	//cout << res << endl;
	u = 0;
	for (int i=0; i < n; ++i) {
		for (int j=i+1; j < n; ++j) {
			if (was[{i, j}] == -1) {
				continue;
			}
			int index = 3*u + 1;
			if (kek.e[2*index].flow == 1) {
				ans[i][j] = 1;
			}
			else ans[j][i] = 1;
			u++;
		}
	}

	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j) cout << ans[i][j];
		cout << "\n";
	}





}