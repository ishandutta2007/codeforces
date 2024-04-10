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
int l[maxn];
int d[maxn];
int dd[210];

void solve() {
	ms(dd, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", l + i);
	FOR(i, 0, n) scanf("%d", d + i);
	vii v;
	FOR(i, 0, n) v.push_back(make_pair(l[i], d[i]));
	sort(v.begin(), v.end());
	vii pos;
	int cur;
	FOR(i, 0, n) {
		if (!i) cur = 0; else if (v[i].first > v[i - 1].first) {pos.push_back(make_pair(cur, i - cur)); cur = i;}
		if (i == n - 1) pos.push_back(make_pair(cur, n - cur));
	}
	int ans = INT_MAX;
	int k = 0;
	FOR(i, 0, sz(pos)) {
		while (k < pos[i].first) dd[v[k++].second]++;
		int s = 0;
		FOR(j, pos[i].first, pos[i].first + pos[i].second) s -= v[j].second;
		int m = pos[i].second - 1;
		FORd(j, 210, 0) if (m > dd[j]) {s -= dd[j] * j; m -= dd[j];} else {s -= m * j; break;}
		ans = min(ans, s);
	}
	FOR(i, 0, n) ans += d[i];
	printf("%d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}