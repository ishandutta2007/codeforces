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

struct item {
	int t1, t2, w, s, v;
	item() {}
};

int n, s;
item a[507];
int dp[507][1007];
int p[1007];
vector<int> q[2 * 507];

int get(int v, int wei) {
	if (dp[v][wei] != -1)
		return dp[v][wei];
	int ans = 0;
	vector<int> p(2 * n + 1, 0);
	for (int l = max(a[v].t1, 0); l <= min(a[v].t2, 2 * n); l++) {
		if (l != 0)
			p[l] = max(p[l], p[l - 1]);
		forn(i, q[l].size()) {
			item now = a[q[l][i]];
			if (q[l][i] == v)
				continue;
			if (a[v].t1 <= now.t1 && now.t2 <= a[v].t2 && wei >= now.w) {
				p[now.t2] = max(p[now.t2], p[l] + now.v + get(q[l][i], min(wei - now.w, now.s)));
			}
		}
		ans = max(ans, p[l]);
	}
	dp[v][wei] = ans;
	return ans;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	forn(i, 505)
		forn(j, 1005)
			dp[i][j] = -1;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t1 >> a[i].t2 >> a[i].w >> a[i].s >> a[i].v;
	}
	a[0].t1 = -1;
	a[0].t2 = INF;
	a[0].s = s;
	a[0].v = 0;
	a[0].w = 0;
	for (int i = 1; i <= n; i++)
		q[a[i].t1].pub(i);
	cout << get(0, s);
}