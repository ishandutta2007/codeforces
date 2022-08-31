#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int go[1000][32];
int total=0;

bool expr(vector<int> &v, int x) {
	int n = v.size();
	for (int i = 1; i < (1<<n); ++i) {
		int t = x;
		for (int j = 0; j < n; ++j) {
			if ((1<<j)&i) t ^= v[j];
		}
		if (t==0) return true;
	}
	return false;
}

map<vector<int>, int> mm;

vector<int> get(vector<int> &v) {
	vector<int> t;
	for (int i = 1; i < 32; ++i) {
		if (expr(v, i) && !expr(t, i)) t.push_back(i);
	}
	return t;
}

bool was[1000];

int check(vector<int> &v) {
	if (mm.count(v)) return mm[v];
	mm[v] = total++;
	return mm[v];
}

void recursively_gen(int i, vector<int> &v) {
	if (v.size() <= 5) {
		vector<int> t = get(v);
		int x = check(t);
	    if (!was[x]) {
	        was[x] = true;
    		go[x][0] = -1;
    		for (int j = 1; j < 32; ++j) {
    			if (expr(t, j)) go[x][j] = -1;
    			else {
    				t.push_back(j);
    				vector<int> q = get(t);
    				go[x][j] = check(q);
    				t.pop_back();
    			}
    		}
	    }
		
	}
	if (v.size() == 5) return;
	int start = 1;
	if (v.size()) start = v.back() + 1;
	for (int i = start; i < 32; ++i) if (!expr(v, i)) {
		v.push_back(i);
		recursively_gen(i+1, v);
		v.pop_back();
	}
}

struct Edge{
	int to; int w; int index;
};

vector<vector<Edge> > data;
vector<bool> used;

const int mod = 1000000007;

int dp[374];
int ns;
vector<pair<int, int> > connected;
vector<int> pos;

vector<int> take, th;

void dfs(int vertex, int last, int w) {
	th.push_back(vertex);
	used[vertex] = true;
	pos[vertex] = w;

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i].to;
		int q = data[vertex][i].w;
		if (to == 0) {
			connected.push_back({vertex, q});
			continue;
		}
		if (to==last) continue;
		if (used[to]) {
			if (vertex < to) {
				int T = pos[vertex]^pos[to]^q;
				take.push_back(T);
			}
			continue;
		}
		dfs(to, vertex, w^q);
	}

}

int midway[374];
int current[374];
int nw[374];

void clear() {
	for (int i = 0; i < th.size(); ++i) used[th[i]] = false;
	th.clear();
}

void recalc(int vertex) {
	ns = 0;
	connected.clear();
	take.clear();
	th.clear();
	dfs(vertex, -1, 0);

	for (int i=0; i < 374; ++i) midway[i] = dp[i];
	vector<pair<int, int> > tc = connected;

	for (int start = 0; start < tc.size(); ++start) {
		take.clear();
		clear();
		dfs(tc[start].first, -1, tc[start].second);
		for (int i = 0; i < 374; ++i) current[i] = 0;

		for (int i = 0; i < 374; ++i) {
			int N = i;
			for (int j = 0; j < take.size(); ++j) {
				if (N==-1) break;
				N = go[N][take[j]];
			}
			if (N!= -1) {
				current[N] = (current[N] + dp[i]) % mod;
			}
		}

		for (int j = start + 1; j < tc.size(); ++j) {
			for (int e = 0; e < 374; ++e) nw[e] = current[e];
			int edge = pos[tc[j].first]^tc[j].second;
			for (int e = 0; e < 374; ++e) {
				int T = go[e][edge];
				if (T!=-1) nw[T] = (nw[T] + current[e]) % mod;
			}
			for (int e = 0; e < 374; ++e) current[e] = nw[e];
		}
		for (int e = 0; e < 374; ++e) midway[e] = (midway[e] + current[e]) % mod;
	}

	for (int i = 0; i < 374; ++i) {
		dp[i] = midway[i];
	}


}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> now;
	recursively_gen(0, now);
	

	int n, m;
	cin >> n >> m;
	data.assign(n, {});

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		data[u-1].push_back({v-1, w, i});
		data[v-1].push_back({u-1, w, i});
	}

	dp[0] = 1;
	used.assign(n, false);
	pos.assign(n, -1);

	for (int i = 0; i < data[0].size(); ++i) {
		int to = data[0][i].to;
		if (used[to]) continue;
		//cout << "===\n";
		recalc(to);
	}

	int ans = 0;
	for (int i = 0; i < 374; ++i) ans = (ans + dp[i]) % mod;
	cout << ans;



}