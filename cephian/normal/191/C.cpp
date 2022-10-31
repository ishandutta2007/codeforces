#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii> > graph;

int n,k;
graph G;
vector<vector<int> > path;
const int N = 100005;

int ans[N];
int bit[N]={0};
int olab[N]={0};
int open = 0;

void bit_u(int i, int v) {
	for(;i <= n;i +=(i&(-i)))
		bit[i] += v;
}

int bit_q(int i) {
	if(i == 0) return 0;
	return bit[i] + bit_q(i-(i&(-i)));
}

int ctr = 1;
int dfs(int v, int from) {
	int lab = ctr++;
	for(int i = 0; i < path[v].size(); ++i) {
		int j = path[v][i];
		if(olab[j]) {
			bit_u(olab[j], -1);
			--open;
		} else {
			++open;
			bit_u(lab, 1);
			olab[j] = lab;
		}
	}
	for(int i = 0; i < G[v].size(); ++i) {
		int u = G[v][i].first;
		if(u == from) continue;
		int j = G[v][i].second;
		ans[j] = open;
		int l = dfs(u, v);
		ans[j] += open - 2*bit_q(l-1);
	}
	return lab;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	G = graph(n+1,vector<pii>());
	path = vector<vector<int> >(n+1, vector<int>());
	for(int i = 1; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(pii(b,i));
		G[b].push_back(pii(a,i));
	}
	cin >> k;
	for(int i = 0; i < k; ++i) {
		int a,b;
		cin >> a >> b;
		if(a == b) continue;
		path[a].push_back(i);
		path[b].push_back(i);
	}
	dfs(1,0);
	for(int i = 1; i < n; ++i) {
		cout << ans[i];
		if(i == n-1) cout << "\n";
		else cout << " ";
	}

	return 0;
}