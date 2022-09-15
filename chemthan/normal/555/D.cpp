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
int n, m;
vll v;
int rev[maxn];
int ans;

void run(int cur, ll len, int pos = 0) {
	if (len == 0) ans = cur;
	else if (!pos) {
		int next = upper_bound(v.begin(), v.end(), pl(v[cur].first + len, _I64_MAX)) - v.begin(); next--;
		if (next > cur) {
			ll d = v[next].first - v[cur].first;
			len %= 2 * d;
			if (len >= d) run(next, len - d, 1); else run(cur, len);
		}
		else {
			next = upper_bound(v.begin(), v.end(), pl(v[cur].first - len, _I64_MIN)) - v.begin();
			if (next < cur) {
				ll d = v[cur].first - v[next].first;
				len %= 2 * d;
				if (len >= d) run(next, len - d); else run(cur, len, 1);
			}
			else ans = cur;
		}
	}
	else {
		int next = upper_bound(v.begin(), v.end(), pl(v[cur].first - len, _I64_MIN)) - v.begin();
		if (next < cur) {
			ll d = v[cur].first - v[next].first;
			len %= 2 * d;
			if (len >= d) run(next, len - d); else run(cur, len, 1);
		}
		else {
			next = upper_bound(v.begin(), v.end(), pl(v[cur].first + len, _I64_MAX)) - v.begin(); next--;
			if (next > cur) {
				ll d = v[next].first - v[cur].first;
				len %= 2 * d;
				if (len >= d) run(next, len - d, 1); else run(cur, len);
			}
			else ans = cur;
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	int x; FOR(i, 0, n) {scanf("%d", &x); v.push_back(pl(x, i));}
	sort(v.begin(), v.end());
	FOR(i, 0, n) rev[v[i].second] = i;
	int a, l;
	while (m--) {
		scanf("%d%d", &a, &l); a--;
		run(0, l + v[rev[a]].first - v[0].first);
		printf("%d\n", v[ans].second + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}