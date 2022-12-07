#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

const int maxN = 123456;

u64 mulpw2[100][100];

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		i64 n;
		cin >> n;
		i64 group = (n - 1) / 3, pos = (n - 1) % 3;
		i64 l = 1;
		while (1)
		{
			i64 r = 2 * l - 1;
			if (group < (r - l + 1))
			{
				i64 u = group + l;
				i64 v = multiply(group, 2) + 2 * l;
				i64 w = u ^ v;
				if (pos == 0)
					cout << u << "\n";
				else if (pos == 1)
					cout << v << "\n";
				else
					cout << w << "\n";
				break;
			}
			else
			{
				group -= (r - l + 1);
				l = l * 4;
			}
		}
	}
	/*
	for (cin >>)
		set<int> s;
	for (int rd = 0; rd < 100; rd++)
	{
		int x = 1;
		while (s.count(x))
			x++;
		int y = x + 1;
		while (s.count(y) || s.count(x ^ y))
			y++;
		int u = x - 64;
		printf("%d %d %d %d %d %d\n", x, y, x ^ y, x - 64, y - 128, u ^ (u << 1));
		s.insert(x);
		s.insert(y);
		s.insert(x ^ y);
	}*/
}