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

ll t, a, b;

int check(ll a, ll b) {
	ll tmp = 0;
	ll pw = 1;
	while (b) {
		tmp += (b % a) * pw;
		pw *= t;
		b /= a;
	}
	return tmp == a;
}

void solve() {
	scanf("%I64d%I64d%I64d", &t, &a, &b);
	if (t == 1 && a == 1 && b == 1) printf("inf");
	else {
		if (a == 1) {if (b == 1) printf("1"); else printf("0"); return;}
		if (a > b) {printf("0"); return;}
		ll tmp = b; while (tmp % a == 0) tmp /= a;
		int ans = tmp == 1;
		ans += check(a, b);
		printf("%d", ans);
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