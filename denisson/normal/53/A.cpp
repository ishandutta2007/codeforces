#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <climits>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<string, int> psi;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<pii> vpii;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define for1(i, n) for (int i = 1; i <= (int)n; i++)
#define forq(i, s, t) for (int i = s; i <= t; i++)
#define ford(i, s, t) for (int i = s; i >= t; i--)
#define mk make_pair
#define inb push_back
#define outb pop_back
#define ump unordered_map
#define all(v) v.begin(), v.end()
#define X first
#define Y second
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define randint(x,y)
#define randlong(x, y)
#define TASK "dinner"
#define y1 amdknkgsdaasdwapgnpikn

const double eps = 1e-15;
const double pi = acos(-1.0);

const int MAXN = (int)1e5 + 7;
const int INF = (ll)2e9;
const ll LINF = (ll)8e18;
const int MOD = (ll)1e9 + 7;
const int CHASH = (ll)239017;

void gen();
int solve();

int main()
{
#ifdef _DEBUG
	gen();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("test.txt", "w", stderr);
	double tstart = TIME;
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("test.txt", "w", stderr);
#endif
	solve();
#ifdef _DEBUG
	double tend = TIME;
	cerr << tend - tstart << " s.\n";
#endif
	return 0;
}

void gen()
{
	freopen("input.txt", "a+", stdout);
	srand(time(0));
	return;
}

string s, ans;
int n;

int solve()
{
	bool f = 1;
	cin >> s;
	cin >> n;
	ans = "";
	forn(i, n)
	{
		string x;
		cin >> x;
		if (x.find(s) == 0)
		{
			if (ans != "")
				ans = min(ans, x);
			else
				ans = x;
			f = 0;
		}
	}
	if (f)
		ans = s;
	cout << ans;
	return 0;
}