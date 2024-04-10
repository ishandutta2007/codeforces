//#include <bits/stdc++.h>
#include <iostream>
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

int const nmax = 1010;
int n, X, Y;
int x[nmax], y[nmax];
bool isdestroy[nmax];

void solve() {
	ms(isdestroy, 0);
	cin>>n>>X>>Y;
	FOR(i, 0, n) cin>>x[i]>>y[i];
	int cnt = 0;
	FOR(i, 0, n) {
		if (!isdestroy[i] && (x[i] != X || y[i] != Y)) {
			isdestroy[i] = 1; cnt++;
			FOR(j, 0, n) if ((x[i] - X) * (y[j] - Y) == (x[j] - X) * (y[i] - Y)) isdestroy[j] = 1;
		}
	}
	if (cnt) cout<<cnt; else cout<<1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}