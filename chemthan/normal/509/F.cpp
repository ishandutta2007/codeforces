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

const int maxn = 510;
const int mod = 1000000007;
int n;
int b[maxn];
int f[maxn][maxn];

ll cal(int l, int r) {
	if (f[l][r] >= 0) return f[l][r];
	if (l == r) return (f[l][r] = 1);
	else if (l > r) return (f[l][r] = 0);
	f[l][r] = cal(l + 1, r);
	FOR(i, l, r) f[l][r] = (f[l][r] + cal(l + 1, i) * cal(i, r) * (b[l + 1] < b[i + 1] ? 1 : 0)) % mod;
	return f[l][r];
}

void solve() {
	ms(f, -1);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", b + i);
	printf("%I64d", cal(0, n - 1));
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