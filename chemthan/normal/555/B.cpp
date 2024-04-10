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
ll l[maxn];
ll r[maxn];
vector<pair<pl, ll> > v;
multiset<pl> ms;

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%I64d%I64d", l + i, r + i);
		if (i) v.push_back(pair<pl, ll>(pl(r[i] - l[i - 1], l[i] - r[i - 1]), i - 1));
	}
	ms.insert(pl(0, 0)); ms.insert(pl(_I64_MAX, _I64_MAX));
	FOR(i, 0, m) {ll a; scanf("%I64d", &a); ms.insert(pl(a, i));}
	sort(v.begin(), v.end());
	int ans[maxn];
	FOR(i, 0, n - 1) {
		multiset<pl>::iterator it = ms.lower_bound(pl(v[i].first.second - 1, _I64_MAX));
		if (it->first > v[i].first.first) {printf("No"); return;}
		ans[v[i].second] = it->second + 1;
		ms.erase(*it);
	}
	printf("Yes\n");
	FOR(i, 0, n - 1) printf("%d ", ans[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}