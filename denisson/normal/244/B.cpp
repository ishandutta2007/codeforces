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
const int P1 = 239017;
const int P2 = 353251;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

int n, ans = 0;
int d[11];
int was[11][11];
vec<int> s;

void check(int len, bool spec){
	if (d[0] == 0)
		re;
	if (len < s.size()){
		bool stop = 1;
		forn(i, len){
			if (d[i] != d[0])
				stop = 0;
		}
		if (stop != spec)
			re;
		ans++;
	} else {
		bool f = 0, stop = 1;
		forn(i, s.size()){
			if (d[i] > s[i] && !f)
				re;
			if (d[i] != d[0])
				stop = 0;
			if (d[i] < s[i])
				f = 1;
		}
		if (stop && !spec)
			re;
		ans++;
	}
}

void gen(int k, int len, int c1, int c2){
	if (k == len){
		check(len, 0);
	} else {
		forn(i, 2)
			if (!i){
				d[k] = c1;
				gen(k + 1, len, c1, c2);
			} else {
				d[k] = c2;
				gen(k + 1, len, c1, c2);
			}
	}
}

const bool is_testing = 0;
int main()
{
	srand(time(NULL));
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	int cop = n;
	while(cop){
		s.push_back(cop % 10);
		cop /= 10;
	}
	reverse(all(s));
	
	for (int len = 1; len <= s.size(); len++){
		if (len > 1){
			for (int c1 = 0; c1 <= 9; c1++)
				for (int c2 = 0; c2 <= 9; c2++)
					if (c1 != c2 && was[c1][c2] != len){
						gen(0, len, c1, c2);
						was[c1][c2] = len;
						was[c2][c1] = len;
					}
		}
		for (int c = 1; c <= 9; c++){
			forn(i, len)
				d[i] = c;
			check(len, 1);
		}
	}

	cout << ans;
	if (is_testing){
		cout << LN << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}