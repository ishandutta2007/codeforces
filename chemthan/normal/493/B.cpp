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
int n;
vi p1, p2;

void solve() {
	scanf("%d", &n);
	ll point1 = 0, point2 = 0;
	int last;
	FOR(i, 0, n) {int a; scanf("%d", &a); if (a > 0) {point1 += a; last = 1; p1.push_back(a);} else {point2 -= a; last = 2; p2.push_back(-a);}}
	if (point1 > point2) {printf("first"); return;}
	if (point1 < point2) {printf("second"); return;}
	int k = min(sz(p1), sz(p2));
	FOR(i, 0, k) {
		if (p1[i] > p2[i]) {printf("first"); return;}
		if (p1[i] < p2[i]) {printf("second"); return;}
	}
	if (sz(p1) < sz(p2)) {printf("first"); return;}
	if (sz(p1) > sz(p2)) {printf("second"); return;}
	if (last == 1) printf("first"); else printf("second");
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