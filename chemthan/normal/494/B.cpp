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
const int mod = 1000000007;
char s[maxn];
char t[maxn];
int n, m;
int b[maxn];
bool flag[maxn];

void preprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && t[i] != t[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void search() {
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && s[i] != t[j]) j = b[j];
		i++; j++;
		if (j == m) {
			flag[i - j + m - 1] = 1;
			j = b[j];
		}
	}
}

ll f[maxn];
ll g[maxn];
ll h[maxn];

void solve() {
	ms(flag, 0); ms(f, 0); ms(g, 0); ms(h, 0);
	scanf("%s%s", s, t);
	n = strlen(s); m = strlen(t);
	preprocess();
	search();
	int prev = -1;
	FOR(i, 0, n) {
		f[i] = f[(i + n) % (n + 1)];
		if (flag[i]) {
			if (i >= m) {
				if (prev == -1) f[i] = (f[i] + g[i - m]) % mod;
				else if (i - m >= prev) f[i] = (f[i] + h[i - m] - h[(prev + n) % (n + 1)] + mod) % mod;
			}
			f[i] = (f[i] + i - m + 1 - prev) % mod;
			prev = i - m + 1;
		}
		g[i] = (g[(i + n) % (n + 1)] + f[i]) % mod;
		h[i] = (h[(i + n) % (n + 1)] + g[i]) % mod;
	}
	printf("%I64d", g[n - 1]);
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