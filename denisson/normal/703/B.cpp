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

int n, k;
ll color[100007];
bool bad[100007];
ll ans = 0;

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
	cin >> n >> k;
	forn(i, n)
		cin >> color[i];
	ll sum = 0, sum2 = 0;
	forn(i, n)
		sum += (ll)color[i];
	forn(i, k) {
		int a;
		cin >> a;
		bad[a - 1] = 1;
	}
	forn(i, n)
		if (bad[i])
			sum2 += (ll)color[i];
	forn(i, n) {
		if (!bad[i]) {
			if (!bad[(i + 1) % n])
				ans += (ll)color[i] * color[(i + 1) % n];
			if (!bad[(i - 1 + n) % n])
				ans += (ll)color[i] * color[(i - 1 + n) % n];
			ans += (ll)color[i] * sum2;
		} else {
			ans += ((ll)color[i] * (sum - color[i]));
		}
	}
	cout << ans / 2;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}