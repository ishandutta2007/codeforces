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
int n, m, k;
bool ftr[maxn];
vi adj[maxn];
int d[maxn];
int str[maxn];
int str2[maxn];

void solve() {
	ms(ftr, 0); ms(d, 0); ms(str, 0); ms(str2, 0);
	scanf("%d%d%d", &n, &m, &k);
	int l;
	FOR(i, 0, k) {scanf("%d", &l); l--; ftr[l] = 1;}
	int a, b;
	FOR(i, 0, m) {
		scanf("%d%d", &a, &b); a--; b--;
		adj[a].push_back(b); adj[b].push_back(a);
		d[a]++; d[b]++;
		if (!ftr[a] && !ftr[b]) {str[a]++; str[b]++; str2[a]++; str2[b]++;}
	}
	set<pair<ll, int> > st;
	FOR(i, 0, n) if (!ftr[i]) st.insert(make_pair(1000000000LL * str[i] / d[i], i));
	ll dmax = INT_MIN;
	while (!st.empty()) {
		set<pair<ll, int> >::iterator it = st.begin();
		dmax = max(dmax, it->first);
		int u = it->second;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			set<pair<ll, int> >::iterator it2 = st.find(make_pair(1000000000LL * str[v] / d[v], v));
			if (it2 != st.end()) {
				st.erase(make_pair(1000000000LL * str[v] / d[v], v));
				st.insert(make_pair(1000000000LL * (--str[v]) / d[v], v));
			}
		}
		st.erase(make_pair(1000000000LL * str[u] / d[u], u));
	}
	FOR(i, 0, n) if (!ftr[i]) st.insert(make_pair(1000000000LL * str2[i] / d[i], i));
	while (!st.empty()) {
		set<pair<ll, int> >::iterator it = st.begin();
		if (it->first == dmax) {
			printf("%d\n", st.size());
			for (it = st.begin(); it != st.end(); it++) printf("%d ", it->second + 1);
			return;
		}
		int u = it->second;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			set<pair<ll, int> >::iterator it2 = st.find(make_pair(1000000000LL * str2[v] / d[v], v));
			if (it2 != st.end()) {
				st.erase(make_pair(1000000000LL * str2[v] / d[v], v));
				st.insert(make_pair(1000000000LL * (--str2[v]) / d[v], v));
			}
		}
		st.erase(make_pair(1000000000LL * str2[u] / d[u], u));
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}