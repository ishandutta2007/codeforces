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

int n, m;
int a[100007], b[100007];
vec < pair<int, int> > q;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);	
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m)
		scanf("%d", &b[i]);
	forn(i, n) {
		q.pb(mp(a[i], 0));
	}
	forn(i, m) {
		q.pb(mp(b[i], 1));
	}
	sort(all(q));
	ll sum1 = 0, sum2 = 0, k1 = 0, k2 = 0;
	forn(i, m)
		sum2 += (ll)b[i], k2++;
	ll ans = LINF;
	forn(i, q.size()) {
		ans = min(ans, (ll)q[i].XX * (ll)k1 - (ll)sum1 + (ll)sum2 - (ll)q[i].XX * (ll)k2);
		if (q[i].YY == 0)
			k1++, sum1 += (ll)q[i].XX;
		else
			k2--, sum2 -= (ll)q[i].XX;
	}
	cout << ans;
}