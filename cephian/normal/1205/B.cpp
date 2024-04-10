#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int INF = 0x7fffffff;

const int N = 1e5+5;
vector<int> G[N];

int search(int s, int t) {
	set<int> seen;
	queue<pair<int,int>> Q;
	Q.emplace(s, 0);
	seen.insert(s);
	while(Q.size()) {
		int u, d;
		tie(u,d) = Q.front();
		Q.pop();
		for(int v : G[u]) {
			if(u == s && v == t) continue;
			if(v == t)
				return d+2;
			if(!seen.count(v)) {
				Q.emplace(v, d+1);
				seen.insert(v);
			}
		}
	}
	return INF;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> which[64];
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		for(int j = 0; j < 64; ++j) {
			if((1LL<<j)&a)
				which[j].push_back(i);
		}
	}

	for(int j = 0; j < 64; ++j) {
		if(which[j].size() > 2) {
			cout << "3\n";
			return 0;
		} else if(which[j].size() == 2) {
			int u = which[j][0];
			int v = which[j][1];
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	
	int ans = INF;
	for(int u = 0; u < n; ++u) {
		for(int v : G[u]) {
			ans = min(ans, search(u, v));
		}
	}
	if(ans == INF) {
		cout << "-1\n";
	} else {
		cout << ans << '\n';
	}
}