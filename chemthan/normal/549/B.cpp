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

int const nmax = 110;
int n;
vector<int> v[nmax], ans;
int a[nmax];
int b[nmax];

void solve() {
	ms(b, 0);
	cin>>n;
	char buf[nmax];
	FOR(i, 0, n) {
		cin>>buf;
		FOR(j, 0, n) if (buf[j] == '1') v[i].push_back(j);
	}
	FOR(i, 0, n) cin>>a[i];
	queue<int> q; FOR(i, 0, n) if (a[i] == b[i]) q.push(i);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (a[i] == b[i]) {
			ans.push_back(i);
			FOR(j, 0, sz(v[i])) {int k = v[i][j]; b[k]++; if (a[k] == b[k]) q.push(k);}
		}
	}
	cout<<sz(ans)<<"\n";
	FOR(i, 0, sz(ans)) cout<<ans[i] + 1<<" ";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}