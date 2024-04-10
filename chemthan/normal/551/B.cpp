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
char a[nmax], b[nmax], c[nmax];
int aa[256], bb[256], cc[256], dd[256];

int check(int k) {
	ms(dd, 0);
	FOR(i, 'a', 'z' + 1) {dd[i] = aa[i] - k * bb[i]; if (dd[i] < 0) return -1;}
	int ret = INT_MAX;
	FOR(i, 'a', 'z' + 1) if (cc[i]) ret = MIN(ret, dd[i] / cc[i]);
	return ret;
}

void solve() {
	ms(aa, 0); ms(bb, 0); ms(cc, 0);
	cin>>a>>b>>c;
	int la = strlen(a), lb = strlen(b), lc = strlen(c);
	FOR(i, 0, la) aa[a[i]]++;
	FOR(i, 0, lb) bb[b[i]]++;
	FOR(i, 0, lc) cc[c[i]]++;
	int x = INT_MAX;
	FOR(i, 'a', 'z' + 1) if (bb[i]) x = MIN(x, aa[i] / bb[i]);
	int ans = 0;
	int k1 = 0, k2 = 0;
	FOR(i, 0, x + 1){
		int ret = check(i);
		if (ret > -1) {if (ans < i + ret) {ans = i + ret; k1 = i; k2 = ret;}}
	}
	FOR(i, 'a', 'z' + 1) {aa[i] -= k1 * bb[i] + k2 * cc[i];}
	FOR(i, 0, k1) cout<<b;
	FOR(i, 0, k2) cout<<c;
	FOR(i, 'a', 'z' + 1) while (aa[i]--) cout<<char(i);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}