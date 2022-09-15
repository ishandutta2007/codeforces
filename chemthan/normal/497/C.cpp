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
int n, m;
vector<pair<pair<int, int>, int> > V1;
vector<pair<pair<int, int>, pair<int, int> > > V2;
set<pi> st;
map<pi, int> mp;
int ans[maxn];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {int a, b; scanf("%d%d", &a, &b); V1.push_back(make_pair(make_pair(a, b), i));}
	scanf("%d", &m);
	FOR(i, 0, m) {int c, d, k; scanf("%d%d%d", &c, &d, &k); V2.push_back(make_pair(make_pair(c, d), make_pair(k, i + 1)));}
	sort(V1.begin(), V1.end());
	sort(V2.begin(), V2.end());
	int d = 0;
	FOR(i, 0, sz(V1)) {
		while (d < sz(V2) && V2[d].first.first <= V1[i].first.first) {st.insert(make_pair(V2[d].first.second, V2[d].second.second)); mp[make_pair(V2[d].first.second, V2[d].second.second)] = V2[d].second.first; d++;}
		set<pi>::iterator it = st.lower_bound(make_pair(V1[i].first.second, INT_MIN));
		if (it == st.end()) {printf("NO"); return;}
		ans[V1[i].second] = it->second;
		mp[*it]--;
		if (!mp[*it]) st.erase(*it);
	}
	printf("YES\n");
	FOR(i, 0, n) printf("%d ", ans[i]);
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