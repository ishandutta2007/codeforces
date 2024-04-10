#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

int n;
graph G;
graph ID;

vector<vector<int> > ans;
void addp(int id, int t) {
	while(ans.size() <= t)
		ans.push_back(vector<int>());
	ans[t].push_back(id);
}

void solve(int from, int lab, int v) {
	int ctr = 0;
	for(int i = 0; i < G[v].size(); ++i) {
		if(ctr == lab) ++ctr;
		if(G[v][i] == from) continue;
		addp(ID[v][i],ctr);
		solve(v, ctr++, G[v][i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	G = graph(n,vector<int>());
	ID = graph(n,vector<int>());
	for(int i = 1; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);
		ID[a].push_back(i);
		ID[b].push_back(i);
	}
	solve(-1,-1,0);
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i].size();
		for(int j = 0; j < ans[i].size(); ++j)
			cout << " " << ans[i][j];
		cout << "\n";
	}
	return 0;
}