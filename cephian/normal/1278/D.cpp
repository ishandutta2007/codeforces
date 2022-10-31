#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;


const int N = 5e5+5;
vector<pair<int,int>> events;
int l[N], r[N];

struct dsu {
	vector<int> uf;

	int id(int u) {
		return (uf[u]==u) ? u : uf[u]=id(uf[u]);
	}

	void merge(int u, int v) {
		u = id(u), v = id(v);
		if(u != v)
			uf[u] = v;
	}

	void init(int n) { 
		uf.resize(n);
		for(int i = 0; i < n; ++i)
			uf[i] = i;
	}
	dsu(int n) {init(n);}
};

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		events.emplace_back(l[i], i);
		events.emplace_back(r[i], i);
	}
	sort(events.begin(), events.end());
	set<pair<int,int>> active;
	dsu D(n);
	int edges = 0;
	for(int i = 0; i < (int)events.size(); ++i) {
		const int j = events[i].second;
		if(l[j] == events[i].first) {
			active.emplace(-r[j], j);
			auto it = active.find(make_pair(-r[j], j));
			++it;
			while(it != active.end()) {
				int k = it->second;
				if(D.id(k) == D.id(j)) {
					cout << "NO\n";
					return 0;
				}
				D.merge(j, k);
				++edges;
				++it;
			}
		} else {
			active.erase(make_pair(-r[j], j));
		}
	}
	if(edges == n-1) {
		cout << "YES\n";
	} else cout << "NO\n";
}