#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E3+8;

_ tc, n, m, a[maxn], p[maxn];
struct tr {
	_ x, y, z;
} b[10][10], c[10][10][10], d[maxn];
vector<tr> g;

void recur(_ x);
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		memset(p, -1, sizeof p);
		memset(d, 0, sizeof d);
		scanf("%lld%lld", &n, &m);
		for(_ i = 1; i <= n; ++i) {
			for(_ j = 1; j <= m; ++j) {
				char ch;
				scanf(" %c", &ch);
				a[j] = ch^48;
				if(j > 1) b[a[j-1]][a[j]] = (tr){j-1, j, i};
				if(j > 2) c[a[j-2]][a[j-1]][a[j]] = (tr){j-2, j, i};
			}
		}
		for(_ i = 1; i <= m; ++i) {
			char ch;
			scanf(" %c", &ch);
			a[i] = ch^48;
		}
		p[0] = 0;
		for(_ i = 0; i <= m-1; ++i) if(~p[i]) {
			if(i+2 <= m && b[a[i+1]][a[i+2]].z) {
				p[i+2] = i;
				d[i+2] = b[a[i+1]][a[i+2]];
			}
			if(i+3 <= m && c[a[i+1]][a[i+2]][a[i+3]].z) {
				p[i+3] = i;
				d[i+3] = c[a[i+1]][a[i+2]][a[i+3]];
			}
		}

//		printf("%lld\n", a[1]);
//		exit(0);

		if(!~p[m]) {
			puts("-1");
			continue;
		}

		g.clear();
		recur(m);
		printf("%lld\n", (_)g.size());
		for(tr i : g) printf("%lld %lld %lld\n", i.x, i.y, i.z);
	}

	return 0;
}

void recur(_ x) {
	if(!x) return;
	recur(p[x]);
	g.push_back(d[x]);
	return;
}