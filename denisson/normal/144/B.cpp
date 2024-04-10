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

int x1, x2, y1, y2;
int n;
bool f[10007];
int ans = 0;
pair<pair<int, int>, int> a[1007];
vector<pair<int, int> > d;

bool ok(pair<int, int> a, pair<int, int> b, int r) {
	return((a.XX - b.XX) * (a.XX - b.XX) + (a.YY - b.YY) * (a.YY - b.YY) <= r * r);
}

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
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);
	cin >> n;
	forn(i, n)
		cin >> a[i].XX.XX >> a[i].XX.YY >> a[i].YY;
	//
	for (int x = x1; x <= x2; x++) {
		d.pub(mp(x, y1));
		d.pub(mp(x, y2));
	}
	for (int y = y1 + 1; y <= y2 - 1; y++) {
		d.pub(mp(x1, y));
		d.pub(mp(x2, y));
	}
	//
	forn(i, n) {
		forn(j, d.size())
			f[j] = max(f[j], ok(a[i].XX, d[j], a[i].YY));
	}
	forn(i, d.size())
		if (!f[i])
			ans++;
	cout << ans;
}