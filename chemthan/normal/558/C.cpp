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
int c[maxn];
int d[maxn];

void solve() {
	ms(c, 0); ms(d, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n) {
		int cnt1 = 0;
		while (a[i]) {
			int cnt2 = 0, cnt3 = 0;
			while (a[i] % 2 == 0) {cnt3++; a[i] >>= 1;}
			int k = a[i];
			while (k < maxn) {
				c[k]++;
				d[k] += cnt1 + abs(cnt2 - cnt3);
				k <<= 1;
				cnt2++;
			}
			a[i] >>= 1;
			cnt1 += cnt3 + 1;
		}
	}
	int ans = INT_MAX;
	FOR(i, 0, maxn) if (c[i] == n) ans = min(ans, d[i]);
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