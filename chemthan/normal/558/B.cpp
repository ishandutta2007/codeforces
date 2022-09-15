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
int cnt[10 * maxn];
int f[10 * maxn];
int g[10 * maxn];

void solve() {
	ms(cnt, 0); ms(f, -1);
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		cnt[a[i]]++;
		if (f[a[i]] == -1) f[a[i]] = i;
		g[a[i]] = i;
	}
	int dmax = INT_MIN, ans;
	FOR(i, 0, 10 * maxn)
		if (dmax < cnt[i]) {dmax = cnt[i]; ans = i;}
		else if (dmax == cnt[i] && g[i] - f[i] < g[ans] - f[ans]) ans = i;
		printf("%d %d", f[ans] + 1, g[ans] + 1);
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