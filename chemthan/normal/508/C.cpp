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

const int maxn = 310;
int m, t, r;
int w[maxn];
int end[maxn];

void solve() {
	ms(end, -1);
	scanf("%d%d%d", &m, &t, &r);
	FOR(i, 0, m) scanf("%d", w + i);
	ll ans = 0;
	int curtime = INT_MIN;
	FOR(i, 0, m) {
		int k = -1;
		FORd(j, r, 0) if (end[j] < w[i] + 1) {k = j; break;}
		if (k == -1) continue;
		if (w[i] - k - 1 <= curtime || k > t - 1) {printf("-1"); return;}
		FOR(j, 0, k + 1) {
			end[j] = w[i] - k + j + t;
			ans++;
		}
		curtime = w[i] - 1;
		sort(end, end + r);
	}
	printf("%I64d", ans);
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