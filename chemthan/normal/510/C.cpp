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

int const nmax = 110;
int n;
char s[nmax][nmax];
int sig[255][255];

void run(int u, int v) {
	int len = MIN(strlen(s[u]), strlen(s[v]));
	FOR(i, 0, len) {
		int x = s[u][i], y = s[v][i];
		if (x == y) continue;
		if (sig[x][y] == 1) {cout<<"Impossible"; exit(0);}
		sig[x][y] = -1; sig[y][x] = 1;
		return;
	}
	if (strlen(s[u]) > strlen(s[v])) {cout<<"Impossible"; exit(0);}
}

void solve() {
	ms(s, 0); ms(sig, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%s", s + i);
	FOR(i, 0, n - 1) run(i, i + 1);
	char alb[] = "abcdefghijklmnopqrstuvwxyz";
	int cnt = 0;
	while (1) {
		bool ck = false;
		FOR(i, 0, 26) FOR(j, i + 1, 26) if (sig[alb[i]][alb[j]] == 1) {swap(alb[i], alb[j]); ck = true;}
		if (!ck) break;
		if (cnt++ == 30) {cout<<"Impossible"; return;}
	}
	printf(alb);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}