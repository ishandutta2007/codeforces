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
int n, m;
ll a[maxn];
ll b[maxn];

void solve() {
	scanf("%d", &n); FOR(i, 0, n) scanf("%I64d", a + i);
	scanf("%d", &m); FOR(i, 0, m) scanf("%I64d", b + i);
	sort(a, a + n); sort(b, b + m);
	a[n] = _I64_MAX;
	int dmax = INT_MIN;
	int p1, p2;
	FOR(i, 0, n + 1) {
		int A = 2 * i + 3 * (n - i);
		int k = upper_bound(b, b + m, a[i] - 1) - b;
		int B = 2 * k + 3 * (m - k);
		if (dmax < A - B) {dmax = A - B; p1 = A; p2 = B;}
	}
	printf("%d:%d", p1, p2);
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