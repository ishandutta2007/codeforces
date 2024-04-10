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
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 105, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1;
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n,m;
		scanf ("%d %d",&n,&m);
		vector<vector<int>> adj(n+1); vector<ll> v(n+1);
		for (int i = 1; i <= n; i++) scanf ("%lld",&v[i]);
		while (m--) {
			int a,b;
			scanf ("%d %d",&a,&b);
			adj[b].push_back(a);
		}
		vector<pair<vector<int>,ll>> go;
		for (int i = 1; i <= n; i++) if (!adj[i].empty()) sort(all(adj[i])), go.push_back({adj[i],v[i]});
		sort(all(go));
		ll cur = 0, ret = 0;
		for (int i = 0; i < (int)go.size(); i++) {
			if (i && go[i].first == go[i-1].first) cur += go[i].second;
			else ret = __gcd(ret,cur), cur = go[i].second;
		}
		printf ("%lld\n",__gcd(ret,cur));
	}
	return 0;
}