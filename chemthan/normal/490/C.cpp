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
char s[maxn];
int a, b;
int f[maxn];
int g[maxn];

void solve() {
	scanf("%s%d%d", s, &a, &b);
	int len = strlen(s);
	FOR(i, 0, len) {
		if (!i) f[i] = (s[i] - '0') % a;
		else f[i] = (f[i - 1] * 10 + s[i] - '0') % a;
	}
	int pw = 1;
	FORd(i, len, 0) {
		if (i == len - 1) g[i] = (s[i] - '0') % b;
		else g[i] = (pw * (s[i] - '0') + g[i + 1]) % b;
		pw = (pw * 10) % b;
	}
	FOR(i, 1, len) {
		if (s[i] != '0') {
			if (f[i - 1] == 0 && g[i] == 0) {printf("YES\n"); int tmp = s[i]; s[i] = 0; printf("%s\n", s); s[i] = tmp; printf("%s", s + i); return;}
		}
	}
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