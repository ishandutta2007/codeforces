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

const int maxn = 5010;
int n, T;
int p[maxn];
int t[maxn];
double f[maxn][maxn];
double g[maxn];
double h[maxn];

void solve() {
	ms(f, 0); ms(g, 0); ms(h, 0);
	scanf("%d%d", &n, &T);
	FOR(i, 0, n) scanf("%d%d", p + i, t + i);
	FORd(pos, n, 0) {
		double alpha = 1.0 * p[pos] / 100;
		g[0] = 1; h[0] = alpha;
		FOR(k, 1, T - pos + 1) {
			g[k] = g[k - 1] * (1.0 - alpha);
			h[k] = h[k - 1] * (1.0 - alpha) + alpha * (1 + f[pos + 1][k]);
			int l = t[pos];
			if (k >= l) f[pos][k] = g[l - 1] * (1 + f[pos + 1][k - l]) + h[k - 1] - h[k - l] * g[l - 1]; else f[pos][k] = h[k - 1];
		}
	}
	cout<<fixed<<setprecision(9)<<f[0][T];
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