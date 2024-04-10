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

int const nmax = 2010;
int n, t;
ld p;
ld f[nmax][nmax];

void solve() {
	ms(f, 0);
	cin>>n>>p>>t;
	f[0][0] = 1;
	FOR(i, 0, t) {
		FOR(j, 0, n) {
			f[i + 1][j + 1] += f[i][j] * p;
			f[i + 1][j] += f[i][j] * (1 - p);
		}
		f[i + 1][n] += f[i][n];
	}
	ld ans = 0;
	FOR(i, 0, n + 1) ans += f[t][i] * i;
	cout<<fixed<<setprecision(10)<<ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}