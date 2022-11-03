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
const int l = 20;

struct matr{
	ll a[60][60];
	matr (){
		forn(i, 59)
			forn(j, 59)
				a[i][j] = 1;
	}
};

ll n, m, k;
matr a;

int opr(char c){
	if (c >= 'a' && c <= 'z')
		re (c - 'a');
	re (26 + c - 'A');
}

matr umn(matr a, matr b){
	matr ans;
	forn(i, m){
		forn(j, m){
			ans.a[i][j] = 0;
			forn(k, m)
				ans.a[i][j] = (ans.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
		}
	}
	re ans;
}

matr bin(matr q, ll k){
	if (k == 1)
		re q;
	if (k % 2 == 0){
		matr s = bin(q, k / 2);
		re umn(s, s);
	} else {
		re umn(q, bin(q, k - 1));
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
	cin >> n >> m >> k;
	forn(i, k){
		char c1, c2;
		cin >> c1 >> c2;
		a.a[opr(c1)][opr(c2)] = 0;
	}
	if (n == 1){
		cout << m;
		exit(0);
	}
	matr d = bin(a, n - 1);
	ll ans = 0;
	forn(i, m)
		forn(j, m)
			ans = (ans + d.a[i][j]) % MOD;
	cout << ans;
	if (is_testing){
		cout << LN << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}