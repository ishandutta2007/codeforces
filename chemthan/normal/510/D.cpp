#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 310;
int n;
int l[nmax];
int c[nmax];
ll ans;

void run(int k) {
	vi p;
	int q = l[k];
	for (int i = 2; i * i <= q; i++) if (q % i == 0) {p.push_back(i); while (q % i == 0) q /= i;}
	if (q > 1) p.push_back(q);
	if (sz(p) == 0) {ans = MIN(ans, c[k]); return;}
	int mask[nmax]; ms(mask, 0);
	FOR(i, 0, n) FOR(j, 0, sz(p)) if (l[i] % p[j] != 0) mask[i] |= 1 << j;
	ll dp[1024];
	FOR(i, 0, 1 << 10) dp[i] = INT_MAX;
	dp[0] = 0;
	FOR(i, 1, 1 << sz(p)) FOR(j, 0, n) dp[i] = MIN(dp[i], 0LL + dp[i & (i ^ mask[j])] + c[j]);
	ans = MIN(ans, dp[(1 << sz(p)) - 1] + c[k]);
}

void solve() {
	cin>>n;
	FOR(i, 0, n) cin>>l[i];
	FOR(i, 0, n) cin>>c[i];
	ans = INT_MAX;
	FOR(i, 0, n) run(i);
	if (ans == INT_MAX) ans = -1;
	cout<<ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}