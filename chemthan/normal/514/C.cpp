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

int const nmax = 600010;
char s[nmax];
int n, m;
set<ll> vl;
ll M = 1000000007;

ll _hash(char *s) {
	ll res = 0;
	int len = strlen(s);
	FOR(i, 0, len) res = (res * 257 + s[i]) % M;
	return res;
}

void solve() {
	cin>>n>>m;
	FOR(i, 0, n) {scanf("%s", s); vl.insert(_hash(s));}
	FOR(i, 0, m) {
		scanf("%s", s);
		ll h = _hash(s), p = 1;
		int len = strlen(s);
		bool ck = false;
		FORd(j, len, 0) {
			if (ck) break;
			FOR(k, 'a', 'c' + 1) if (k != s[j] && vl.find((2 * M + h + (k - s[j]) * p) % M) != vl.end()) {cout<<"YES\n"; ck = true; break;}
			p = (p * 257) % M;
		}
		if (!ck) cout<<"NO\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}