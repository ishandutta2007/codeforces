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

string s, s2;
int was[27];
char a[2][17];
int uk, ee;
char c;

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
	forn(i, (int)s.size() - 1)
		if (s[i] == s[i + 1])
			cout << "Impossible", exit(0);
	forn(i, 26)
		was[i] = -1;
	int r;
	forn(i, s.size()) {
		if (was[s[i] - 'A'] != -1)
			r = abs(was[s[i] - 'A'] - i), c = s[i] - 'A', ee = i;
		else
			was[s[i] - 'A'] = i;
	}
	for (int i = ee; i < (int)s.size() - 1; i++)
		s[i] = s[i + 1];
	s.pop_back();
	int now = was[c];
	int k = (r - 1) / 2;
	//cout << k << endl;
	if (k == 13) {
		now = 0;
		forn(i, 13)
			a[0][i] = s[now++];
		for (int i = 12; i >= 0; i--)
			a[1][i] = s[now++];
	} else {
		//cout << k << endl;
		for (int i = 12 - k; i < 13; i++)
			a[0][i] = s[(now++) % (int)s.size()];
		for (int i = 12; i >= 0; i--)
			a[1][i] = s[(now++) % (int)s.size()];
		for (int i = 0; i < 12 - k; i++)
			a[0][i] = s[(now++) % (int)s.size()];
	}
	forn(i, 2) {
		forn(j, 13)
			cout << a[i][j];
		cout << LN;
	}
}