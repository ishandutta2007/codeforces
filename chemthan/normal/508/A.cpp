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

const int maxn = 1010;
int n, m, k;
int a[maxn][maxn];

bool sum(int i, int j) {
     if (i < 0 || i + 1 >= n || j < 0 || j + 1 >= m) return false;
     return a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 4;
}

void solve() {
     ms(a, 0);
     scanf("%d%d%d", &n, &m, &k);
     FOR(i, 0, k) {
            int u, v;
            scanf("%d%d", &u, &v); u--; v--;
            a[u][v] = 1;
            if (sum(u, v) || sum(u - 1, v) || sum(u, v - 1) || sum(u - 1, v - 1)) {printf("%d", i + 1); return;}
     }
     printf("0");
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