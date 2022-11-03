#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pb push_back
#define XX first
#define YY second
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 2e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
	char *res = mem + mpos;
	mpos += n;
	return (void *)res;
}
void operator delete ( void * ) { }
*/
//

int a1, a2, a3, a4;

bool can(db c) {
	c = c * 8 + 1;
	db now = sqrt(c);
	re(((db)now - (int)now) == 0);
}

const bool is_testing = 0;
int main() {
	srand(423);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	cin >> a1 >> a2 >> a3 >> a4;
	if (!can(a1) || !can(a4))
		cout << "Impossible", exit(0);
	ll k0 = (ll)1 + sqrt((ll)8 * a1 + 1);
	ll k1 = (ll)1 + sqrt((ll)8 * a4 + 1);
	if (k0 % 2 != 0 || k1 % 2 != 0)
		cout << "Impossible", exit(0);
	k0 /= 2;
	k1 /= 2;
	if (a1 == 0 && a2 == 0 && a3 == 0)
		k0 = 0;
	if (a4 == 0 && a2 == 0 && a3 == 0)
		k1 = 0;
	if (k0 == 0 && k1 == 0) {
		cout << 0;
		exit(0);
	}
	if (k0 == 0) {
		forn(i, k1)
			cout << 1;
		exit(0);
	}
	if (k1 == 0) {
		forn(i, k0)
			cout << 0;
		exit(0);
	}
	if (k0 * k1 != a2 + a3)
		cout << "Impossible", exit(0);
	while (a3 >= k0)
		a3 -= k0, k1--, cout << 1;
	while (k0--) {
		cout << 0;
		if (a3 != 0 && k0 == a3)
			a3 = 0, cout << 1, k1--;
	}
	while (k1--)
		cout << 1;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}