#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
typedef unsigned long long ull;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int Maxn = 400005, ch = 233;
int n, m, nm;

int inline getid(char c) { return c == 'L' ? 0 : (c == 'T' ? 1 : (c == 'R' ? 2 : 3)); }
void inline shit() { puts("No solution"); exit(0); }

struct Graph_Zxbs {
	vector<int> nei[Maxn];
	bool lgl[Maxn];
	vector<int> tmp, ftmp;
	vector<vector<int> > hs;
	vector<pair<ull, int> > hsh;
	void inline addedge(int u, int v) {
		nei[u].pub(v); nei[v].pub(u);
	}
	void inline dfs(int now) {
		lgl[now] = 1;
		tmp.pub(now);
		parse(to, nei[now]) if (!lgl[to]) dfs(to);
	}
	void inline getZxbs(vector<int> &a) {
		int i = 0, j = 1, k = 0, n = SZ(a);
		while (i < n && j < n && k < n) {
			if (a[(i + k) % n] / nm == a[(j + k) % n] / nm) ++k;
			else {
				(a[(i + k) % n] / nm > a[(j + k) % n] / nm ? i : j) += k + 1;
				if (i == j) ++i;
				k = 0;
			}
		}
		if (i >= n || (j < n && a[i] > a[j])) i = j;
		vector<int> b;
		loop(j, n) b.pub(a[(i + j) % n]);
		a.swap(b);
	}
	ull inline gethash(const vector<int> &a) {
		ull res = 0;
		parse(it, a) res = res * ch + it / nm;
		return res;
	}
	void inline getHuan() {
		loop(i, 4 * nm) if (!lgl[i]) {
			tmp.clear(); dfs(i);
			if (SZ(tmp) == 1) continue;
			ftmp = tmp; reverse(all(ftmp));
			getZxbs(tmp); getZxbs(ftmp);
			loop(i, SZ(tmp)) if (tmp[i] / nm != ftmp[i] / nm) {
				if (tmp[i] > ftmp[i]) tmp.swap(ftmp);
				break;
			}
			hsh.emb(gethash(tmp), SZ(hs));
			hs.pub(tmp);
		}
		sort(all(hsh));
	}
} g1, g2;

int cnt[4][4];
int px[Maxn], py[Maxn];

int main() {
	scanf("%d%d", &n, &m); nm = max(n, m);
	loop(i, n + m) {
		char p1, p2; int x1, x2;
		scanf(" %c %c %d%d", &p1, &p2, &x1, &x2);
		--x1; --x2; int f1 = getid(p1), f2 = getid(p2);
		++cnt[f1][f2]; ++cnt[f2][f1];
		g1.addedge(f1 * nm + x1, f2 * nm + x2);
	}
	if (cnt[0][2] && cnt[1][3]) shit();
	if (cnt[0][3] != cnt[1][2] || cnt[0][1] != cnt[2][3]) shit();
	loop(i, n) g1.addedge(0 * nm + i, 2 * nm + i), g2.addedge(0 * nm + i, 2 * nm + i);
	loop(i, m) g1.addedge(1 * nm + i, 3 * nm + i), g2.addedge(1 * nm + i, 3 * nm + i);
	loop(i, cnt[0][1]) g2.addedge(0 * nm + i, 1 * nm + i);
	loop(i, cnt[2][3]) g2.addedge(2 * nm + (n - i - 1), 3 * nm + (m - i - 1));
	loop(i, cnt[0][3]) g2.addedge(0 * nm + (n - i - 1), 3 * nm + i);
	loop(i, cnt[1][2]) g2.addedge(1 * nm + (m - i - 1), 2 * nm + i);
	loop(i, cnt[0][2]) g2.addedge(0 * nm + cnt[0][1] + i, 2 * nm + cnt[1][2] + i);
	loop(i, cnt[1][3]) g2.addedge(1 * nm + cnt[0][1] + i, 3 * nm + cnt[0][3] + i);
	g1.getHuan(); g2.getHuan();
	if (SZ(g1.hs) != SZ(g2.hs)) shit();
	loop(i, SZ(g1.hs)) if (g1.hsh[i].first != g2.hsh[i].first) shit();
	loop(i, SZ(g1.hs)) {
		vector<int> &v1 = g1.hs[g1.hsh[i].second], &v2 = g2.hs[g2.hsh[i].second];
		loop(i, SZ(v1)) {
			if (v1[i] / nm == 0) px[v2[i] % nm] = v1[i] % nm; 
			if (v1[i] / nm == 1) py[v2[i] % nm] = v1[i] % nm; 
		}
	}
	loop(i, n) printf("%d%c", px[i] + 1, " \n"[i == n - 1]);
	loop(i, m) printf("%d%c", py[i] + 1, " \n"[i == m - 1]);
	return 0;
}