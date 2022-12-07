#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 123456;
int l[maxN], a[maxN], n, m, delt[maxN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l[i];
	}
	int pos = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		int npos = max(pos + 1, l[i]);
		delt[i] = npos - pos;
		pos = npos;
		if (pos > n)
		{
			cout << "-1\n";
			return 0;
		}
	}
	int g = n - pos;
	for (int i = 0; i < m; i++)
	{
		int c = min(g, l[i] - delt[i]);
		delt[i] += c;
		g -= c;
	}
	if (g > 0)
	{
		cout << "-1\n";
		return 0;
	}
	pos = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		pos += delt[i];
		a[i] = pos - l[i] + 1;
	}
	for (int i = 0; i < m; i++)
	{
		cout << a[i] << " ";
	}
}