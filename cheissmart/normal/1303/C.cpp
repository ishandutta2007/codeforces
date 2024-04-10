#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

bool vis[26];
		vi G[26];

bool dfs(int u, int from = -1) {
	vis[u] = 1;
	for(int v:G[u]) if(v != from) {
		if(!vis[v]) {
			if(!dfs(v, u)) return false;
		} else return false;
	}
	return true;
}

void dfs1(int u) {
	vis[u] = 1;
	cout << (char)('a' + u);
	for(int v:G[u]) {
		if(!vis[v])dfs1(v);
	}
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		memset(vis, 0, sizeof vis);
		for(int i = 0; i <26; i++) G[i].clear();
		string s;
		cin >> s;
		for(int i=0;i<(int)s.size()-1;i++) {
			int x = s[i] - 'a', y = s[i+1] - 'a';
			G[x].PB(y);
			G[y].PB(x);
		}
		for(int i = 0; i < 26; i++) {
			sort(ALL(G[i]));
			G[i].resize(unique(ALL(G[i]))-G[i].begin());
		}
		bool ok = true;
		vi v;
		for(int i = 0; i < 26; i++) {
			if(G[i].size() > 2) ok = false;
		}
		if(!ok) {
			cout << "NO" << endl;
			continue;
		}
		for(int i = 0; i < 26; i++) {
			if(!vis[i]) {
				ok &= dfs(i);
			}
		}
		if(!ok) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < 26; i++) {
			if(!vis[i] && G[i].size() == 1) {
				dfs1(i);
			}
			if(G[i].size() == 0) dfs1(i);
		}
		cout << endl;
	}	
	
}