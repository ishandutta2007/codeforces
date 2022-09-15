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

const int maxn = 110;
int n;
int a[maxn][maxn];
int res[maxn][maxn];
int ans, cnt;

void solve() {
	ms(res, 0);
	scanf("%d", &n);
	char s[maxn];
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, n) a[i][j] = s[j] - '0';
	}
	FOR(k, 0, n) FOR(i, 0, n) FOR(j, i + 1, n) if (a[i][k] != a[j][k]) res[i][j] = res[j][i] = 1;
	ans = INT_MIN;
	FOR(i, 0, n) {cnt = 0; FOR(j, 0, n) if (!res[i][j]) cnt++; ans = max(ans, cnt);}
	printf("%d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}