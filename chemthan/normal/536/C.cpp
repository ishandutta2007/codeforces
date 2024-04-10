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
int s[maxn];
int r[maxn];
vii p, v1, v2;
map<pi, bool> mp;

ld intersect(pi p1, pi p2) {
	return 0.1 * p1.second * p2.second * (p2.first - p1.first) / p1.first / p2.first / (p1.second - p2.second);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d%d", s + i, r + i); p.push_back(make_pair(s[i], r[i]));}
	sort(p.begin(), p.end());
	FOR(i, 0, n) {while (sz(v1) && v1.back().second <= p[i].second) v1.pop_back(); v1.push_back(p[i]);}
	FOR(i, 0, sz(v1)) {while (sz(v2) > 1 && intersect(v2.back(), v1[i]) > intersect(v2[sz(v2) - 2], v2.back()) + 1e-9) v2.pop_back(); v2.push_back(v1[i]);}
	FOR(i, 0, sz(v2)) mp[v2[i]] = 1;
	FOR(i, 0, n) if (mp[make_pair(s[i], r[i])]) printf("%d ", i + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}