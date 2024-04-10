#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MN = 2e5+3, MOD = 1e9+7;
int arr[MN], parity[2][MN], depth[MN], st[MN], ed[MN], ree;
vector<int> adj[MN];
void dfs (int cur, int p = -1) {
	st[cur] = ++ree;
	for (int i : adj[cur]) if (i != p) {
		depth[i] = depth[cur]^1;
		dfs(i,cur);
	}
	ed[cur] = ree;
}
void update (int *bit, int i, int v) {
	for(;i<MN;i+=i&-i)
		bit[i] += v;
}
int query (int *bit, int i) {
	int ret = 0;
	for (;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
int _main() {
	int n,q;
	scanf ("%d %d",&n,&q);
	for (int i = 1; i <= n; i++) scanf ("%d",&arr[i]);
	for (int i = 1; i < n; i++) {
		int a,b; scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1);
	while (q--) {
		int t,a,b;
		scanf ("%d %d",&t,&a);
		if (t == 1) {
			scanf ("%d",&b);
			update(parity[depth[a]],st[a],b); update(parity[depth[a]],ed[a]+1,-b);
			update(parity[!depth[a]],st[a],-b); update(parity[!depth[a]],ed[a]+1,b);
		} else {
			printf ("%d\n",arr[a]+query(parity[depth[a]],st[a]));
		}
	}
	return 0;
}
int main () {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		clock_t start = clock();
	#endif
	assert(!_main());
	#ifdef LOCAL
		printf ("Time elapsed: %.3f\n",(clock()-start)/double(CLOCKS_PER_SEC));
	#endif
	return 0;
}