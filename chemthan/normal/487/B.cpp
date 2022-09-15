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

const int maxn = 100010;
int n, s, l;
int a[maxn];
int f[maxn];
multiset<int> st, rs;

void solve() {
	ms(f, 0);
	scanf("%d%d%d", &n, &s, &l);
	int pos = 1;
	FOR(i, 1, n + 1) {
		scanf("%d", a + i);
		st.insert(a[i]);
		while (*st.rbegin() - *st.begin() > s) {
			st.erase(st.find(a[pos]));
			if (i - pos >= l && pos) rs.erase(rs.find(f[pos - 1]));
			pos++;
		}
		if (i - pos + 1 >= l) rs.insert(f[i - l]);
		if (sz(rs)) f[i] = *rs.begin() + 1; else f[i] = maxn;
	}
	if (f[n] >= maxn) printf("-1"); else printf("%d", f[n]);
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