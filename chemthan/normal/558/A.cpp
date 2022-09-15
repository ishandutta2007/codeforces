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

const int maxn = 110;
int n;
int x[maxn];
int a[maxn];
vii v;

void solve() {
	scanf("%d", &n);
	int cnt1 = 0, cnt2 = 0;
	FOR(i, 0, n) {scanf("%d%d", x + i, a + i); v.push_back(make_pair(x[i], a[i])); if (x[i] < 0) cnt1++; else cnt2++;}
	sort(v.begin(), v.end());
	int k = min(cnt1, cnt2);
	ll ans = 0;
	int temp = k;
	if (cnt1 < cnt2) temp++;
	FOR(i, 0, n) {if (temp == 0) break; if (v[i].first > 0) {ans += v[i].second; temp--;}}
	temp = k;
	if (cnt1 > cnt2) temp++;
	FORd(i, n, 0) {if (temp == 0) break; if (v[i].first < 0) {ans += v[i].second; temp--;}}
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