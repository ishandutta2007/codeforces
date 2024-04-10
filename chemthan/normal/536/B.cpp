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

const int maxn = 1000010;
const int mod = 1000000007;
int n, m;
char p[maxn];
int nlen;
int y[maxn];
ll hash[maxn];
ll po[maxn];

bool check(int i) {
	return (hash[i - 1] * po[nlen - i] - hash[nlen - 1] + hash[nlen - i - 1] + mod) % mod == 0;
}

void solve() {
	scanf("%d%d%s", &n, &m, p);
	nlen = strlen(p);
	po[0] = 1;
	FOR(i, 0, nlen) {
		if (i) hash[i] = (hash[i - 1] + p[i] * po[i]) % mod; else hash[i] = p[i];
		po[i + 1] = po[i] * 257 % mod;
	}
	int cnt = 0;
	FOR(i, 0, m) {
		scanf("%d", y + i);
		if (i && y[i] - y[i - 1] < nlen && !check(nlen - y[i] + y[i - 1])) {printf("0"); return;}
		if (i && y[i] - y[i - 1] > nlen) {cnt += y[i] - y[i - 1] - nlen;}
	}
	if (m) cnt += n + y[0] - (y[m - 1] + nlen); else cnt = n;
	ll ans = 1;
	FOR(i, 0, cnt) ans = ans * 26 % mod;
	printf("%I64d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}