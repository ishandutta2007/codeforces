#include<bits/stdc++.h>
using namespace std;
const int N(222222);
vector<int> adj[N];
vector<int> ans;
bool vst[N];
void dfs(int v, int fa) {
	ans.push_back(v);
	vst[v] = true;
	for(int y : adj[v]) {
		if(y != fa && !vst[y]) {
			dfs(y, v);
		}
	}
	if(fa) ans.push_back(fa);
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i(0); i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == y)
			continue;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	int cur(0);
	for(int i(0); i < k; i++) {
		vector<int> v;
		while(v.size() < (2 * n + k - 1) / k && cur < (int)ans.size()) {
			if(!v.empty() && ans[cur] == v.back()) {
			}else {
				v.push_back(ans[cur]);
			}
			cur++;
		}
		if(v.empty())
			v.push_back(1);
		printf("%d", (int)v.size());
		for(int i(0); i < (int)v.size(); i++)
			printf(" %d", v[i]);
		printf("\n");
	}
}