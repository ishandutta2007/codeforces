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
int n, m;
ll a[maxn][maxn];
ll aa[maxn];
ll bb[maxn];

void solve() {
     scanf("%d%d", &n, &m);
     FOR(i, 0, n) FOR(j, 0, m) scanf("%I64d", &a[i][j]);
     ll g = 0;
     FOR(i, 0, n - 1) {
            FOR(j, 0, m - 1) {
                   ll u = abs((a[i + 1][j + 1] - a[i + 1][j]) - (a[i][j + 1] - a[i][j]));
                   ll v = abs((a[i + 1][j + 1] - a[i][j + 1]) - (a[i + 1][j] - a[i][j]));
                   g = gcd(g, gcd(u, v));
            }
     }
     if (g == 0) g = 1000000007;
     FOR(i, 0, n) FOR(j, 0, m) if (a[i][j] >= g) {printf("NO"); return;}
     aa[0] = 0; bb[0] = a[0][0];
     FOR(i, 0, n - 1) {
            aa[i + 1] = (g + aa[i] + a[i + 1][0] - a[i][0]) % g;
     }
     FOR(j, 0, m - 1) {
            bb[j + 1] = (g + bb[j] + a[0][j + 1] - a[0][j]) % g;
     }
     printf("YES\n%d\n", g);
     FOR(i, 0, n) printf("%d ", aa[i]);
     printf("\n");
     FOR(i, 0, m) printf("%d ", bb[i]);
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