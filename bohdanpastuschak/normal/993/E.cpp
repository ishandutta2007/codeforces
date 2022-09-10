#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
#include <complex>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

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
const LL mod = 1e9 + 7;
const LL MAX = 2e5 + 47;

namespace FFT
{
	struct complex
	{
		LD x, y;
		complex() { x = y = 0; }
		complex(LD x, LD y) : x(x), y(y) { }
	};

	inline complex operator+(complex a, complex b) { return complex(a.x + b.x, a.y + b.y); }
	inline complex operator-(complex a, complex b) { return complex(a.x - b.x, a.y - b.y); }
	inline complex operator*(complex a, complex b) { return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline complex conj(complex a) { return complex(a.x, -a.y); }

	int base = 1;
	vector<complex> roots = { { 0, 0 },{ 1, 0 } };
	vector<int> rev = { 0, 1 };

	void ensure_base(int nbase)
	{
		if (nbase <= base)
			return;

		rev.resize(1 << nbase);
		FOR(i, 0, 1 << nbase)
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

		roots.resize(1 << nbase);
		while (base < nbase)
		{
			LD angle = 2.0 * PI / (1 << (base + 1));
			FOR(i, 1 << (base - 1), 1 << base)
			{
				roots[i << 1] = roots[i];
				LD angle_i = angle * (2 * i + 1 - (1 << base));
				roots[(i << 1) + 1] = complex(cos(angle_i), sin(angle_i));
			}

			base++;
		}
	}

	void fft(vector<complex>& a, int n = -1)
	{
		if (n == -1)
			n = a.size();

		int zeros = __builtin_ctz(n);
		ensure_base(zeros);

		int shift = base - zeros;
		FOR(i, 0, n)
			if (i < (rev[i] >> shift))
				swap(a[i], a[rev[i] >> shift]);

		for (int k = 1; k < n; k <<= 1)
		{
			for (int i = 0; i < n; i += 2 * k)
			{
				FOR(j, 0, k)
				{
					complex z = a[i + j + k] * roots[j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	vector<complex> fa, fb;

	void multiply(VLL&a, VLL&b, VLL& res)
	{
		int need = a.size() + b.size() - 1;
		int nbase = 0;

		while ((1 << nbase) < need)
			nbase++;

		ensure_base(nbase);
		int sz = 1 << nbase;

		if (sz > SZ(fa))
			fa.resize(sz);

		FOR(i, 0, sz)
		{
			int x = (i < SZ(a) ? a[i] : 0);
			int y = (i < SZ(b) ? b[i] : 0);
			fa[i] = complex(x, y);
		}

		fft(fa, sz);
		complex r(0, -0.25 / sz);
		FOR(i, 0, (sz >> 1) + 1)
		{
			int j = (sz - i) & (sz - 1);
			complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
			if (i != j)
				fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;

			fa[i] = z;
		}

		fft(fa, sz);
		res.resize(need);
		FOR(i, 0, need)
			res[i] = fa[i].x + 0.5;
	}
};
int n, x;
int a[MAX];
LL ans[MAX];

void solve(int l, int r)
{
	if (l == r)
	{
		ans[a[l]]++;
		return;
	}

	int m = (l + r) >> 1;
	int curr = 0;
	VLL x, y, z;

	RFOR(i, m + 1, l)
	{
		if (a[i])
		{
			x.push_back(curr);
			curr = 0;
		}

		++curr;
	}

	x.push_back(curr);
	curr = 0;

	FOR(i, m + 1, r + 1)
	{
		if (a[i])
		{
			y.push_back(curr);
			curr = 0;
		}

		++curr;
	}

	y.push_back(curr);
	FFT::multiply(x, y, z);
	FOR(i, 0, SZ(z))
		ans[i] += z[i];

	solve(l, m);
	solve(m + 1, r);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> x;
	FOR(i, 0, n)
	{
		cin >> a[i];
		if (a[i] < x)
			a[i] = 1;
		else
			a[i] = 0;
	}

	solve(0, n - 1);
	FOR(i, 0, n + 1)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}

	cin >> n;
	return 0;
}