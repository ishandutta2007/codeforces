#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 110000;
const int CNT = 1050;
const int MOD = INF + 7;


vector<int> v;
int n, k, cnt[CNT];


bool read() {
	if (! (cin >> n >> k))
		return false;
	memset (cnt, 0, sizeof cnt);
	forn(i,n) {
		int x;
		scanf ("%d", &x);
		if (binary_search (all(v), x))
			++cnt[ lower_bound (all(v), x) - v.begin() ];
		else
			++cnt[0];
	}
	return true;
}


int fact[MAXN], d[2][MAXN];

inline int binpow (int a, int b) {
	int res = 1;
	while (b)
		if (b & 1) {
			res = res * 1ll * a % MOD;
			--b;
		}
		else {
			a = a * 1ll * a % MOD;
			b >>= 1;
		}
	return res;
}

inline int inv (int x) {
	return binpow (x, MOD-2);
}

inline int get_c (int n, int k) {
	if (k < 0 || k > n)  return 0;
	return fact[n] * 1ll * inv (fact[k] * 1ll * fact[n-k] % MOD) % MOD;
}

void solve() {
	for (int i=0; i<=k; ++i)
		d[0][i] = get_c (cnt[0], i);
	int t = 0;
	for (int i=1; i<CNT; ++i) {
		t ^= 1;
		for (int j=0; j<=k; ++j)
			d[t][j] = int ((d[t^1][j] + (j ? d[t^1][j-1] : 0) * 1ll * cnt[i]) % MOD);
	}
	cout << d[t][k] << endl;
}



int main() {
	v.pb (0);
	forn(i,v.size()) {
		int64 c = v[i];
		if (c*10+4 <= INF)
			v.pb (int (c*10+4));
		if (c*10+7 <= INF)
			v.pb (int (c*10+7));
	}
	sort (all (v));

	fact[0] = 1;
	fore(i,1,MAXN)
		fact[i] = fact[i-1] * 1ll * i % MOD;

#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}