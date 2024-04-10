#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
vector<int> adj[MN];
int color[MN]; bool vis[MN];
void dfs (int cur, int p = -1) {
	vis[cur] = 1;
	for (int i : adj[cur]) {
		if (vis[i] && color[i] == color[cur]) {printf ("-1\n"); exit(0);}
		if (!vis[i]) {
			color[i] = color[cur] ^ 1;
			dfs(i);
		} 
	}
}
int main () { 
	int n,m;
	scanf ("%d %d",&n,&m);
	while (m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (!color[i]) ++cnt;
	printf ("%d\n",cnt);
	for (int i = 1; i <= n; i++) if (!color[i]) printf ("%d ",i);
	printf ("\n%d\n",n-cnt);
	for (int i = 1; i <= n; i++) if (color[i]) printf ("%d ",i);
	printf ("\n");
	return 0;
}