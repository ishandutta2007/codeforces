#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
const int maxc = 26;
int n, k;
int f[maxn];
int g[maxn];
int h[maxn];

int ntrie = 1;
int node[maxn][maxc];
void add(string& s) {
	int k = 0;
	FOR(i, 0, sz(s)) {
		if (!~node[k][s[i] - 'a']) node[k][s[i] - 'a'] = ntrie++;
		k = node[k][s[i] - 'a'];
	}
}

void trace(int k) {
	int flag = 0;
	FOR(i, 0, maxc) if (~node[k][i]) {
		flag = 1;
		trace(node[k][i]);
		f[k] |= !f[node[k][i]];
		g[k] |= !g[node[k][i]];
	}
	if (!flag) {
		f[k] = 0;
		g[k] = 1;
	}
}

void solve() {
	ms(node, -1);
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		string s; cin>>s;
		add(s);
	}
	trace(0);
	if (!f[0]) {
		printf("Second");
	}
	else {
		if (g[0]) printf("First");
		else {
			if (k & 1) printf("First");
			else printf("Second");
		}
	}
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}