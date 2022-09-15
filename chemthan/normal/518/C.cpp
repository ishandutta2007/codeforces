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

int const nmax = 100010;
int n, m, k;
int a[nmax];
int res[nmax];

void solve() {
	ms(res, 0);
	cin>>n>>m>>k;
	FOR(i, 0, n) {cin>>a[i]; res[a[i]] = i;}
	ll ans = 0;
	FOR(i, 0, m) {
		int b; cin>>b;
		int l = res[b];
		ans += (l / k) + 1;
		if (l > 0) {int buf = a[l]; a[l] = a[l - 1]; a[l - 1] = buf; res[a[l]] = l; res[a[l - 1]] = l - 1;}
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