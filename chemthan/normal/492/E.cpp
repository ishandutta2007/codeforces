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

const int maxn = 1000010;
int n, m, dx, dy;
int x[maxn];
int y[maxn];
int r1[maxn];
int r2[maxn];
int cnt[2 * maxn];

void solve() {
	ms(cnt, 0);
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	int tmp1 = 0, tmp2 = 0;
	FOR(i, 0, n) {
		r1[tmp1] = r2[tmp2] = i;
		tmp1 = (tmp1 + dx) % n;
		tmp2 = (tmp2 + dy) % n;
	}
	FOR(i, 0, m) {
		scanf("%d%d", x + i, y + i);
		cnt[(r1[x[i]] - r2[y[i]] + n) % n]++;
	}
	int dmax = 0, ans;
	FOR(i, 0, 2 * n) if (dmax < cnt[i]) {dmax = cnt[i]; ans = i;}
	FOR(i, 0, n) if ((r1[x[i]] - r2[y[i]] + n) % n == ans) {printf("%d %d", x[i], y[i]); return;}
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