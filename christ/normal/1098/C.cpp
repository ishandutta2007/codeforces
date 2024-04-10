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
const int MN = 1e5+5, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1, SQRT = 315;
int p[MN], depth[MN], deg[MN];
ll get (int n, int att) {
	int left = n; ll ret = 0;
	for (ll cur = 1,idx=1;left;cur *=att,++idx) {
		ret += min(cur,(ll)left) * idx;
		left -= min(cur,(ll)left);
	}
	return ret;
}
int main () {
	int n; ll s,cur = 1;
	scanf ("%d %lld",&n,&s);
	if (s > (ll)n*(n+1)/2|| s < 2*n-1) return !printf ("No\n");
	printf ("Yes\n");
	int low = 1, high = n, mid, ans = 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (get(n,mid) > s) low = (ans = mid) + 1;
		else high = mid - 1;
	}
	depth[1] = 1; set<pii> togo; set<pii> leaf;
	for (int i = 2; i <= n; i++) {
		cur += (depth[i] = depth[p[i] = (i + ans - 2) / ans] + 1);
		++deg[p[i]];
	}
	for (int i = 1; i <= n; i++) {
		togo.emplace(depth[i],i);
		if (!deg[i]) leaf.emplace(depth[i],i);
	}
	while (cur > s) {
		int take = leaf.rbegin()->second, go = togo.begin()->second;
		assert(depth[take] > depth[go]);
		if (depth[take] - depth[go] - 1 >= cur - s) { //final stretch
			bool succ = 0;
			for (pii pp : togo) if (depth[take] - depth[pp.second] - 1 == cur - s) {
				p[take] = pp.second; succ = 1; cur = s;
				break;
			}
			assert(succ);
		} else { //stick take to go
			leaf.erase(prev(leaf.end())); togo.erase({depth[take],take}); cur -= depth[take] - depth[go] - 1;
			if (!(--deg[p[take]])) leaf.emplace(depth[p[take]],p[take]);
			if (deg[p[take]] == ans) togo.emplace(depth[p[take]],p[take]);
			if (++deg[go] > ans) togo.erase(togo.begin());
			p[take] = go; togo.insert({depth[take] = depth[go] + 1,take});
		}
	}
	ll check = 0;
	for (int i = 1; i <= n; i++) check += (depth[i] = depth[p[i]] + 1);
	assert(check == s);
	for (int i = 2; i <= n; i++) printf ("%d ",p[i]);
	printf ("\n");
	return 0;
}