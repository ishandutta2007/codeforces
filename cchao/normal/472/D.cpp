#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

typedef pair<int, pii> pp;
pp p[2010 * 2010];
int n, a[2010][2010], pa[2010], d[2010][2010]={};
int f(int x) { return x == pa[x] ? x : pa[x] = f(pa[x]); }
vector<pii> g[2010];

bool dfs(int x, int fa, int dis, int ans[2010], int cmp[2010]) {
	ans[x] = dis;
	if(ans[x] != cmp[x]) return false;
	rep(i, g[x].size())	{
		int y = g[x][i].first;
		int w = g[x][i].second;
		if(y != fa) if(!dfs(y, x, dis + w, ans, cmp)) return false;
	}
	return true;
}

int main() {
	ri(n); rep(i,n) ria(a[i],n);
	rep(i, n) rep(j, n) {
		if(i == j) {
			if(a[i][j]) {
				puts("NO");
				return 0;
			}
		}
		else {
			if(!a[i][j] || a[i][j] != a[j][i]) {
				puts("NO");
				return 0;
			}
		}
	}
	int sz = 0;
	rep(i, n) rep(j, i) p[sz++] = pp(a[i][j], pii(j, i));
	sort(p, p + sz);
	rep(i, n) pa[i] = i;
	rep(i, sz) {
		int w = p[i].first;
		int aa = p[i].second.first, bb = p[i].second.second;
		int fa = f(aa), fb = f(bb);
		if(fa != fb) {
			pa[fa] = fb;
			g[aa].push_back(pii(bb,w));
			g[bb].push_back(pii(aa,w));
		}
	}
	rep(i, n) if(!dfs(i, -1, 0, d[i], a[i])) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;

}