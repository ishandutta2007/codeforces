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
int a[maxn];
bool ck[maxn];
int cnt1[maxn];
int cnt2[maxn];

int run() {
	int r = (n - 1) / 2 + 1; while (r > 0 && a[r - 1] == a[n - r]) r--;
	if (2 * r <= n - 1) {
		ms(ck, 0); ms(cnt1, 0); ms(cnt2, 0);
		FOR(i, 0, r) {cnt1[a[i]]++; cnt1[a[n - i - 1]]++;}
		int k = 0; FOR(i, 0, maxn) if (cnt1[i]) k++;
		int cnt = 0;
		FOR(i, 0, r) {
			cnt2[a[i]]++;
			if (!ck[a[i]] && 2 * cnt2[a[i]] >= cnt1[a[i]]) {ck[a[i]] = 1; cnt++;}
			if (cnt == k) return i;
		}
	}
	ms(ck, 0); ms(cnt1, 0); ms(cnt2, 0);
	FOR(i, 0, n) cnt1[a[i]]++;
	int nodd = 0; FOR(i, 0, maxn) if (cnt1[i] % 2 == 1) nodd++; if (nodd > 1) return -1;
	int k = 0; FOR(i, 0, maxn) if (cnt1[i]) k++;
	int cnt = 0;
	FOR(i, 0, n) {
		cnt2[a[i]]++;
		if (!ck[a[i]] && 2 * cnt2[a[i]] >= cnt1[a[i]]) {ck[a[i]] = 1; cnt++;}
		if (cnt == k) return i;
	}
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	int l = -1;
	while (2 * (l + 1) <= n - 1 && a[l + 1] == a[n - l - 2]) l++;
	if (l == (n - 1) / 2) {printf("%I64d", 1LL * n * (n + 1) / 2); return;} l++;
	int k = run(); if (k == -1) {printf("0"); return;}
	int pref = k - l + 1;
	reverse(a, a + n); k = run();
	int suff = k - l + 1;
	printf("%I64d", 1LL * (l + 1) * (2 * (n - 2 * l) + l - pref - suff + 1));
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