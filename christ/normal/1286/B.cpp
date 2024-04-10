#include<bits/stdc++.h>
using namespace std;
const int MN = 2e3+2, MOD = 1e9+7, REEE = 100;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
vector<int> adj[MN];
int c[MN];
int a[MN];
int n;
int p[MN];
int order[MN], st[MN], ed[MN], ree = 0;
int o[MN];
int hmm = 0;
bool fail = 0;
void dfs (int cur) {
	int lb = 1, ub = 1e9;
	int temp = cur;
	while (p[temp]) {
		temp = p[temp];
		if (c[temp] < c[cur]+1) lb = max(lb,a[temp]);
		else ub = min(ub,a[temp]);
	}
	a[cur] = lb+ub>>1;
	temp = cur;
	while (p[temp]) {
		temp = p[temp];
		if (a[cur] < a[temp]) --c[temp];
	}
	for (int i : adj[cur]) dfs(i);
}
void getorder (int cur) {
	st[cur] = ++ree;
	order[ree] = cur;
	for (int i : adj[cur]) getorder(i);
	ed[cur] = ree;
}
int main () {
	int root=-1;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d %d",&p[i],&o[i]); c[i] = o[i];
		if (p[i]) adj[p[i]].push_back(i);
		else root = i;
	}
	getorder(root);
	dfs(root);
	for (int cur = 1; cur <= n; cur++) {
		int cnt = 0;
		for (int i = st[cur]+1; i <= ed[cur]; i++) {
			if (a[order[i]] < a[cur]) ++cnt;
		}
		if (cnt != o[cur]) {
			return 0 * printf ("NO\n");
		}
	}
	printf ("YES\n");
	for (int i = 1; i <= n; i++) printf ("%d ",a[i]);
	printf ("\n");
	return 0;
}