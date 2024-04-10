#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = pair<int,int>;

const vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> G(n, vector<int>());
	map<point, int> pt_idx;
	map<int, point> closest;
	for(int i = 0; i < n; ++i) {
		point p;
		cin >> p.first >> p.second;
		pt_idx[p] = i;
	}
	queue<pair<int, point>> Q;
	for(const auto& pid : pt_idx) {
		const auto& p = pid.first;
		for(const vector<int>& v : dir) {
			int dx = v[0], dy = v[1];
			auto q = make_pair(p.first + dx, p.second + dy);
			if(pt_idx.count(q)) {
				G[pid.second].push_back(pt_idx[q]);
			} else {
				Q.emplace(pid.second, q);
			}
		}
	}
	while(!Q.empty()) {
		int u; point p;
		tie(u, p) = Q.front();
		Q.pop();
		if(closest.count(u)) continue;
		closest[u] = p;
		for(int v : G[u])
			Q.emplace(v, p);
	}
	for(const auto& x : closest)
		cout << x.second.first << ' ' << x.second.second << '\n';
}