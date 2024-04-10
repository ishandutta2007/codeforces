#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E2+8;

_ tc, n, m, cnt, p[maxn][maxn];
map<str, _> mp;
str a[maxn], b[maxn];
bitset<maxn> v;
v_ g;
vector<char> d = {'\0', ' ', '?', '.', ',', '!'};

void retrv(_ x, _ y);
str read(bool ig, char utl = '\n');
int main() {

	scanf("%lld", &tc);
	for(; tc--; ) {
		mp.clear();
		memset(p, ~0, sizeof p);
		g.clear();
		cnt = 0;
		scanf("%lld", &n);
		for(_ i = 1; i <= n; ++i) {
			b[i] = read(true, i == n ? '\n' : ' ');
//			printf("read name %s\n", b[i].c_str());
			mp[b[i]] = ++cnt;
		}
		scanf("%lld", &m);
		p[0][0] = 0;
		for(_ i = 1; i <= m; ++i) {
			str nm = read(true, ':');
//			printf("read query at %lld, name is %s\n", i, nm.c_str());
			a[i] = read(false);
			str c = '\0'+a[i]+'\0';
			v.reset();
			for(_ j = 1; j <= n; ++j) for(char x : d) for(char y : d) if(c.find(x+b[j]+y) != string::npos) v.set(j);
			if(nm == "?") {
//				printf("query %lld is a wildcard\n", i);
				for(_ j = 1; j <= n; ++j) if(!v.test(j)) for(_ k = 0; k <= n; ++k) if(k != j && ~p[i-1][k]) {
					p[i][j] = k;
//					printf("p[%lld][%lld] is %lld\n", j, k, p[j][k]);
				}
			} else {
				_ t = mp[nm];
				if(v[t]) continue;
				for(_ j = 0; j <= n; ++j) if(t != j && ~p[i-1][j]) p[i][t] = j;
			}
		}
		_ t = -1;
		for(_ i = 1; i <= n; ++i) if(~p[m][i]) t = i;
		if(!~t) puts("Impossible");
		else {
			retrv(m, t);
			reverse(g.begin(), g.end());
			for(_ i = 1; i <= m; ++i) printf("%s:%s\n", b[g[i-1]].c_str(), a[i].c_str());
		}
	}

	return 0;
}

str read(bool ig, char utl) {
	str rv;
	char ch = getchar();
	if(ig) for(; ch == '\n' || ch == ' '; ) ch = getchar();
	for(; ch != utl; ch = getchar()) rv += ch;
	return rv;
}

void retrv(_ x, _ y) {
	if(!x) return;
	g.push_back(y);
	retrv(x-1, p[x][y]);
	return;
}