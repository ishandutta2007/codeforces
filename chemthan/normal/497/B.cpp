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

const int maxn = 100010;
int n;
int a[maxn];
int cnt[2][maxn];
vii ans;

int check(int t) {
	int res = 0, tmp = 0, pos = 0;
	while (pos < n) {
		int u = a[pos], v = u ^ 1, w;
		int k = lower_bound(cnt[u], cnt[u] + n, cnt[u][(pos + n) % (n + 1)] + t) - cnt[u];
		int l = lower_bound(cnt[v], cnt[v] + n, cnt[v][(pos + n) % (n + 1)] + t) - cnt[v];
		if (min(k, l) == n) return false;
		if (k < l) w = u; else w = v;
		if (w == a[n - 1]) {res++; tmp++;} else tmp--;
		pos = min(k, l) + 1;
	}
	if (tmp <= 0) return 0; else return res;
}

void solve() {
	ms(cnt, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d", a + i); a[i] %= 2;}
	FOR(i, 0, n) {FOR(k, 0, 2) cnt[k][i] = cnt[k][(i + n) % (n + 1)]; cnt[a[i]][i]++;}
	FOR(t, 1, n + 1) {int s = check(t); if (s) ans.push_back(make_pair(s, t));}
	sort(ans.begin(), ans.end());
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%d %d\n", ans[i].first, ans[i].second);
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