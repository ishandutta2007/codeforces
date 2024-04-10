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
#define write(x) printf("%d", &x)
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
const ll MOD = 1e9 + 9;

struct matr{
	ll a[2][2];
	matr (){
		a[0][0] = 0;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = 0;
	}
	matr (ll a1, ll b, ll c, ll d){
		a[0][0] = a1;
		a[0][1] = b;
		a[1][0] = c;
		a[1][1] = d;
	}
};

matr umn(matr a, matr b){
	matr ans;
	forn(i, 2)
		forn(j, 2){
			forn(k, 2){
				ans.a[i][j] = (ans.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD ) % MOD;
			}
		}
	re ans;
}

ll n, m, k;
matr q = matr(2, 2, 0, 1);

matr bin(matr a, int k){
	if (k == 1)
		re a;
	if (k % 2 == 0){
		matr p = bin(a, k / 2);
		re umn(p, p);
	} else {
		re umn(a, bin(a, k - 1));
	}
}

const bool is_testing = 0;
int main()
{
	srand(3252);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n >> m >> k;
	ll k1 = n / k;
	ll ost = n % k;
	ll ma = n - k1;
	if (m <= ma){
		cout << m;
	} else {
		ll d = m - ma;
		ll su = m - d * k;
		ll ans = 0;
		if (d > 0){
			if (d == 1){
				ans = 2;
			} else {
				matr s = bin(q, d - 1);
				ans = (s.a[0][1] + (s.a[0][0] * (ll)2) % MOD) % MOD;
			}
			ans = (ans * k) % MOD;
		}
		ans = (ans + su) % MOD;
		cout << ans;
	}
}