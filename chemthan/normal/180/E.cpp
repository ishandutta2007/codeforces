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

int const nmax = 200010;
int n, m, k;
int a[nmax];
vii c[nmax];

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n) {
		int j = i;
		while (j < n - 1 && a[j + 1] == a[i]) j++;
		c[a[i] - 1].push_back(ii(i, j)); i = j;
	}
	int ans = INT_MIN;
	FOR(i, 0, m) {
		int next = 0, p = 0;
		FOR(j, 0, sz(c[i])) {
			if (j) p -= c[i][j - 1].second - c[i][j - 1].first + 1;
			while (next < sz(c[i])) {
				int q = p + c[i][next].second - c[i][next].first + 1;
				if (c[i][next].second - c[i][j].first + 1 - q > k) break;
				p = q;
				next++;
			}
			ans = MAX(ans, p);
		}
	}
	cout<<ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}