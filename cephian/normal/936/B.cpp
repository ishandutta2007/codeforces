#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;

const int N = 1e5+5;
vector<int> g[N];
vector<int> h[2*N];
int n, m;

int seen[N] = {};
bool dfs(int v) {
	if(seen[v] == 1) return true;
	if(seen[v] == 2) return false;
	seen[v] = 1;
	for(int u : g[v]) {
		if(dfs(u))
			return true;
	}
	seen[v] = 2;
	return false;
}

bool seen2[2*N] = {};
vector<int> winning;
bool dfs2(int v) {
	if(seen2[v]) return false;
	seen2[v] = true;
	int v2 = v;
	if(v2 > n) v2 -= n;

	if(g[v2].size() == 0 && v > n) {
		winning.push_back(v2);
		return true;
	}
	for(int u : h[v]) {
		if(dfs2(u)) {
			winning.push_back(v2);
			return true;
		}
	}
	return false;
}


int main() {
	fio;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		int c;
		cin >> c;
		for(int j = 0; j < c; ++j) {
			int u;
			cin >> u;
			g[i].push_back(u);
			h[i].push_back(n+u);
			h[i+n].push_back(u);
		}
	}
	int s;
	cin >> s;
	if(dfs2(s)) {
		cout << "Win\n";
		for(int i = winning.size()-1; i >= 0; --i)
			cout << winning[i] << " ";
		cout << "\n";
		return 0;
	}

	if(dfs(s)) {
		cout << "Draw\n";
		return 0;
	}
	cout << "Lose\n";
}