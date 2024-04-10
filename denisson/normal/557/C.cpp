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
pair<int, int> a[100007];
vec<pair<int, vec<int> > > q;
int was[207];
int pref[100007];

int get(int k) {
	int ans = 0;
	form(i, 1, 200) {
		if (k >= was[i])
			k -= was[i], ans += was[i] * i;
		else
			ans += k * i, k = 0;
	}
	re ans;
}

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
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i].XX);
	}
	forn(i, n) {
		scanf("%d", &a[i].YY);
	}
	sort(a, a + n);
	forn(i, n) {
		if (q.size() == 0 || q.back().XX != a[i].XX) {
			vec<int> s;
			s.pb(a[i].YY);
			q.pb(mp(a[i].XX, s));
		} else {
			q.back().YY.pb(a[i].YY);
		}
	}
	int len = q.size();
	for (int i = q.size() - 1; i >= 0; i--) {
		pref[i] = 0;
		forn(j, q[i].YY.size())
			pref[i] += q[i].YY[j];
		if (i != len - 1)
			pref[i] += pref[i + 1];
	}
	int ans = INF;
	int wass = 0;
	forn(i, q.size()) {
		int now = q[i].YY.size();
		int ost = n - wass - now;
		int last = n - ost - now;
		int k = max(last - (now - 1), 0);
		ans = min(ans, pref[i + 1] + get(k));
		forn(j, q[i].YY.size())
			was[q[i].YY[j]]++;
		wass += now;
	}
	cout << ans;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}