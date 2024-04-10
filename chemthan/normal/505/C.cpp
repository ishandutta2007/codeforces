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

const int maxn = 30010;
const int maxd = 500;
int n, d;
int trea[maxn];
int f[maxn][maxd];

int cal(int pos, int l) {
	int &res = f[pos][l - d + 250];
	if (res != -1) return res;
	res = 0;
	if (pos + l < maxn) res = max(res, cal(pos + l, l) + trea[pos + l]);
	if (pos + l + 1 < maxn) res = max(res, cal(pos + l + 1, l + 1) + trea[pos + l + 1]);
	if (l > 1 && pos + l - 1 < maxn) res = max(res, cal(pos + l - 1, l - 1) + trea[pos + l - 1]);
	return res;
}

void solve() {
	ms(trea, 0); ms(f, -1);
	scanf("%d%d", &n, &d);
	FOR(i, 0, n) {int p; scanf("%d", &p); trea[p]++;}
	printf("%d", cal(d, d) + trea[d]);
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