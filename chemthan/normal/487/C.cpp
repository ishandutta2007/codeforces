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

const int maxn = 100010;
int n;
bool flag[maxn];
vi dvs;
vii fac;

bool isprime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

int ex(int u, int k) {
	if (k == 0) return 1;
	if (k % 2 == 1) return 1LL * u * ex(u, k - 1) % n;
	int t = ex(u, k >> 1);
	return 1LL * t * t % n;
}

void run(int pos, int val) {
	if (!flag[val]) {flag[val] = 1; dvs.push_back(val);}
	if (pos == sz(fac)) return;
	int pw = 1;
	FOR(i, 0, fac[pos].second + 1) {
		run(pos + 1, val * pw);
		pw *= fac[pos].first;
	}
}

void build() {
	int k = n - 1;
	for (int i = 2; i * i <= k; i++) {
		if (k % i != 0) continue;
		int cnt = 0; while (k % i == 0) {cnt++; k /= i;}
		fac.push_back(make_pair(i, cnt));
	}
	if (k > 1) fac.push_back(make_pair(k, 1));
	ms(flag, 0); flag[1] = flag[n - 1] = 1; run(0, 1); sort(dvs.begin(), dvs.end());
}

void solve() {
	scanf("%d", &n);
	if (n == 1) {printf("YES\n1"); return;}
	if (n == 4) {printf("YES\n1 3 2 4"); return;}
	if (!isprime(n)) {printf("NO"); return;}
	//printf("YES\n1\n");
	//FOR(i, 2, n) printf("%d\n", 1LL * i * ex(i - 1, n - 2) % n);
	//printf("%d", n);
	build();
	int proot = 2;
	FOR(i, 2, n - 1) {
		bool flag = true;
		FOR(j, 0, sz(dvs)) {
			if (ex(i, dvs[j]) == 1) {flag = false; break;}
		}
		if (flag) {proot = i; break;}
	}
	printf("YES\n1\n");
	FOR(i, 1, n - 1) if (i % 2 == 1) printf("%d\n", ex(proot, i)); else printf("%d\n", ex(proot, n - i - 1));
	printf("%d", n);
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