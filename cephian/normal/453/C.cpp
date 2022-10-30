#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 100005;
int p[N],cc[N]={0},ncc=0;
vvi G;

bool fcc(int v, int c) {
	if(cc[v] != 0) return 0;
	cc[v] = c;
	bool n0 = p[v] != 0;
	for(auto u : G[v])
		n0 |= fcc(u,c);
	return n0;
}

vi non0;

vi ans;

bool dfs(int v) {
	bool nflip = 1^p[v];
	cc[v] = -1;
	for(auto u : G[v]) {
		if(cc[u] == -1) continue;
		ans.push_back(u);
		bool cflip = dfs(u);
		nflip ^= 1;
		ans.push_back(v);
		if(cflip) {
			ans.push_back(u);
			ans.push_back(v);
			nflip ^= 1;
		}
	}
	return nflip;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	G = vvi(n,vi());
	for(int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 0; i < n; ++i)
		cin >> p[i];
	for(int i = 0; i < n; ++i) {
		if(cc[i] == 0) {
			++ncc;
			if(fcc(i,ncc))
				non0.push_back(i);
		}
	}
	if(non0.size() > 1) {
		cout << "-1\n";
		return 0;
	}
	if(non0.size() == 0) {
		cout << "0\n";
		return 0;
	}
	int root = non0[0];

	ans.push_back(root);
	if(dfs(root))
		ans.pop_back();

	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i]+1 << " ";
	cout << endl;

	return 0;
}