#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;

u64 mulpw2[100][100];
u64 pretable[10][10][266][266];
u64 pretable2[10][266];

u64 multiply_powers_of_2(int a, int b);

u64 multiply(u64 a, u64 b)
{
	u64 ans = 0;
	for (int p1 = 0; p1 < 64; p1++)
		if (a & (1ull << p1))
			for (int p2 = 0; p2 < 64; p2++)
				if (b & (1ull << p2))
					ans = ans ^ multiply_powers_of_2(p1, p2);
	return ans;
}

u64 multiply_powers_of_2(int a, int b)
{
	if (a == 0 || b == 0)
		return 1ull << (a + b);
	if (mulpw2[a][b] != 0)
		return mulpw2[a][b];
	u64 ans = 1, e = 1;
	for (int i = 0; i < 16; i++)
	{
		if (((a ^ b) >> i) & 1)
			e *= 1ull << (1 << i);
		else if ((a >> i) & 1)
			ans = multiply(ans, 3 * (1ull << (1 << i)) / 2);
	}
	return mulpw2[a][b] = multiply(ans, e);
}

u64 fmultiply(u64 a, u64 b)
{
	u64 ans = 0;
	for (int p1 = 0; p1 < 8; p1++)
		for (int p2 = 0; p2 < 8; p2++)
		{
			ans ^= pretable[p1][p2][(a >> (8 * p1)) & 255][(b >> (8 * p2)) & 255];
		}
	//assert(ans == multiply(a, b));
	return ans;
}
u64 power(u64 a, u64 b)
{
	u64 ans = 1;
	while (b)
	{
		if (b & 1)
			ans = fmultiply(ans, a);
		a = fmultiply(a, a);
		b >>= 1;
	}
	return ans;
}

u64 order = ~0ull;
int factor[] = {3, 5, 17, 257, 641, 65537, 6700417};
u64 CRT[] = {12297829382473034410ull, 7378697629483820646ull, 1085102592571150095ull, 2296870857426870240ull, 16979062407938588850ull, 4611615650756935680ull, 10691053700478254925ull};
u64 g = 2170067843377617395ull;
u64 a[500];
u64 x[10][500], ans[500];
u64 base;
int t;

void fastmulinit(u64 a)
{
	base = a;
	for (int s1 = 0; s1 < 8; s1++)
	{
		u64 tmps[10];
		for (int b = 0; b < 8; b++)
			tmps[b] = multiply(a, 1ull << (s1 * 8 + b));
		for (u64 s2 = 0; s2 < 256; s2++)
		{
			pretable2[s1][s2] = 0;
			for (int b = 0; b < 8; b++)
				if (s2 & (1 << b))
				{
					pretable2[s1][s2] ^= tmps[b];
				}
			//assert(pretable2[s1][s2] == multiply(a, s2 << (8 * s1)));
		}
	}
}
u64 fastmul(u64 b)
{
	u64 ans = 0;
	for (int p1 = 0; p1 < 8; p1++)
	{
		ans ^= pretable2[p1][(b >> (8 * p1)) & 255];
	}
	assert(ans == multiply(base, b));
	return ans;
}

void solve(int id)
{
	u64 gpr = power(g, order / factor[id]);
	int T = sqrt(factor[id] * 2 * t) + 1;
	int bs = factor[id] / T + 1;
	u64 gT = 1;
	u64 gbs = power(gpr, bs);
	fastmulinit(gbs);
	unordered_map<u64, int> tab;
	for (int i = 0; i < T; i++)
	{
		tab[gT] = i * bs;
		//cout << "giant step " << i << " " << gT << endl;
		gT = fastmul(gT);
	}
	fastmulinit(gpr);
	for (int i = 0; i < 2 * t; i++)
	{
		u64 h = power(a[i], order / factor[id]);
		if (h == 1)
		{
			x[id][i] = 0;
		}
		else
		{
			u64 hT = h;
			int step = 0;
			while (1)
			{
				if (tab.count(hT))
				{
					x[id][i] = tab[hT] - step;
					break;
				}
				hT = fastmul(hT);
				step++;
			}
			x[id][i] %= factor[id];
		}
		assert(power(gpr, x[id][i]) == h);
	}
}
typedef unsigned int u32;

u64 add(u64 a, u64 b)
{
	u32 a_hi = a >> 32, a_lo = u32(a);
	u32 b_hi = b >> 32, b_lo = u32(b);
	u64 p1 = u64(a_hi) + b_hi;
	u64 p2 = u64(a_lo) + b_lo;
	p1 += p2 >> 32;
	p2 = u32(p2);
	u64 car = p1 >> 32;
	p1 = u32(p1);
	return (p1 << 32) + p2 + car;
}
u64 mul(u64 a, u64 b)
{
	u32 a_hi = a >> 32, a_lo = u32(a);
	u32 b_hi = b >> 32, b_lo = u32(b);
	u64 p01 = u64(a_lo) * b_lo;
	u64 p12 = u64(a_hi) * b_lo + u32(p01 >> 32);
	u32 t_hi = p12 >> 32, t_lo = p12;
	p12 = u64(a_lo) * b_hi + t_lo;
	u64 p23 = u64(a_hi) * b_hi + u32(p12 >> 32) + t_hi;
	return add(u32(p01) | (p12 << 32), p23);
}

u64 gcd(u64 a, u64 b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			for (u64 s1 = 0; s1 < 256; s1++)
			{
				u64 tmps[10];
				for (int b = 0; b < 8; b++)
					tmps[b] = multiply(s1 << (8 * i), 1ull << (8 * j + b));
				for (u64 s2 = 0; s2 < 256; s2++)
					for (int b = 0; b < 8; b++)
						if (s2 & (1 << b))
						{
							pretable[i][j][s1][s2] ^= tmps[b];
						}
			}
		}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a[2 * i] >> a[2 * i + 1];
	}
	for (int i = 0; i < 7; i++)
	{
		solve(i);
	}

	for (int i = 0; i < 2 * t; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			ans[i] = add(ans[i], mul(CRT[j], x[j][i]));
		}
	}
	for (int i = 0; i < t; i++)
	{
		u64 p = ans[2 * i], q = ans[2 * i + 1];
		u64 d = gcd(p, order);
		if (q % d != 0)
		{
			cout << -1 << endl;
			continue;
		}
		u64 phi = 1;
		for (int j = 0; j < 7; j++)
			if ((order / d) % factor[j] == 0)
				phi = phi * (factor[j] - 1);
		u64 inv = 1;
		u64 b = p / d;
		phi -= 1;
		while (phi)
		{
			if (phi & 1)
				inv = mul(inv, b);
			b = mul(b, b);
			phi /= 2;
		}
		u64 r = mul(q / d, inv) % (order / d);
		//cout << p << " " << r << " " << q << endl;
		assert(power(a[2 * i], r) == a[2 * i + 1]);
		cout << r << endl;
	}
}