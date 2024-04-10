#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-9;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1000000007;
const LL MAXN = 3e5 + 7;

int n;
int a[MAXN];
LL power[32];

struct node
{
	int id_l = -1;
	int id_r = -1;
	int l = 0;
	int r = 0;
};

vector<node> t;
int bits[32];

void add(int v)
{
	int x = v;
	int cnt = 0;
	FILL(bits, 0);
	while (x)
	{
		bits[cnt++] = x & 1;
		x >>= 1;
	}

	int now = 0;
	RFOR(i, 30, 0)
	{
		if (bits[i] == 0)
		{
			if (t[now].id_l != -1)
			{
				t[now].l++;
				now = t[now].id_l;
			}
			else
			{
				t[now].id_l = t.size();
				t.push_back({ -1, -1, 0, 0 });
				t[now].l++;
				now = t.size() - 1;
			}
		}
		else
		{
			if (t[now].id_r != -1)
			{
				t[now].r++;
				now = t[now].id_r;
			}
			else
			{
				t[now].id_r = t.size();
				t.push_back({ -1, -1, 0, 0 });
				t[now].r++;
				now = t.size() - 1;
			}
		}
	}
}

int get(int v)
{
	int x = v;
	int cnt = 0;
	FILL(bits, 0);
	while (x)
	{
		bits[cnt++] = x & 1;
		x >>= 1;
	}

	int now = 0;
	int ans = 0;
	RFOR(i, 30, 0)
	{
		if (bits[i] == 0)
		{
			if (t[now].l)
			{
				t[now].l--;
				now = t[now].id_l;
			}
			else
			{
				t[now].r--;
				ans += power[i];
				now = t[now].id_r;
			}
		}
		else
		{
			if (t[now].r)
			{
				t[now].r--;
				now = t[now].id_r;
			}
			else
			{
				t[now].l--;
				ans += power[i];
				now = t[now].id_l;
			}
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	power[0] = 1;
	FOR(i, 1, 32)
		power[i] = 2LL * power[i - 1];

	t.push_back({ -1, -1, 0, 0 });

	int x;
	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];
	
	FOR(i, 0, n)
	{
		cin >> x;
		add(x);
	}

	FOR(i, 0, n)
		cout << get(a[i]) << " ";

	cin >> n;
	return 0;
}