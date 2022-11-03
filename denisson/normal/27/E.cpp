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
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n;
vector<int> d;

bool pr(int a) {
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0)
			return 0;
	return 1;
}

ll dp[1001][101];

bool can(ll a, ll b) {
	return ((db)a * (db)b <= 1e18);
}

bool f;

ll bp(ll a, ll k) {
	if (k == 1)
		return a;
	if (k & 1) {
		ll q = bp(a, k - 1);
		if (!can(q, a))
			f = 0;
		return a * bp(a, k - 1);
	} else {
		ll q = bp(a, k / 2);
		if (!can(q, q))
			f = 0;
		return q * q;
	}
}

ll get(int kol, int uk) {
	if (kol == 1)
		return 1;
	if (dp[kol][uk] != -1)
		return dp[kol][uk];
	ll ans = LINF;
	for (int i = 1; i * i <= kol; i++) {
		if (kol % i == 0) {
			if (i > 1 && get(kol / i, uk + 1) != -2) {
				f = 1;
				ll ha = bp(d[uk], (i - 1));
				if (f && can(ha, get(kol / i, uk + 1))) {
					ll now = ha * get(kol / i, uk + 1);
					ans = min(ans, now);
				}
			}
			if (get(kol / (kol / i), uk + 1) != -2) {
				f = 1;
				ll ha = bp(d[uk], (kol / i - 1));
				if (f && can(ha, get(kol / (kol / i), uk + 1))) {
					ll now = ha * get(kol / (kol / i), uk + 1);
					ans = min(ans, now);
				}
			}
		}
	}
	if (ans == LINF)
		ans = -2;
	dp[kol][uk] = ans;
	return ans;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 101; j++)
			dp[i][j] = -1;

	cin >> n;
	if (n == 1)
		cout << 1, exit(0);
	for (int i = 2; i <= 100000 && d.size() < 2000; i++)
		if (pr(i))
			d.pub(i);
	cout << get(n, 0);

}