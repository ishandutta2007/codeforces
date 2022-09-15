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

int n, m;
char s[20][21];
vector<ll> d;
ll a[20][20];
ll mk[20][20];
ll vl[20][20];

void solve() {
	ms(mk, 0); ms(vl, 0);
	cin>>n>>m;
	d.assign(1 << n, _I64_MAX);
	FOR(i, 0, n) cin>>s[i];
	FOR(i, 0, n) FOR(j, 0, m) cin>>a[i][j];
	FOR(i, 0, n) FOR(j, 0, m) {
		ll mx = _I64_MIN;
		FOR(k, 0, n) {if (s[i][j] == s[k][j]) {mx = MAX(mx, a[k][j]); mk[i][j] += 1 << k; vl[i][j] += a[k][j];}}
		vl[i][j] -= mx;
	}
	d[0] = 0;
	FOR(mask, 1, 1 << n) {
		int i = 0; while (!(mask & (1 << i))) i++;
		FOR(j, 0, m) {
			d[mask] = MIN(d[mask], d[mask ^ (1 << i)] + a[i][j]);
			d[mask] = MIN(d[mask], d[mask & (mask ^ mk[i][j])] + vl[i][j]);
		}
	}
	cout<<d[(1 << n) - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}