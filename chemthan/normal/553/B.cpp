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

ll n, k;
ll fib[100];

void solve() {
	scanf("%I64d%I64d", &n, &k);
	fib[0] = fib[1] = 1;
	FOR(i, 0, n) fib[i + 2] = fib[i + 1] + fib[i];
	vi ans;
	FORd(i, n, 1) if (k > fib[i]) {ans.push_back(n - i); k -= fib[i];}
	int l = 0;
	FOR(i, 1, n + 1) if (l < sz(ans) && ans[l] == i) {printf("%d %d ", i + 1, i); l++; i++;} else printf("%d ", i);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}