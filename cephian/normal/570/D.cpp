#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 5e5+5;
vector<int> T[N];
vector<int> queries[N];
vector<string> ans[N];
int mask[N];
int sz[N];
vector<pair<int,int>> Q;

int findsz(int v) {
	sz[v] = 1;
	for(int u : T[v])
		sz[v] += findsz(u);
	return sz[v];
}

inline string pal(int a) {
	return (a == 0 || (a&-a) == a)?"Yes":"No";
}

void solve(int v, int height, map<int,int>& stored) {
	stored[height] ^= mask[v];
	if(T[v].size() != 0) {
		int big = -1;
		for(int u : T[v]) {
			if(big == -1 || sz[u] > sz[big])
				big = u;
		}
		solve(big, height+1, stored);
		for(int u : T[v]) {
			if(u == big) continue;
			map<int,int> tmp;
			solve(u, height+1, tmp);
			for(auto x : tmp)
				stored[x.first] ^= x.second;
		}
	}
	ans[v].resize(queries[v].size());
	for(int i = 0; i < (int)queries[v].size(); ++i) {
		int res = 0;
		if(stored.count(queries[v][i]))
			res = stored[queries[v][i]];
		ans[v][i] = pal(res);
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		T[p].push_back(i);
	}
	string s;
	cin >> s;
	for(int i = 1; i <= n; ++i)
		mask[i] = 1<<(s[i-1]-'a');

	for(int i = 0; i < m; ++i) {
		int v, h;
		cin >> v >> h;
		Q.emplace_back(v, queries[v].size());
		queries[v].push_back(h);
	}

	findsz(1);
	map<int,int> tmp;
	solve(1, 1, tmp);

	for(int i = 0; i < m; ++i) {
		cout << ans[Q[i].first][Q[i].second] << "\n";
	}

}