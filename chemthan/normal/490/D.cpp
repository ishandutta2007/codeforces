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

int a1, b1, a2, b2;
ll n;
int t[2];
int ar[2][2];
vl v;
map<ll, int> mp[2];
map<pi, bool> flag;

void run(int a, int b, int cnt, int k) {
	if (flag[make_pair(a, b)]) return; flag[make_pair(a, b)] = 1;
	if (!mp[k].count(1LL * a * b)) {v.push_back(1LL * a * b); mp[k][1LL * a * b] = cnt;} else mp[k][1LL * a * b] = min(mp[k][1LL * a * b], cnt);
	if (a % 2 == 0) run(a / 2, b, cnt + 1, k);
	if (a % 3 == 0) run(2LL * a / 3, b, cnt + 1, k);
	if (b % 2 == 0) run(a, b / 2, cnt + 1, k);
	if (b % 3 == 0) run(a, 2LL * b / 3, cnt + 1, k);
}

void run2(int a, int b, int cnt, int k) {
	if (flag[make_pair(a, b)]) return; flag[make_pair(a, b)] = 1;
	if (1LL * a * b == n && cnt == t[k]) {ar[k][0] = a; ar[k][1] = b; return;}
	if (a % 2 == 0) run2(a / 2, b, cnt + 1, k);
	if (a % 3 == 0) run2(2LL * a / 3, b, cnt + 1, k);
	if (b % 2 == 0) run2(a, b / 2, cnt + 1, k);
	if (b % 3 == 0) run2(a, 2LL * b / 3, cnt + 1, k);
}

void solve() {
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
	run(a1, b1, 0, 0); flag.clear();
	run(a2, b2, 0, 1); flag.clear();
	int ans = -1;
	FOR(i, 0, sz(v)) {
		ll k = v[i];
		if (mp[0].count(k) && mp[1].count(k)) {
			if (ans == -1 || ans > mp[0][k] + mp[1][k]) {ans = mp[0][k] + mp[1][k]; n = k; t[0] = mp[0][k]; t[1] = mp[1][k];}
		}
	}
	if (ans == -1) {printf("-1"); return;}
	run2(a1, b1, 0, 0); flag.clear();
	run2(a2, b2, 0, 1); flag.clear();
	printf("%d\n%d %d\n%d %d", ans, ar[0][0], ar[0][1], ar[1][0], ar[1][1]);
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