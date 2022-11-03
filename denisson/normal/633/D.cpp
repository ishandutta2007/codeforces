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
     
const int MAXN = 60007;
const int P = 79633;
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 8e8 + 23457;
const ll MOD2 = 1e9 + 9;

//
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
//

int n;
int a[1007];
map<int, int> was;

int go(int a, int b) {
	if (a == 0 && b == 0)
		re was[0];
	int q = 0;
	if (was[a + b] > 0) {
		was[a + b]--;
		q = 1 + go(b, a + b);
		was[a + b]++;
	}
	re q;
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
	forn(i, n)
		scanf("%d", &a[i]), was[a[i]]++;
	int ans = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j) {
			was[a[i]]--;
			was[a[j]]--;
			ans = max(ans, go(a[i], a[j]) + 2);
			was[a[i]]++;
			was[a[j]]++;
			if (ans == n)
				break;
		}
	cout << ans;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}