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
int n;
map<int, int> mp;
map<int, int> rev;

int fen[maxn];
void add(int p, int val) {
	for (p++; p < maxn; p += p & -p) fen[p] += val;
}
int get(int p)
{
	int res = 0;
	for (; p > 0; p -= p & -p) res += fen[p];
	return res;
}

void solve() {
	scanf("%d", &n); int a, b;
	FOR(i, 0, n) {
		scanf("%d%d", &a, &b);
		int temp = mp[a];
		if (!mp[b]) mp[a] = b; else mp[a] = mp[b];
		if (!temp) mp[b] = a; else mp[b] = temp;
	}
	vii v; int k = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) v.push_back(make_pair(it->second, ++k));
	sort(v.begin(), v.end());
	FOR(i, 0, sz(v)) rev[v[i].first] = i;
	ll ans = 0;
	FOR(i, 0, sz(v)) {
		int k = v[i].second;
		ans += i - get(k);
		add(k, 1);
	}
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		int k = it->first;
		int l = it->second;
		ans += 0LL + abs(k - l) - abs(rev[k] - rev[l]);
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