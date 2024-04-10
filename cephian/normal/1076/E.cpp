#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

//point update, range query, 0-indexed
template <class T>
struct bit {
	vector<T> b;
	void init(int n){b.resize(n+1);}
	bit(){}
	bit(int n){init(n);}
	inline void update(int i, T v) {
		for(++i; i < (int)b.size(); i+=i&-i)
			b[i] += v;
	}
	//sum of the first i values
	T prefix(int i) const {
		T a = 0;
		for(; i; i^=i&-i)
			a += b[i];
		return a;
	}
	inline T query(int l, int r) const {
		return prefix(r+1) - prefix(l);
	}
};

const int N = 3e5+5;
vector<int> T[N];
vector<pair<int,int>> ops[N];
ll ans[N];

bit<ll> B;

void dfs(int v, int p, int d) {
	for(auto q : ops[v]) B.update(min(d+q.first, N-1), q.second);
	ans[v] = B.query(d, N-1);
	for(int u : T[v]) {
		if(u == p) continue;
		dfs(u, v, d+1);
	}

	for(auto q : ops[v]) B.update(min(d+q.first, N-1), -q.second);
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int v, d, x;
		cin >> v >> d >> x;
		ops[v].emplace_back(d, x);
	}

	B = bit<ll>(N);
	dfs(1, 1, 0);
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}