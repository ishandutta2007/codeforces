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
int n, r, avg;
int a[maxn];
int b[maxn];
vii v;

void solve() {
	scanf("%d%d%d", &n, &r, &avg);
	ll cur = 0;
	FOR(i, 0, n) {scanf("%d%d", a + i, b + i); cur += a[i]; v.push_back(make_pair(b[i], a[i]));}
	sort(v.begin(), v.end());
	ll ans = 0;
	if (cur >= 1LL * avg * n) {printf("0"); return;}
	FOR(i, 0, n) {
		int k = r - v[i].second;
		if (1LL * avg * n - cur <= k) {printf("%I64d", ans + (1LL * avg * n - cur) * v[i].first); return;}
		else {ans += 1LL * k * v[i].first; cur += k;}
	}
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