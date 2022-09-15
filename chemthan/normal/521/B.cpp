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
const int mod = 1000000009;
int m;
int x[maxn];
int y[maxn];
vi v;
set<int> st;
map<pi, int> mp;

void update(int x, int y) {
	if (!mp[make_pair(x, y)]) return;
	int cnt = 0, idx;
	FOR(i, x - 1, x + 2) {
		int k = mp[make_pair(i, y - 1)] - 1;
		if (k >= 0) {
			cnt++;
			idx = k;
		}
	}
	if (cnt == 1) st.erase(idx);
}

void takeout(int k) {
	mp[make_pair(x[k], y[k])] = 0;
	FOR(i, x[k] - 1, x[k] + 2) update(i, y[k] + 1);
	FOR(i, x[k] - 1, x[k] + 2) {
		int l = mp[make_pair(i, y[k] - 1)] - 1;
		if (l >= 0) st.insert(l);
	}
	FOR(i, x[k] - 2, x[k] + 3) update(i, y[k]);
}

void solve() {
	scanf("%d", &m);
	FOR(i, 0, m) st.insert(i);
	FOR(i, 0, m) {scanf("%d%d", x + i, y + i); mp[make_pair(x[i], y[i])] = i + 1;}
	FOR(i, 0, m) update(x[i], y[i]);
	int k = 0;
	while (!st.empty()) {
		set<int>::iterator it;
		if (k++ % 2 == 0) {it = st.end(); it--;} else it = st.begin();
		v.push_back(*it);
		takeout(*it);
		st.erase(*it);
	}
	ll ans = 0, po = 1;
	while (!v.empty()) {
		ans = (ans + po * v.back()) % mod;
		v.pop_back();
		po = po * m % mod;
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