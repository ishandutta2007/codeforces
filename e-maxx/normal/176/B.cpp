#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos(0.0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MOD = INF + 7;
typedef int64 matr[3][3];


string a, b;
int k;


bool read() {
	return !! (cin >> a >> b >> k);
}


int64 val;


inline int64 f (int sh) {
	if (sh)
		return f (0) + (k%2==0 ? -1 : +1);
	return val;
}


void mult (matr a, matr b) {
	matr c;
	memset (c, 0, sizeof c);
	forn(i,3)
		forn(j,3)
			forn(k,3)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
	memcpy (a, c, sizeof c);
}

void binpow (matr a, int b) {
	matr res;
	memset (res, 0, sizeof res);
	forn(i,3)
		res[i][i] = 1;

	while (b)
		if (b & 1) {
			mult (res, a);
			--b;
		}
		else {
			mult (a, a);
			b >>= 1;
		}

	memcpy (a, res, sizeof res);
}


int solve() {
	if (k == 0)
		return a==b;

	int n = (int) a.length();
	if (k == 1) {
		val = 0;
	}
	else {
		matr m = {
				{ 0, 0, 0 },
				{ (n-1), (n-1)*(n-1), 0 },
				{ (MOD-(n-1))%MOD, (MOD+(n-1)-(n-1)*(n-1))%MOD, 1 }
		};
		binpow (m, (k-2)/2);

		val = m[1][1] * (n-1) + m[2][1];
		val = (val % MOD + MOD) % MOD;
		if (k % 2 == 1)
			val = val * (n-1) - (n-1);
		val = (val % MOD + MOD) % MOD;
	}

	int64 ans = 0;
	forn(i,n) {
		if (a == b)
			ans += f (i);

		rotate (a.begin(), a.begin()+1, a.end());
	}
	return (int) ((ans % MOD + MOD) % MOD);
}


int main() {
#ifdef SU2_PROJ
	cerr << "B" << endl;
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		cout << solve() << endl;

}