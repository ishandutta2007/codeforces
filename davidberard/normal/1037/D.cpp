#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> edges;
vector<int> parent;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	edges.resize(N+1);
	parent.resize(N+1);
	for(int i=0;i<N-1;++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> seq(N);
	for(auto& x : seq) cin >> x;

	if(seq[0] != 1) {
		cout <<"NO"<< endl;
		return 0;
	}
	vector<int> level;
	level.push_back(1);
	int ptr = 1;
	parent[1] = -1;
	while(level.size()) {
		vector<int> next;
		for(auto & u : level) {
			set<int> expected;
			for(auto& v : edges[u]) {
				if(parent[u] == v) continue;
				expected.insert(v);
				parent[v] = u;
			}
			int s = expected.size();
			for(int i=0;i<s;++i,++ptr) {
				if(!expected.count(seq[ptr])) {
					cout << "NO" << endl;
					return 0;
				}
				expected.erase(seq[ptr]);
			}
			for(int i=s;i>0;--i) {
				next.push_back(seq[ptr-i]);
			}
		}
		level = next;
	}

	cout << "YES" << endl;
	
	return 0;
}