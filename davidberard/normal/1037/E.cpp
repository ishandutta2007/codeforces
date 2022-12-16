#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * Basically, we keep adding edges, and we want to know how many people after
 * each added edge are in a group such that every member in the group has an
 * edge to at least K other members in the group. Sort of like a clique.
 *
 * Think about it for a while and seems pretty hard to figure out if a new edge
 * creates such a group, cause you gotta check a bunch of edges, seems like a N
 * bfs sort of thing.
 *
 * So look at the opposite situation, how can we remove people from these
 * groups? Sort of like pruning a tree, look for people who can't possibly be in
 * such a group, the "leaves" sort of, cause if a bunch of people are all
 * connected to K people but none of them form this group thing, then at the
 * edges there should probably be some people who don't have enough connections.
 *
 * Remove these people along with their edges... and continue until you've
 * removed all the people who have < K connections. But can we prove that if
 * there are no people with < K connections in our graph, all people satisfy the
 * requirement?
 */

vector<set<int>> edges;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<pii> added;
	int N, M, K;
	cin >> N >> M >> K;
	edges.resize(N+1);
	for(int i=0;i<M;++i) {
		int u, v;
		cin >> u >> v;
		added.emplace_back(u, v);
		edges[u].insert(v);
		edges[v].insert(u);
	}
	queue<int> bad;
	vector<bool> vis(N+1, false);
	for(int i=1;i<=N;++i) {
		if(edges[i].size() < K) {
			bad.push(i);
			//cerr << "push " << i << endl;
			vis[i] = true;
		}
	}
	vector<int> ans(M);
	int cnt = N;
	for(int i=M-1;i>=0;--i) {
		while(!bad.empty()) {
			int u = bad.front(); bad.pop();
			//cerr << "del " << u << endl;
			--cnt;
			for(auto& v : edges[u]) {
				edges[v].erase(u);
				if(!vis[v] && edges[v].size() < K) {
					bad.push(v);
					vis[v] = true;
				}
			}
		}

		ans[i] = cnt;
		
		int u = added[i].first, v = added[i].second;
		edges[u].erase(v);
		edges[v].erase(u);
		if(edges[u].size() < K && !vis[u]) {bad.push(u); vis[u] = true; }
		if(edges[v].size() < K && !vis[v]) { bad.push(v); vis[v] = true;}
	}

	for(auto& x : ans) {
		cout << x << "\n";
	}

	return 0;
}