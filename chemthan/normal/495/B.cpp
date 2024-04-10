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

int a, b;
vii v;
bool flag[1024];
int ans;

void run(int pos, int k) {
	if (pos == sz(v)) return;
	FOR(i, 0, v[pos].second + 1) {
		if (i && k > b) ans++;
		run(pos + 1, k);
		k *= v[pos].first;
	}
}

void solve() {
	scanf("%d%d", &a, &b);
	if (a == b) {printf("infinity"); return;}
	if (a < b) {printf("0"); return;}
	int d = a - b;
	for (int i = 2; i * i <= d; i++) {
		if (d % i != 0) continue;
		int cnt = 0; while (d % i == 0) {cnt++; d /= i;}
		v.push_back(make_pair(i, cnt));
	}
	if (d > 1) v.push_back(make_pair(d, 1));
	ans = 0; if (b == 0) ans++;
	run(0, 1); printf("%d", ans);
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