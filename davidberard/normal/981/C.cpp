#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> edges(N+1);
	int u, v;
	for(int i=0;i<N-1;++i) {
		cin >> u;
		cin >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	int start = 0;
	for(int i=1;i<=N;++i) {
		if(edges[i].size() > 2) {
			if(start == 0) {
				start = i;
			} else {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if(start == 0) {
		start = 1;
	}

	queue<pii> q;
	q.push(pii(start, -1));
	vector<int> leaves;
	while(!q.empty()) {
		int u = q.front().first, par = q.front().second; q.pop();
		int child_count = 0;
		for(const int& v : edges[u]) {
			if(v != par) {
				++child_count;
				q.push(pii(v, u));
			}
		}
		if(!child_count) {
			leaves.push_back(u);
		}
	}
	cout << "Yes" << '\n';
	cout << leaves.size() << "\n";
	for(auto& ii : leaves) {
		cout << start << " " << ii << "\n";
	}
	return 0;
}