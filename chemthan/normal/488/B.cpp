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

int n;
int a[4];

bool check(int a[]) {
	sort(a, a + 4);
	if (a[0] + a[3] != a[1] + a[2] || a[0] * 3 != a[3]) return false;
	return true;
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	if (n == 0) {printf("YES\n%d\n%d\n%d\n%d", 1, 1, 3, 3); return;}
	else if (n == 1) {printf("YES\n%d\n%d\n%d", a[0] * 2, a[0] * 2, a[0] * 3); return;}
	else if (n == 2) {
		FOR(i, 1, 1510) FOR(j, 1, 1510) {
			int tmp[4]; tmp[0] = a[0]; tmp[1] = a[1]; tmp[2] = i; tmp[3] = j;
			if (check(tmp)) {printf("YES\n%d\n%d", i, j); return;}
		}
	}
	else if (n == 3) {
		FOR(i, 0, 1510) {
			int tmp[4]; tmp[0] = a[0]; tmp[1] = a[1]; tmp[2] = a[2]; tmp[3] = i;
			if (check(tmp)) {printf("YES\n%d", i); return;}
		}
	}
	else if (check(a)) {printf("YES"); return;}
	printf("NO");
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