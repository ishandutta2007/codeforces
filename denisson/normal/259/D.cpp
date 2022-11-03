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

int n;
vec<int> s;
ll ans = 0;
int d[8], kol[11], now[11];
int dp[15][2][15];

int rec(int p, bool f, int kol){
	if (kol < 0)
		re 0;
	if (p == s.size() && kol == 0)
		re 1;
	if (p == s.size() && kol != 0)
		re 0;
	if (dp[p][f][kol] != -1)
		re dp[p][f][kol];
	if (f){
		int ans = 0;
		for (int c = 0; c <= 9; c++){
			if (c == 4 || c == 7){
				ans += rec(p + 1, 1, kol - 1);
			} else {
				ans += rec(p + 1, 1, kol);
			}
		}
		dp[p][f][kol] = ans;
		re ans;
	} else {
		int ans = 0;
		for (int c = 0; c <= s[p]; c++){
			if (c == 4 || c == 7){
				ans += rec(p + 1, c != s[p], kol - 1);
			} else {
				ans += rec(p + 1, c != s[p], kol);
			}
		}
		dp[p][f][kol] = ans;
		re ans;
	}
}

void check(){
	forn(i, 10)
		now[i] = 0;
	ll res = 1;
	forn(i, 7){
		int need = d[i];
		res = (res * (kol[need] - now[need])) % MOD;
		now[need]++;
	}
	ans = (ans + res) % MOD;
}

void go(int v, int sum){
	if (v == 7){
		check();
		re;
	}
	if (v == 0){
		for (int i = 1; i <= 9; i++){
			d[v] = i;
			go(v + 1, i - 1);
		}
	} else {
		for (int i = 0; i <= sum; i++){
			d[v] = i;
			go(v + 1, sum - i);
		}
	}
}

const bool is_testing = 0;
int main()
{
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
	forn(i, 13)
		forn(j, 13)
			forn(f, 2)
				dp[i][f][j] = -1;
	forn(i, 10)
		kol[i] = rec(0, 0, i);
	kol[0]--;
	go(0, 0);
	cout << ans;
	if (is_testing){
		cout << LN << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}