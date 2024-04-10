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

int n, q;
set<int> sv, sh;
map<int, int> mp;

void solve() {
	scanf("%d%d", &n, &q);
	sv.insert(0); sv.insert(n + 1); sh.insert(0); sh.insert(n + 1);
	int x, y; char s[2];
	while (q--) {
		scanf("%d%d%s", &x, &y, s);
		if (mp[x]) {printf("0\n"); continue;}
		int k, l, m;
		set<int>::iterator it;
		if (s[0] == 'U') {
			it = sv.lower_bound(x); k = *it;
			it = sh.lower_bound(y); it--; l = *it;
			if (k < n + 1 - l) m = k - x + mp[k]; else m = y - l;
			sv.insert(x); printf("%d\n", m);
		} else {
			it = sh.lower_bound(y); k = *it;
			it = sv.lower_bound(x); it--; l = *it;
			if (k < n + 1 - l) m = k - y + mp[n + 1 - k]; else m = x - l;
			sh.insert(y); printf("%d\n", m);
		}
		mp[x] = m;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}