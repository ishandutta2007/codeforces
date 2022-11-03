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
     
const int MAXN = 60007;
const int P = 79633;
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 8e8 + 23457;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 2e8;
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

int n;
ll k;
int a[100007];
int w[100007];
int up[41][100007];
int mm[41][100007];
int a1[100007];
ll a2[100007];
ll ss[41][100007];

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
	ios_base::sync_with_stdio(0);
	cin.tie();
	cin >> n >> k;
	forn(i, n)
		cin >> a[i], up[0][i] = a[i];
	forn(i, n)
		cin >> w[i], mm[0][i] = w[i], ss[0][i] = w[i];
	form(l, 1, 40)
		forn(i, n)
			up[l][i] = up[l - 1][up[l - 1][i]];
	form(l, 1, 40)
		forn(i, n)
			mm[l][i] = min(mm[l - 1][i], mm[l - 1][up[l - 1][i]]);
	form(l, 1, 40)
		forn(i, n)
		ss[l][i] = ss[l - 1][i] + ss[l - 1][up[l - 1][i]];
	forn(i, n) {
		int ans = INF;
		int a = i;
		ll kk = k;
		for (int l = 40; l >= 0; l--)
			if (((ll)1 << l) <= kk)
				kk -= ((ll)1 << l), ans = min(ans, mm[l][a]), a = up[l][a];
		a1[i] = ans;
	}
	forn(i, n) {
		ll ans = 0;
		int a = i;
		ll kk = k;
		for (int l = 40; l >= 0; l--)
			if (((ll)1 << l) <= kk)
				kk -= ((ll)1 << l), ans += ss[l][a], a = up[l][a];
		a2[i] = ans;
	}
	forn(i, n)
		cout << a2[i] << ' ' << a1[i] << LN;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}