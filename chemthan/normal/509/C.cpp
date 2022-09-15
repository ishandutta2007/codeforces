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

const int maxn = 310;
int n;
int b[maxn];
vi prev;

void operator ++ (vi &v) {
	vi res;
	int m = 1;
	while (sz(v)) {
		if (m) {
			if (v.back() < 9) {res.push_back(v.back() + 1); m = 0;}
			else {
				res.push_back(0); m = 1;
				if (sz(v) == 1) res.push_back(1);
			}
		}
		else res.push_back(v.back());
		v.pop_back();
	}
	while (sz(res)) {v.push_back(res.back()); res.pop_back();}
}

vi create(int n) {
	vi res;
	if (n <= 0) return res;
	int k = n % 9;
	int l = n / 9;
	if (k) res.push_back(k);
	FOR(i, 0, l) res.push_back(9);
	return res;
}

int sum(vi a) {
	int res = 0;
	FOR(i, 0, sz(a)) res += a[i];
	return res;
}

int compare(vi a, vi b) {
	if (sz(a) > sz(b)) return 1;
	if (sz(b) > sz(a)) return -1;
	FOR(i, 0, sz(a)) if (a[i] > b[i]) return 1; else if (a[i] < b[i]) return -1;
	return 0;
}

void run(int k) {
	vi v = create(k);
	if (compare(v, prev) <= 0) {
		vi temp = prev;
		FORd(i, sz(prev), 0) {
			vi temp2 = temp;
			FOR(j, 0, 10) {
				++temp2;
				int p = k - sum(temp2); vi q = create(p);
				if (p >= 0 && sz(q) <= sz(prev) - i - 1) {
					vi ans;
					FOR(j, 0, sz(temp2)) ans.push_back(temp2[j]);
					FOR(j, 0, sz(prev) - i - sz(q) - 1) ans.push_back(0);
					FOR(j, 0, sz(q)) ans.push_back(q[j]);
					prev = ans;
					return;
				}
			}
			temp.pop_back();
		}
	}
	prev = v;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", b + i);
	FOR(i, 0, n) {
		run(b[i]);
		FOR(j, 0, sz(prev)) printf("%d", prev[j]); printf("\n");
	}
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