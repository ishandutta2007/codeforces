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
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= (int)t; i++)
#define ford(i, s, t) for (int i = s; i >= (int)t; i--)
#define mk make_pair
#define pk push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "sequence"

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int MAXN = (int)2e5 + 7;
const ll INF = (ll)2e9 + 7;
const int MOD = (int)1e9 + 7;
const ll P = 239017;
const ull MM = (ull)2147482661;

int solve();

int main()
{
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	freopen("test.txt", "w", stderr);
//#else
//	freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
//#endif
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	solve();
	return 0;
}

struct event{
	int type, d;//0-RUN 1-JUMP
};

int a[MAXN];
vector<event> v;

void ok(bool f) {
	if (!f) {
		printf("IMPOSSIBLE\n");
		exit(0);
	}
}

void finish() {
	for (auto e : v) {
		printf(e.type ? "JUMP " : "RUN ");
		printf("%d\n", e.d);
	}
	exit(0);
}

int solve()
{
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	forn(i, n) {
		scanf("%d", a + i);
	}
	sort(a, a + n);

	if (a[0] > m) {
		v.pk({ 0, m });
		finish();
	}
	ok(a[0] > s);
	int maxx = a[0] + d - 1, lastx = a[0] - 1, x = 0;
	v.pk({ 0, lastx });
	
	forn(i, n) {
		int nx = a[i] - 1;
		if (x != a[i]) {
			ok(x <= maxx);

			if (nx >= m) {
				v.pk({ 1, m - lastx });
				finish();
			}

			if (nx - x >= s) {
				int nmaxx = nx + d;
				if (nmaxx > maxx) {
					v.pk({ 1, x - lastx });
					v.pk({ 0, nx - x });
					lastx = nx;
					maxx = nmaxx;
				}
			}
		}
		x = nx + 2;
	}
	
	ok(maxx >= x);
	ok(x <= m);
	v.pk({ 1, x - lastx });
	if (x < m) {
		v.pk({ 0, m - x });
	}
	finish();
	return 0;
}