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
int n;
int a[nmax];
int ans[nmax];
vii v;

void solve() {
	ms(a, 0);
	cin>>n;
	FOR(i, 0, n) {cin>>a[i]; v.push_back(ii(-a[i], i));}
	sort(v.begin(), v.end());
	int k = 0;
	ans[v[0].second] = 0;
	FOR(i, 1, n) {int k = v[i].second; ans[k] = i; if (v[i].first == v[i - 1].first) ans[k] = ans[v[i - 1].second];}
	FOR(i, 0, n) {cout<<ans[i] + 1<<" ";}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}