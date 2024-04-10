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

int const nmax = 200010;
int n;
ll x[nmax], w[nmax];
vii a;

void solve() {
	cin>>n;
	FOR(i, 0, n) {cin>>x[i]>>w[i]; a.push_back(ii(x[i] + w[i], x[i] - w[i]));}
	sort(a.begin(), a.end());
	int ans = 1, cur = 0;
	FOR(i, 1, n) if (a[cur].first <= a[i].second) {ans++; cur = i;}
	cout<<ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}