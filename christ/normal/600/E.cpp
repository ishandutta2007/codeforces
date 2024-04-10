#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+3;
map<int,int> freq[MN];
map<int,ll> freqsum[MN];
int sz[MN], big[MN], color[MN], pt[MN];
ll ans[MN];
vector<int> adj[MN];
int get_sz (int cur, int p = -1) {
	int mx = 0;
	for (int i : adj[cur]) if (i != p) {
		sz[cur] += get_sz(i,cur);
		if (sz[i] > mx) {
			mx = sz[i];
			big[cur] = i;
		}
	}
	return ++sz[cur];
}
void ins (int cur, int c, int cnt) {
	if (!freq[cur].count(c)) {
		freq[cur][c] = cnt;
		freqsum[cur][cnt] += c;
	} else {
		int &f = freq[cur][c];
		freqsum[cur][f] -= c;
		f += cnt;
		freqsum[cur][f] += c;
	}
}
void dfs (int cur, int p = -1) {
	for (int i : adj[cur]) if (i != p) dfs(i,cur);
	pt[cur] = big[cur] ? pt[big[cur]] : cur;
	ins(pt[cur],color[cur],1);
	for (int i : adj[cur]) if (i != p && i != big[cur])
		for (auto j : freq[pt[i]])
			ins(pt[cur],j.first,j.second);
	ans[cur] = freqsum[pt[cur]].rbegin()->second;
}
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",&color[i]);
	for (int i = 1; i < n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	get_sz(1);
	dfs(1);
	for (int i = 1; i <= n; i++) printf ("%lld ",ans[i]);
	printf ("\n");
	return 0;
}