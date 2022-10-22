#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 3e5 + 111;
const int inf = 1e9 + 11;

int n, k;
char s[nax];

int a, b;

vector <int> v[nax];

struct uf {
	int p[nax];
	int e[nax];
	int res[nax][2];
	int siz[nax];
	
	void init() {
		for (int i = 1; i <= k; ++i) {
			p[i] = i;
			e[i] = 0;
			res[i][0] = 0;
			res[i][1] = 0;
			siz[i] = 1;
		}
	}
	
	int find(int x) {
		if (x == p[x]) return x;
		return find(p[x]);
	}
	
	int color(int u) {
		int y = e[u];
		while (p[u] != u) {
			u = p[u];
			y ^= e[u];
		}
		return y;
	}
	
	void unia(int x, int y, int k) {
		int xx = find(x);
		int yy = find(y);
		if (xx == yy) return;
		
		if (k == 0) {
			int k1 = color(x);
			int k2 = color(y);
			if (k1 == k2) {
				res[yy][0] += res[xx][0];
				res[yy][1] += res[xx][1];
			}
			else {
				res[yy][0] += res[xx][1];
				res[yy][1] += res[xx][0];
				e[xx] = 1;
			}
		}
		else {
			int k1 = color(x);
			int k2 = color(y);
			if (k1 == k2) {
				res[yy][0] += res[xx][1];
				res[yy][1] += res[xx][0];
				e[xx] = 1;
			}
			else {
				res[yy][0] += res[xx][0];
				res[yy][1] += res[xx][1];
			}
		}
		res[yy][0] = min(res[yy][0], inf);
		res[yy][1] = min(res[yy][1], inf);
		siz[yy] += siz[xx];
		p[xx] = yy;
	}
} ja;
				
int t[nax];	

int main() {
	scanf ("%d%d", &n, &k);
	ja.init();
	scanf ("%s", s + 1);
	for (int i = 1; i <= n; ++i) 
		t[i] = ((s[i] - '0') ^ 1);
	for (int i = 1; i <= k; ++i) {
		scanf ("%d", &a);
		while (a--) {
			scanf ("%d", &b);
			v[b].pb(i);
		}
	}
	
	for (int i = 1; i <= k; ++i) {
		ja.res[i][0] = 1;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (ss(v[i]) == 1) {
			int w = v[i][0];
			int rep = ja.find(w);
			ans -= min(ja.res[rep][0], ja.res[rep][1]);
			int col = ja.color(w);
			if (t[i] == 0) {
				ja.res[rep][col] = inf;
			}
			else {
				ja.res[rep][!col] = inf;
			}
			ans += min(ja.res[rep][0], ja.res[rep][1]);
		}
		else if (ss(v[i]) == 2) {
			a = v[i][0];
			b = v[i][1];
			if (ja.siz[ja.find(a)] > ja.siz[ja.find(b)]) swap(a, b);
			int A = ja.find(a);
			int B = ja.find(b);
			if (A == B) {
				printf ("%d\n", ans);
				continue;
			}
			ans -= min(ja.res[B][0], ja.res[B][1]);
			ans -= min(ja.res[A][0], ja.res[A][1]);
			ja.unia(a, b, t[i]);
			ans += min(ja.res[B][0], ja.res[B][1]);
		}
		printf ("%d\n", ans);
	}
		
				
		

	return 0;
}