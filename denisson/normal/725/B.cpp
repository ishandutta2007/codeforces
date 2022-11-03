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
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
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

ll n;
string s;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	cin >> s;
	forn(i, (int)s.size() - 1) {
		n = (ll)10 * n + s[i] - '0';
	}
	ll ful = (n - 1) / (ll)4;
	ll ans = 0;
	ans += (ll)4 * ful + (ll)ful * (ll)12;
	n -= ful * (ll)4;
	if (n == 1) 
	{
		if (s.back() == 'f')
			ans++;
		if (s.back() == 'e')
			ans += 2;
		if (s.back() == 'd')
			ans += 3;
		if (s.back() == 'a')
			ans += 4;
		if (s.back() == 'b')
			ans += 5;
		if (s.back() == 'c')
			ans += 6;
	}
	if (n == 2) {
		if (s.back() == 'f')
			ans++;
		if (s.back() == 'e')
			ans += 2;
		if (s.back() == 'd')
			ans += 3;
		if (s.back() == 'a')
			ans += 4;
		if (s.back() == 'b')
			ans += 5;
		if (s.back() == 'c')
			ans += 6;
		ans += 7;

	}
	if (n == 3) {
		if (s.back() == 'f')
			ans++;
		if (s.back() == 'e')
			ans += 2;
		if (s.back() == 'd')
			ans += 3;
		if (s.back() == 'a')
			ans += 4;
		if (s.back() == 'b')
			ans += 5;
		if (s.back() == 'c')
			ans += 6;

	}
	if (n == 4) {
		if (s.back() == 'f')
			ans++;
		if (s.back() == 'e')
			ans += 2;
		if (s.back() == 'd')
			ans += 3;
		if (s.back() == 'a')
			ans += 4;
		if (s.back() == 'b')
			ans += 5;
		if (s.back() == 'c')
			ans += 6;
		ans += 7;

	}
	cout << ans;

}