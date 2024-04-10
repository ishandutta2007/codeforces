#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
const int maxc = 26;
int n;
string name[maxn];
string pseu[maxn];
vi v[2][8 * maxn];
int q;
vii ans;

int ctries = 1;
int node[8 * maxn][maxc];
int d[8 * maxn];
void init() {
	ms(node, 0); ms(d, 0);
}
void add(string s, int t, int idx) {
	int k = 0;
	FOR(i, 0, s.length()) {
		if (!node[k][s[i] - 'a']) {node[k][s[i] - 'a'] = ctries++; d[node[k][s[i] - 'a']] = d[k] + 1;}
		k = node[k][s[i] - 'a'];
	}
	v[t][k].push_back(idx);
}
void match(int k, int p) {
	FOR(i, 0, maxc) if (node[k][i]) match(node[k][i], k);
	while (sz(v[0][k]) && sz(v[1][k])) {
		q += d[k];
		ans.push_back(make_pair(v[0][k].back(), v[1][k].back()));
		v[0][k].pop_back(); v[1][k].pop_back();
	}
	if (p != -1) {
		while (sz(v[0][k])) {v[0][p].push_back(v[0][k].back()); v[0][k].pop_back();}
		while (sz(v[1][k])) {v[1][p].push_back(v[1][k].back()); v[1][k].pop_back();}
	}
}

void solve() {
	scanf("%d", &n);
	init();
	FOR(i, 0, n) {
		cin>>name[i];
		add(name[i], 0, i);
	}
	FOR(i, 0, n) {
		cin>>pseu[i];
		add(pseu[i], 1, i);
	}
	q = 0; match(0, -1);
	printf("%d\n", q);
	FOR(i, 0, sz(ans)) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}