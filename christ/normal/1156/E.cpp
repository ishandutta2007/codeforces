#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
const int MN = 3e5+3, MM = 1e6+3, BASE = 31, LOG = 20, MOD = 1e9+7;
pii a[MN];
int p[MN], sz[MN];
set<int> s[MN];
int find (int n) {return p[n] == n ? n : p[n] = find(p[n]);}
void merge (int a, int b) {
	a = find(a); b = find(b);
	if (sz[a] > sz[b]) swap(a,b);
	p[a] = b;
	sz[b] += sz[a];
	for (int i : s[a]) s[b].insert(i);
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i].first), a[i].second = i;
	sort(a+1,a+1+n); int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cur = a[i].second, v = a[i].first;
		s[cur].insert(v); p[cur] = cur; sz[cur] = 1;
		int lc = find(cur-1), rc = find(cur+1);
		if (sz[lc] < sz[rc]) {
			for (int i : s[lc]) ans += s[rc].count(v-i);
		} else {
			for (int i : s[rc]) ans += s[lc].count(v-i);
		}
		if (lc) merge(cur,lc);
		if (rc) merge(cur,rc);
	}
	printf ("%d\n",ans);
	return 0;
}