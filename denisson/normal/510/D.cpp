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
const ll MOD = 1e9 + 7;
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

int n;
int a[307];
int c[307];

map<int, int> ans[307];

int gcd(int a, int b) {
	if (b == 0)
		re a;
	re gcd(b, a % b);
}

int get(int k, int was) {
	//cout << k << ' ' << was << LN;
	if (was == 1)
		re 0;
	if (k == n) {
		if (was == 1)
			re 0;
		re INF;
	}
	if (ans[k][was] != 0)
		re ans[k][was];
	int ansnow = c[k] + get(k + 1, a[k]);
	if (was != 1)
		ansnow = min(ansnow, get(k + 1, was));
	if (was != -1 && was != 1 && get(k + 1, gcd(was, a[k])) != INF)
		ansnow = min(ansnow, c[k] + get(k + 1, gcd(was, a[k])));
	ans[k][was] = ansnow;
	re ansnow;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0);
	//cin.tie();
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	cin >> n;
	forn(i, n)
		cin >> a[i];
	forn(i, n)
		cin >> c[i];
	if (n == 1) {
		if (a[0] == 1)
			cout << c[0];
		else
			cout << -1;
		exit(0);
	}
	int aha = get(0, -1);
	if (aha == INF)
		cout << -1;
	else
		cout << aha;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}