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
const ll MOD = 1e9 + 7;

ll n;
ll a[1000007], t[6*1000007], ans[1000007], anss = 0;
map <int, int> was;

void up(ll v, ll vl, ll vr, ll pos)
{
	if (vr < pos || vl > pos)
		return;
	if (vl == vr)
	{
		if (vl == pos)
			t[v]++;
	}
	else
	{
		ll vm = (vl + vr) / 2;
		up(v * 2 + 1, vl, vm, pos);
		up(v * 2 + 2, vm + 1, vr, pos);
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

ll get(ll v, ll vl, ll vr, ll l, ll r)
{
	if (vr < l || vl > r)
		re 0;
	if (vl >= l && vr <= r)
		re t[v];
	ll vm = (vl + vr) / 2;
	ll q1 = get(v * 2 + 1, vl, vm, l, r);
	ll q2 = get(v * 2 + 2, vm + 1, vr, l, r);
	re q1 + q2;
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
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
	{
		was[a[i]]++;
		ans[i] = was[a[i]];
	}
	was.clear();
	was[a[n - 1]] = 1;
	up(0, 0, n, 1);
	for (int i = n - 2; i >= 0; i--)
	{
		ll q = ans[i];
		anss += get(0, 0, n, 0, q - 1);
		up(0, 0, n, ++was[a[i]]);
	}
	cout << anss;
}