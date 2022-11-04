#include <bits/stdc++.h>

using namespace std;

int mas[(int)2e5 + 10], arr[(int)2e5 + 10];
int mn[(int)8e5 + 10], dp[(int)2e5 + 10];

void init(int v, int l, int r)
{
	mn[v] = (int)1e9;
	if (r - l > 1)
	{
		int m = (l + r) / 2;
		init(2 * v + 1, l, m);
		init(2 * v + 2, m, r);
	}
}

int get(int v, int l, int r, int q, int w)
{
	if (l >= w || r <= q)
		return (int)1e9;
	if (q <= l && r <= w)
		return mn[v];
	int m = (l + r) / 2;
	return min(get(2 * v + 1, l, m, q, w), get(2 * v + 2, m, r, q, w));
}

void sett(int v, int l, int r, int q, int x)
{
	//cerr << v << " " << l << " "<< r << " " << q << " " << x << endl;
	mn[v] = min(mn[v], x);
	if (r - l > 1)
	{
		int m = (l + r) / 2;
		if (q < m)
			sett(2 * v + 1, l, m, q, x);
		else
			sett(2 * v + 2, m, r, q, x);
	}
}

void ad(int v, int l, int r, int q, int x)
{
	if (r - l == 1)
	{
		mn[v] += x;
		return;
	}
	int m = (l + r) / 2;
	if (q < m)
		ad(2 * v + 1, l, m, q, x);
	else
		ad(2 * v + 2, m, r, q, x);
	mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
}

void init2(int v, int l, int r)
{
	if (r - l == 1)
	{
		mn[v] = dp[l] + l;
		return;	
	}
	int m = (l + r) / 2;
	init2(2 * v + 1, l, m);
	init2(2 * v + 2, m, r);
	mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];	
		arr[i] = mas[i];
		dp[i] = 5 * n;
	}
	int kek = 5 * n;
	sort(arr, arr + n);
	int m = unique(arr, arr + n) - arr;
	init(0, 0, m);
	for (int i = 2 * n - 1, j = n - 1; i >= 0; j--, i--)
	{
		if (j < 0)
			j += n;
		int x = lower_bound(arr, arr + m, (mas[j] + 1) / 2) - arr;
		dp[j] = min(dp[j], get(0, 0, m, 0, x) - i);
		//cout << dp[j] << " ";
		kek = min(kek, dp[j]);
		sett(0, 0, m, lower_bound(arr, arr + m, mas[j]) - arr, i);
	}
//	cout << endl;
	if (kek > 2 * n)
	{
		for (int i = 0; i < n; i++)
			cout << -1 << " ";
		cout << endl;
		return 0;
	}
	init2(0, 0, n);
	int add = 0;
	for (int i = 0; i < n; i++)
	{
		cout << get(0, 0, n, 0, n) + add << " ";
		ad(0, 0, n, i, n);
		add--;
	}
	cout << endl;
	return 0;
}