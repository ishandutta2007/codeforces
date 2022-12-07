#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 111111;
int l, r, q;
int cnt[maxN], la[maxN], ra[maxN], Lb[maxN], Rb[maxN];
int va[maxN], vb[maxN];
i64 t, xL, xR;

typedef array<i64, 2> segment;
segment lb[maxN], rb[maxN];
vector<segment> cond;

segment operator+(const segment &a, const segment &b)
{
	return {a[0] + b[0], a[1] + b[1]};
}
segment operator-(const segment &a, const segment &b)
{
	return {a[0] - b[0], a[1] - b[1]};
}
void solve(vector<int> a, vector<segment> b, segment add)
{
	i64 ls = 0;
	segment rs = add;
	int lc = l;
	for (int i = 0; i < r; i++)
		rs = rs + b[i];
	for (int i = 0; i <= r; i++)
		cnt[i] = 0;
	for (auto x : a)
		cnt[x]++;

	for (int i = 0; i <= r; i++)
	{
		cond.push_back(segment{0ll, ls} + rs);
		rs = rs - b[i];
		lc -= cnt[i];
		ls += lc;
	}
}

i64 ceild(i64 x, i64 y)
{
	if (x % y == 0 || x < 0)
		return x / y;
	return x / y + 1;
}

i64 floord(i64 x, i64 y)
{
	if (x % y == 0 || x > 0)
		return x / y;
	return x / y - 1;
}

bool check(int p, int v = -1)
{
	i64 ls = 0;
	segment rs{0, 0};
	xL = 0;
	xR = l;
	if (v == -1)
	{
		for (int i = 0; i < r; i++)
		{
			rb[i] = {0, Rb[i]};
			lb[i] = {0, Lb[i]};
			if (i < p)
			{
				lb[i] = {1, 0};
				rb[i] = {1, 0};
			}
		}
	}
	else
	{
		for (int i = 0; i < r; i++)
		{
			rb[i] = {0, min(Rb[i], v)};
			lb[i] = {0, Lb[i]};
		}
		xR = v;
	}
	for (int i = 0; i < p; i++)
	{
		xL = max(xL, (i64)Lb[i]);
		xR = min(xR, (i64)Rb[i]);
	}
	for (int i = 0; i < l; i++)
		ls += la[i];

	for (int i = 0; i < r; i++)
		rs = rs + lb[i];
	if (ls > t)
		return 0;
	// rs[0] * X + rs[1]<=t
	if (rs[0] > 0)
		xR = min(xR, floord(t - rs[1], rs[0]));
	else
	{
		if (rs[1] > t)
			return 0;
	}
	cond.clear();
	solve(vector<int>(ra, ra + l), vector<segment>(rb, rb + r), {0, 0});
	solve(vector<int>(la, la + l), vector<segment>(rb, rb + r), segment{0, t} - segment{0, ls});
	solve(vector<int>(ra, ra + l), vector<segment>(lb, lb + r), segment{0, t} - rs);
	solve(vector<int>(la, la + l), vector<segment>(lb, lb + r), segment{0, 2 * t} - segment{0, ls} - rs);
	for (auto y : cond)
	{
		//cout << y[0] << " " << y[1] << endl;
		//y[0] * X + y[1]>=t
		if (y[0] == 0)
		{
			if (y[1] < t)
				return 0;
		}
		else if (y[0] > 0)
		{
			// X>=(t-y[1])/y[0]
			xL = max(xL, ceild(t - y[1], y[0]));
		}
		else
		{
			//X<=(y[1]-t)/(-y[0])
			xR = min(xR, floord(y[1] - t, -y[0]));
		}
	}
	//cout << "check " << p << " " << xL << " " << xR << endl;
	if (xL > xR)
		return 0;
	if (v == -1)
		return check(p, xR);
	else
		return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> l >> r;
	for (int i = 0; i < l; i++)
	{
		cin >> la[i] >> ra[i];
	}
	cin >> q;
	for (int i = 0; i < r; i++)
	{
		Lb[i] = 0;
		Rb[i] = l;
	}
	for (int i = 0; i < q; i++)
	{
		int rank, score;
		cin >> rank >> score;
		--rank;
		Lb[rank] = score;
		Rb[rank] = score;
	}
	for (int i = 1; i < r; i++)
	{
		Rb[i] = min(Rb[i], Rb[i - 1]);
	}
	for (int i = r - 2; i >= 0; i--)
	{
		Lb[i] = max(Lb[i], Lb[i + 1]);
	}
	cin >> t;
	if (!check(1))
	{
		cout << "-1 -1\n";
		return 0;
	}
	int peoL = 1, peoR = r + 1;
	while (peoL + 1 < peoR)
	{
		int mid = (peoL + peoR) >> 1;
		if (check(mid))
			peoL = mid;
		else
			peoR = mid;
	}
	check(peoL);
	cout << peoL << " " << xR << "\n";
}