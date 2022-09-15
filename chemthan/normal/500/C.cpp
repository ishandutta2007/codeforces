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

const int maxn = 1010;
int n, m;
int w[maxn];
int b[maxn];
int c[maxn];
vii v;
stack<int> st, tmp;

void solve() {
	ms(c, -1);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) scanf("%d", w + i);
	int cnt = 0;
	FOR(i, 0, m) {
		scanf("%d", b + i); b[i]--;
		if (c[b[i]] == -1) c[b[i]] = cnt++;
	}
	FOR(i, 0, n) {if (c[i] == -1) c[i] = INT_MAX; v.push_back(make_pair(c[i], i));}
	sort(v.rbegin(), v.rend());
	FOR(i, 0, n) st.push(v[i].second);
	ll ans = 0;
	FOR(i, 0, m) {
		while (st.top() != b[i]) {int k = st.top(); st.pop(); tmp.push(k); ans += w[k];}
		st.pop();
		while (!tmp.empty()) {st.push(tmp.top()); tmp.pop();}
		st.push(b[i]);
	}
	printf("%I64d", ans);
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