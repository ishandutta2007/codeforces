#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5+5;
vector<int> G[N];
int t[N];
int cur[N] = {0};


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	map<int, vector<int>> list;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		list[t[i]].push_back(i);
	}
	for(const auto& x : list) {
		int top = x.first;
		for(const auto& i : x.second) {
			set<int> seen;
			for(int j : G[i]) {
				if(cur[j] != 0) {
					seen.insert(cur[j]);
				}
			}
			if(!seen.count(top) && (int)seen.size() == top-1) {
				cur[i] = top;
			} else {
				cout << "-1\n";
				return 0;
			}
		}
	}
	for(const auto& x : list) {
		for(const auto& i : x.second) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}