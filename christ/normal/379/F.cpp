#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
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
const int MN = 1e6+3, BASE = 31, LOG = 20, MOD = 1e9+7;
int p[MN][LOG], depth[MN];
int dist (int a, int b) {
	int ret = depth[a] + depth[b];
	if (depth[a] < depth[b]) swap(a,b);
	for (int i = LOG-1; i >= 0; i--)
		if (depth[p[a][i]] >= depth[b])
			a = p[a][i];
	if (a == b) return ret - (depth[a] << 1);
	for (int i = LOG-1; i >= 0; i--)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	return ret-(depth[p[a][0]]<<1);
}
int main() {
	depth[2] = depth[3] = depth[4] = (depth[1] = (depth[0] = -1) + 1) + 1;
	p[2][0] = p[3][0] = p[4][0] = 1;
	int q, st = 2, ed = 3, dia = 2;
	scanf ("%d",&q); int cur = 4;
	while (q--) {
		int a;
		scanf ("%d",&a);
		p[cur+1][0] = p[cur+2][0] = a;
		for (int i = 1; i < LOG; i++)
			if (p[cur+1][i-1])
				p[cur+1][i] = p[cur+2][i] = p[p[cur+1][i-1]][i-1];
			else break;
		depth[cur+1] = depth[cur+2] = depth[a] + 1;
		int dst = dist(st,cur+1), ded = dist(ed,cur+1);
		if (dst >= ded && dst > dia) {
			dia = dst;
			ed = cur+1;
		} else if (ded > dst && ded > dia) {
			dia = ded;
			st = cur+1;
		}
		cur += 2;
		printf ("%d\n",dia);
	}
	return 0;
}