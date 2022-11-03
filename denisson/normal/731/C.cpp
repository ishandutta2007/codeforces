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

int n, m, k;
int a[200007];
bool was[200007];
vector<int> g[200007];
map<int, int> ma;
vector<vector<int> > s;


void dfs(int v) {
	was[v] = 1;
	s.back().pub(v);
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (!was[to])
			dfs(to);
	}
}

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
	cin >> n >> m >> k;
	forn(i, n)
		cin >> a[i];
	forn(i, m) {
		int q1, q2;
		cin >> q1 >> q2;
		q1--; q2--;
		g[q1].pub(q2);
		g[q2].pub(q1);
	}
	forn(i, n)
		if (!was[i]) {
			vector<int> ss;
			s.pub(ss);
			dfs(i);
		}
	int ans = 0;

	forn(i, s.size()) {
		ma.clear();
		int mma = 0;
		for (int c : s[i]) {
			ma[a[c]]++;
			mma = max(mma, ma[a[c]]);
		}
		ans += s[i].size() - mma;
	}
	cout << ans;
}