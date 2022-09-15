#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
const int maxd = 30;
int n;
ll p[maxn];
ll l[maxn];
ll rm[maxn];
ll nx[maxn][maxd];
ll f[maxn][maxd];

ll fen[maxn];
void update(int p, ll val) {
	for (; p < maxn; p += p & -p) fen[p] = max(fen[p], val);
}
ll get(int p)
{
	ll res = 0;
	for (; p > 0; p -= p & -p) res = max(res, fen[p]);
	return res;
}

void solve() {
	ms(rm, 0); ms(f, 0); ms(fen, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%I64d%I64d", p + i, l + i);
	FORd(i, n, 0) {
		int k = upper_bound(p, p + n, p[i] + l[i]) - p;
		rm[i] = max(p[i] + l[i], get(k));
		nx[i][0] = upper_bound(p, p + n, rm[i]) - p;
		update(i + 1, rm[i]);
	}
	nx[n][0] = n;
	FOR(k, 1, maxd) {nx[n][k] = n; FOR(i, 0, n) nx[i][k] = nx[nx[i][k - 1]][k - 1];}
	FOR(i, 0, n) f[i][0] = max(0LL, p[nx[i][0]] - rm[i]);
	FOR(k, 1, maxd) FOR(i, 0, n) f[i][k] = f[i][k - 1] + f[nx[i][k - 1]][k - 1];
	int q; scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		ll ans = 0;
		FORd(k, maxd, 0) if (y >= nx[x][k]) {
			ans += f[x][k];
			x = nx[x][k];
		}
		printf("%I64d\n", ans);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}