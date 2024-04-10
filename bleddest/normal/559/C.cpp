#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>

const int MOD = int(1e9) + 7;

using namespace std;

struct modInt
{
	int x;
	modInt() : x(0) {};
	modInt(int x) : x(x) {};
};

modInt operator +(const modInt& x, const modInt& y)
{
	int z = x.x + y.x;
	while (z >= MOD)
		z -= MOD;
	while (z < 0)
		z += MOD;
	return modInt(z);
}

modInt operator -(const modInt& x, const modInt& y)
{
	int z = x.x - y.x;
	while (z >= MOD)
		z -= MOD;
	while (z < 0)
		z += MOD;
	return modInt(z);
}

modInt operator *(const modInt& x, const modInt& y)
{
	return modInt((x.x * 1ll * y.x) % MOD);
}

modInt operator ^(const modInt& x, const modInt& y)
{
	modInt res(1);
	modInt xx = x;
	int yx = y.x;
	while (yx > 0)
	{
		if (yx % 2 == 1)
			res = res * xx;
		xx = xx * xx;
		yx /= 2;
	}
	return res;
}

modInt operator /(const modInt& x, const modInt& y)
{
	return x * (y ^ (MOD - 2));
}

bool operator <(const modInt& x, const modInt& y)
{
	return x.x < y.x;
}

ostream& operator <<(ostream& out, const modInt& x)
{
	return out << x.x;
}

const int N = 200043;

modInt fact[N];
modInt rfact[N];

void precalc()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = i * fact[i - 1];
	for (int i = 0; i < N; i++)
		rfact[i] = 1 / fact[i];
}

modInt C(int n, int k)
{
	if (n < 0 || k < 0 || n < k)
		return 0;
	return fact[n] * rfact[k] * rfact[(n - k)];
}

modInt countPaths(const pair<int, int>& x, const pair<int, int>& y)
{
	if (x.first > y.first || x.second > y.second)
		return 0;
	return C(y.first - x.first + y.second - x.second, y.first - x.first);
}

int main()
{
	precalc();
	int h, w, n;
	cin >> h >> w >> n;
	vector<pair<int, int> > pts(n);
	for (int i = 0; i < n; i++)
		cin >> pts[i].first >> pts[i].second;
	pts.push_back({ h, w });
	sort(pts.begin(), pts.end());
	vector<modInt> cnt(n + 1);
	for (int i = 0; i <= n; i++)
	{
		cnt[i] = countPaths({ 1, 1 }, pts[i]);
		for (int j = 0; j < i; j++)
			cnt[i] = cnt[i] - countPaths(pts[j], pts[i]) * cnt[j];
	}
	cout << cnt[n] << endl;
	return 0;
}