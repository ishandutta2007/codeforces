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

str s1, s2;
ll h1[1507], deg1[1507], h2[1507], deg2[1507];
int k;
set< pair<ll, ll> > se;

void geth(str s){
	h1[0] = 0, h2[0] = 0, deg1[0] = 1, deg2[0] = 1;
	forn(i, s.size()){
		h1[i + 1] = (h1[i] * P1 + s[i]) % MOD;
		h2[i + 1] = (h2[i] * P2 + s[i]) % MOD2;
		deg1[i + 1] = (deg1[i] * P1) % MOD;
		deg2[i + 1] = (deg2[i] * P2) % MOD2;
	}
}

pair <ll, ll> get_hash(int l, int r){
	ll ans = h1[r + 1] - (h1[l] * deg1[r - l + 1]) % MOD;
	ll ans2 = h2[r + 1] - (h2[l] * deg2[r - l + 1]) % MOD2;
	while (ans < 0)
		ans += MOD;
	while (ans2 < 0)
		ans2 += MOD2;
	re mp(ans, ans2);
}

bool bad(char c){
	re (s2[c - 'a'] == '0');
}

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> s1 >> s2 >> k;
	geth(s1);
	for (int l = 0; l < s1.size(); l++){
		int was = 0;
		for (int r = l; r < s1.size(); r++){
			if (bad(s1[r]))
				was++;
			if (was > k)
				break;
			se.insert(get_hash(l, r));
		}
	}
	cout << se.size();
}