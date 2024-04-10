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
const int maxc = 1000010;
int n;
int a[maxn];
int b[maxc];
int f[maxc];
vi v;

void solve() {
	ms(f, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d", a + i); if (b[a[i]]) continue; v.push_back(a[i]); b[a[i]] = a[i];}
	FOR(i, 1, maxc) f[i] = max(f[i - 1], b[i]);
	int ans = 0;
	FOR(i, 0, sz(v)) {
		for (int k = 1; k * v[i] < maxc; k++) {
			int l = min(maxc, (k + 1) * v[i]) - 1;
			if (f[l] >= k * v[i]) ans = max(ans, f[l] - k * v[i]);
		}
	}
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