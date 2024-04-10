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

struct requirement {
	int x, y;
	char sig[10];
	requirement() {ms(sig, 0);}
	ll hash() {return 0LL + x + (1LL << 8) * y + (1LL << 16) * sig[0] + (1LL << 24) * sig[1];}
};

const int maxn = 110;
int n, k;
vector<requirement> req;
int a[maxn];
map<pair<pair<int, int>, vector<ll> >, ll> mp;

ll cal(int n, vector<requirement> req);

ll go1(int n, vector<requirement> req) {
	ms(a, 0x3f); a[0] = a[1] = 1;
	FOR(i, 0, sz(req)) {
		int u = req[i].x;
		int v = req[i].y;
		if (u < 2 || v < 2) {
			if (req[i].sig[0] == '<' && req[i].sig[1] != '=' && a[u] >= a[v]) return 0;
			if (req[i].sig[0] == '>' && req[i].sig[1] != '=' && a[u] <= a[v]) return 0;
			if (req[i].sig[0] == '=' && a[u] != a[v]) return 0;
			if (req[i].sig[0] == '<' && req[i].sig[1] == '=' && a[u] > a[v]) return 0;
			if (req[i].sig[0] == '>' && req[i].sig[1] == '=' && a[u] < a[v]) return 0;
		}
	}
	vector<requirement> tmp;
	FOR(i, 0, sz(req)) {
		int u = req[i].x;
		int v = req[i].y;
		if (u >= 2 && v >= 2) {
			requirement elm;
			elm.x = u - 2;
			elm.y = v - 2;
			elm.sig[0] = req[i].sig[0];
			elm.sig[1] = req[i].sig[1];
			tmp.push_back(elm);
		}
	}
	return cal(n - 1, tmp);
}

ll go2(int n, vector<requirement> req) {
	ms(a, 0x3f); a[0] = a[2 * n - 1] = 1;
	FOR(i, 0, sz(req)) {
		int u = req[i].x;
		int v = req[i].y;
		if (!u || !v || u == 2 * n - 1 || v == 2 * n - 1) {
			if (req[i].sig[0] == '<' && req[i].sig[1] != '=' && a[u] >= a[v]) return 0;
			if (req[i].sig[0] == '>' && req[i].sig[1] != '=' && a[u] <= a[v]) return 0;
			if (req[i].sig[0] == '=' && a[u] != a[v]) return 0;
			if (req[i].sig[0] == '<' && req[i].sig[1] == '=' && a[u] > a[v]) return 0;
			if (req[i].sig[0] == '>' && req[i].sig[1] == '=' && a[u] < a[v]) return 0;
		}
	}
	vector<requirement> tmp;
	FOR(i, 0, sz(req)) {
		int u = req[i].x;
		int v = req[i].y;
		if (u > 0 && v > 0 && u < 2 * n - 1 && v < 2 * n - 1) {
			requirement elm;
			elm.x = u - 1;
			elm.y = v - 1;
			elm.sig[0] = req[i].sig[0];
			elm.sig[1] = req[i].sig[1];
			tmp.push_back(elm);
		}
	}
	return cal(n - 1, tmp);
}

ll go3(int n, vector<requirement> req) {
	ms(a, 0x3f); a[2 * n - 2] = a[2 * n - 1] = 1;
	FOR(i, 0, sz(req)) {
		int u = req[i].x;
		int v = req[i].y;
		if (u >= 2 * n - 2 || v >= 2 * n - 2) {
			if (req[i].sig[0] == '<' && req[i].sig[1] != '=' && a[u] >= a[v]) return 0;
			if (req[i].sig[0] == '>' && req[i].sig[1] != '=' && a[u] <= a[v]) return 0;
			if (req[i].sig[0] == '=' && a[u] != a[v]) return 0;
			if (req[i].sig[0] == '<' && req[i].sig[1] == '=' && a[u] > a[v]) return 0;
			if (req[i].sig[0] == '>' && req[i].sig[1] == '=' && a[u] < a[v]) return 0;
		}
	}
	vector<requirement> tmp;
	FOR(i, 0, sz(req)) {
		int u = req[i].x;
		int v = req[i].y;
		if (u < 2 * n - 2 && v < 2 * n - 2) {
			requirement elm;
			elm.x = u;
			elm.y = v;
			elm.sig[0] = req[i].sig[0];
			elm.sig[1] = req[i].sig[1];
			tmp.push_back(elm);
		}
	}
	return cal(n - 1, tmp);
}

ll cal(int n, vector<requirement> req) {
	vector<ll> v; FOR(i, 0, sz(req)) v.push_back(req[i].hash());
	if (mp.count(make_pair(make_pair(n, k), v))) return mp[make_pair(make_pair(n, k), v)];
	if (n == 1) {
		FOR(i, 0, sz(req)) if (req[i].sig[0] != '=' && req[i].sig[1] != '=') return 0;
		return 1;
	}
	return mp[make_pair(make_pair(n, k), v)] = go1(n, req) + go2(n, req) + go3(n, req);
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, k) {
		requirement tmp;
		scanf("%d%s%d", &tmp.x, tmp.sig, &tmp.y); tmp.x--; tmp.y--;
		req.push_back(tmp);
	}
	printf("%I64d", cal(n, req));
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