#ifndef ONLINE_JUDGE
#include <iostream>
#else
#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 100;
int n, m;
string a[nmax];
bool vis[nmax][nmax];
int p[nmax][nmax];

void dfs(int i, int j) {
	vis[i][j] = 1;
	FOR(k, i - 1, i + 2) FOR(l, j - 1, j + 2) {
		if (abs(k - i) + abs(l - j) == 1 && k >= 0 && k < n && l >= 0 && l < m && a[k][l] == a[i][j]) {
			if (!vis[k][l]) {p[k][l] = i * m + j; dfs(k, l);}
			else if (p[i][j] != k * m + l) {printf("Yes"); exit(0);}
		}
	}
}

void solve() {
	ms(vis, 0); ms(p, -1);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) cin>>a[i];
	FOR(i, 0, n) FOR(j, 0, m) if (!vis[i][j]) dfs(i, j);
	printf("No");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}