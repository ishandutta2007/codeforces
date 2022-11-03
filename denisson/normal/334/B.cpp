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
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 1e4 + 7;
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

vector<pair<int, int> > a(8), b(8);
map<int, int> ma;
set<int> se;

bool ok(vector<pair<int, int> > q) {
	ma.clear();
	se.clear();
	forn(i, 8)
		ma[q[i].XX]++, se.insert(q[i].XX);
	if (ma.size() != 3)
		return 0;
	if (!(ma[*se.begin()] == 3 && ma[*((++se.begin()))] == 2 && ma[*(++(++se.begin()))] == 3))
		return 0;
	return 1;
}

set<pair<int, int> > tt;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	forn(i, 8)
		cin >> a[i].XX >> a[i].YY, tt.insert(a[i]);
	if (tt.size() != 8)
		cout << "ugly", exit(0);
	forn(i, 8)
		b[i].XX = a[i].YY, b[i].YY = a[i].XX;
	if (ok(a) && ok(b)) {
		cout << "respectable";
	} else
		cout << "ugly";
}