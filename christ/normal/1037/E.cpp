#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+2, BASE = 131, MOD = 1e9+9, MOD2 = 696969697, INV2 = 159611381,LOG = __lg(MN) + 2, INV = 526717562;
set<int> adj[MN]; int deg[MN]; set<pii> st;
void fix (int cur) {
	auto it = st.find({deg[cur],cur});
	if (it != st.end()) {
		st.erase(it);
		st.insert({--deg[cur],cur});
	}
}
int main () {
	int n,m,k;
	scanf ("%d %d %d",&n,&m,&k);
	vector<pii> edges(m);
	for (auto &p : edges) {
		scanf ("%d %d",&p.first,&p.second);
		adj[p.first].insert(p.second); adj[p.second].insert(p.first); ++deg[p.first]; ++deg[p.second];
	}
	for (int i = 1; i <= n; i++) st.insert({deg[i],i});
	while (!st.empty() && st.begin()->first < k) {
		int go = st.begin()->second; st.erase(st.begin());
		for (int i : adj[go]) fix(i);
	}
	vector<int> ans;
	while (m--) {
		ans.push_back((int)st.size());
		adj[edges[m].first].erase(edges[m].second); adj[edges[m].second].erase(edges[m].first);
		if (st.count({deg[edges[m].first],edges[m].first}) && st.count({deg[edges[m].second],edges[m].second})) {
			fix(edges[m].first); fix(edges[m].second);
			while (!st.empty() && st.begin()->first < k) {
				int go = st.begin()->second; st.erase(st.begin());
				for (int i : adj[go]) fix(i);
			}
		}
	}
	reverse(all(ans));
	for (int i : ans) printf ("%d\n",i);
    return 0;
}