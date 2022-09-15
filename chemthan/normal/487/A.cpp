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

int h1, a1, d1;
int h2, a2, d2;
int ph, pa, pd;

int check(int x, int y) {
	int H1 = h1;
	int H2 = h2;
	int A1 = a1 + x;
	int A2 = a2 - y;
	if (A1 <= 0) return 100000;
	if (A2 <= 0) return 0;
	int l = 0, r = 100000;
	while (l < r) {
		int mid = (l + r) >> 1;
		if ((H1 + mid + A2 - 1) / A2 <= (H2 + A1 - 1) / A1) l = mid + 1; else r = mid;
	}
	return l;
}

void solve() {
	scanf("%d%d%d%d%d%d", &h1, &a1, &d1, &h2, &a2, &d2);
	a1 -= d2; a2 -= d1;
	scanf("%d%d%d", &ph, &pa, &pd);
	int ans = INT_MAX;
	int t = min(a2, 110) + 1; if (t <= 0) t = 1;
	FOR(i, 0, 200) FOR(j, 0, 200) ans = min(ans, ph * check(i, j) + pa * i + pd * j);
	printf("%d", ans);
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