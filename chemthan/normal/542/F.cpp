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

const int maxn = 1010;
int n, t;
vi v[maxn];
ll sum[maxn];
ll f[maxn][maxn];

void solve() {
	ms(f, 0);
	scanf("%d%d", &n, &t);
	FOR(i, 0, n) {int time, q; scanf("%d%d", &time, &q); v[t - time].push_back(q);}
	FOR(i, 0, t) sort(v[i].rbegin(), v[i].rend());
	FORd(i, t, 0) {
		FOR(j, 0, sz(v[i]) + 1) if (j) sum[j] = sum[j - 1] + v[i][j - 1]; else sum[j] = 0;
		FOR(j, 0, n + 1) FOR(k, 0, min(j, sz(v[i])) + 1) f[i][j] = max(f[i][j], f[i + 1][min(n, 2 * (j - k))] + sum[k]);
	}
	printf("%I64d", f[0][1]);
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