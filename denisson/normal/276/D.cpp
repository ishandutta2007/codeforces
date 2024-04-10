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
//
#define read(x) scanf("%d", &x)
#define write(x) printf("%d", x)
#define writeln(x) printf("%d\n", x)
#define wp(x) cout << x.first << ' ' << x.second << '\n';
#define wm(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' '; cout << LN;
#define read2(x, y) scanf("%d %d", &x, &y)
//
#define sqr(x) x*x
#define clr(a, x) memset(a, x, sizeof(a));
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
#define TASK "sum"   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
bool in(int k, int x1, int x2) {re (k >= x1 && k <= x2);}

const int MAXN = 60007;
const ll MOD = 1e9 + 7;

ll l, r;
ll dp[70][2][2][2][2];
str s1 = "", s2 = "";

ll get(int p, bool fl1, bool fl2, bool fr1, bool fr2){
	if (p == s1.size())
		re 0;
	if (dp[p][fl1][fl2][fr1][fr2] != -1)
		re dp[p][fl1][fl2][fr1][fr2];
	int min1 = 0, max1 = 1;
	if (s1[p] == '1' && !fl1)
		min1 = 1;
	if (s2[p] == '0' && !fl2)
		max1 = 0;
	int min2 = 0, max2 = 1;
	if (s1[p] == '1' && !fr1)
		min2 = 1;
	if (s2[p] == '0' && !fr2)
		max2 = 0;
	ll ans = 0;
	for (int i = min1; i <= max1; i++)
		for (int j = min2; j <= max2; j++){
			ll now = 0;
			int v = i ^ j;
			if (v == 1)
				now = (1ll << ((int)s1.size() - p - 1));
			bool nfl1 = fl1, nfl2 = fl2, nfr1 = fr1, nfr2 = fr2;
			if (i == 1 && s1[p] == '0')
				nfl1 = 1;
			if (i == 0 && s2[p] == '1')
				nfl2 = 1;
			if (j == 1 && s1[p] == '0')
				nfr1 = 1;
			if (j == 0 && s2[p] == '1')
				nfr2 = 1;
			ans = max(ans, now + get(p + 1, nfl1, nfl2, nfr1, nfr2));
		}
	dp[p][fl1][fl2][fr1][fr2] = ans;
	re ans;
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> l >> r;
	forn(i, 61)
		if ((l >> i) & 1)
			s1 += '1';
		else
			s1 += '0';
	forn(i, 61)
		if ((r >> i) & 1)
			s2 += '1';
		else
			s2 += '0';
	reverse(all(s1));
	reverse(all(s2));
	forn(i, 65)
		forn(f1, 2)
			forn(f2, 2)
				forn(f3, 2)
					forn(f4, 2)
						dp[i][f1][f2][f3][f4] = -1;
	cout << get(0, 0, 0, 0, 0);
}