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
int n, m;
int a[nmax];
int c[nmax];
set<int> st;

void add(int p, int x) {
	if (p == n || p == -1) return;
	if (x + c[p] < a[p]) {c[p] += x; return;}
	if (x + c[p] >= a[p]) {
		x -= a[p] - c[p];
		c[p] = a[p];
		set<int>::iterator it = st.find(p);
		if (it != st.end()) st.erase(st.find(p));
		it = st.upper_bound(p);
		add(*it, x);
	}
}

void solve() {
	ms(c, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, -1, n + 1) st.insert(i);
	scanf("%d", &m);
	while (m--) {
		int t, x, y;
		scanf("%d", &t);
		if (t == 1) {scanf("%d%d", &x, &y); add(x - 1, y);}
		else {scanf("%d", &x); cout<<c[x - 1]<<"\n";}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}