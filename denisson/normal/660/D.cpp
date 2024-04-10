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
pair<int, int> a[2007];
ll ans = 0;
map<pair<pair<int, int>, ll>, int> ma;

int gcd(int a, int b) {
	if (b == 0)
		re a;
	re gcd(b, a % b);
}

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
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d", &a[i].XX, &a[i].YY);
	forn(i, n) {
		forn(j, n) {
			if (i != j) {
				int q1 = a[i].XX - a[j].XX;
				int q2 = a[i].YY - a[j].YY;
				ll d1 = q1;
				ll d2 = q2;
				if (q1 == 0)
					q2 = 1;
				if (q2 == 0)
					q1 = 1;
				if (q1 != 0 && q2 != 0) {
					if (q1 < 0)
						q1 = -q1, q2 = -q2;
					int g = gcd(abs(q1), abs(q2));
					q1 /= g;
					q2 /= g;
				}
				ma[mp(mp(q1, q2), d1 * d1 + d2 * d2)]++;
				//cout << q1 << ' ' << q2 << LN;
			}
		}
	}
	for (auto t : ma) {
		ll now = t.YY / 2;
		ans += now * (now - 1) / 2;
	}
	cout << ans / 2;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}