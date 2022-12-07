#include<bits/stdc++.h>
using namespace std;
int tot(0);
const int N(2011);
string ans[N];
int match[N], fo[N], so[N];
vector<int> adj[N];
bool vst[N];
int dfs(int v) {
	for(int y : adj[v]) {
		if(!vst[y]) {
			vst[y] = true;
			if(match[y] == -1 || dfs(match[y])) {
				match[y] = v;
				return true;
			}
		}
	}
	return false;
}
map<string, int> mp;
map<int, string> rev;
int hsh(string s) {
	if(mp.count(s) == 0) {
		mp[s] = tot++;
		rev[tot - 1] = s;
		return tot - 1;
	}else {
		return mp[s];
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i(0); i < n; i++) {
		string a, b;
		cin >> a >> b;
		fo[i] = hsh(a.substr(0, 3));
		so[i] = hsh(a.substr(0, 2) + b.substr(0, 1));
	}
	for(int i(0); i < n; i++) {
		bool flag(true);
		for(int j(0); j < n; j++) {
			if(j != i && fo[j] == fo[i]) {
				flag = false;
				break;
			}
		}
		adj[i].push_back(so[i]);
		if(flag)
			adj[i].push_back(fo[i]);
	}
	fill(match, match + tot, -1);
	for(int i(0); i < n; i++) {
		fill(vst, vst + tot, false);
		if(!dfs(i)) {
			printf("NO\n");
			return 0;
		}
	}
	for(int i(0); i < tot; i++)
		if(match[i] != -1)
			ans[match[i]] = rev[i];
	printf("YES\n");
	for(int i(0); i < n; i++)
		cout << ans[i] << endl;
}