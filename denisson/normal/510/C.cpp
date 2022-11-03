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
str a[107];
bool was[27][27];
bool was1[27];
bool can[27];
int color[27];
vec<char> ans;
vec<int> g[27];

void dfs(int v) {
	was1[v] = 1;
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (!was1[to]) {
			dfs(to);
		}
	}
	ans.pb((char)v + 'a');
}

void dfs2(int v) {
	color[v] = 1;
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (color[to] == 1) {
			cout << "Impossible", exit(0);
		} else {
			dfs2(to);
		}
	}
	color[v] = 2;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	ios_base::sync_with_stdio(0);
	cin.tie();
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	//for (char c = 'a'; c <= 'z'; c++)
	//	cout << c;
	//cout << LN;
	cin >> n;
	forn(i, n)
		cin >> a[i];
	forn(i, n - 1) {
		int len = min(a[i].size(), a[i + 1].size());
		bool f = 0;
		forn(j, len) {
			if (a[i][j] != a[i + 1][j]) {
				int c1 = a[i][j] - 'a';
				int c2 = a[i + 1][j] - 'a';
				//cout << (char)('a' + c1) << ' ' << (char)('a' + c2) << LN;
				if (!was[c2][c1]) {
					was[c2][c1] = 1;
					g[c2].pb(c1);
					can[c1] = 1;
				}
				f = 1;
				break;
			}
		}
		if (!f && len == a[i + 1].size())
			cout << "Impossible", exit(0);
	}
	forn(i, 26)
		if (color[i] == 0)
			dfs2(i);
	forn(i, 26)
		if (!was1[i] && !can[i]) {
			dfs(i);
		}
	for (char c : ans)
		cout << c;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}