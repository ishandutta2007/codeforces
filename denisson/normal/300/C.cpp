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

int a, b, n;
ll ans = 0;

bool ok(ll q){
	while (q){
		int q1 = q % 10;
		if (q1 != a && q1 != b)
			re 0;
		q /= 10;
	}
	re 1;
}

ll bin(ll a, ll k){
	if (k == 1)
		re a;
	if (k % 2 == 0){
		ll q = bin(a, k / 2);
		re (q * q) % MOD;
	} else {
		re (bin(a, k - 1) * a) % MOD;
	}
}

vec < pair<int ,int> > q;
ll fact[1000007], inv[1000007];

const bool is_testing = 0;
int main()
{
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> a >> b >> n;
	ll sum = b * n;
	forn(i, n + 1){
		if (ok(sum))
			q.pb(mp(i, n - i));
		sum -= b - a;
	}
	fact[1] = 1;
	for (int i = 2; i <= 1000003; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	forn(i, q.size()){
		ll q1 = fact[n];
		q1 = (q1 * bin(fact[q[i].XX], MOD - 2)) % MOD;
		q1 = (q1 * bin(fact[q[i].YY], MOD - 2)) % MOD;
		if (q[i].XX == 0 || q[i].YY == 0)
			ans = (ans + 1) % MOD;
		else
			ans = (ans + q1) % MOD;
	}
	cout << ans;
}