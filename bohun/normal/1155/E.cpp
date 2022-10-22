#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;
const int nax = 20;
const int mod = 1e6 + 3;
int pt(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return res;
}
void gaus(vector <vector <int> > a, vector <int> &ans)
{
	int n = a.size();
	int m = n + 1;
	for(int row = 0, col = 0; col < m && row < n; ++row, ++col)
	{

		int sel = row;
		for(int i = row; i < n; ++i)
			if(abs(a[i][col]) > abs(a[sel][col]))
				sel = i;
		for(int i = col; m > i; ++i)
			swap(a[sel][i], a[row][i]);
		int odw = pt(a[row][col], mod - 2);
		for(int i = col; m > i; ++i)
			a[row][i] = (ll) a[row][i] * odw % mod;
		for(int i = 0; n > i; ++i)
		{
			if(a[i][col] == 0 || i == row)
				continue;
			int w = (ll) a[i][col] * pt(a[row][col], mod - 2) % mod;
			for(int j = col; m > j; ++j)
				a[i][j] = (a[i][j] - (ll) a[row][j] * w % mod + mod) % mod;
		}
	}
	for(int i = 0; n > i; ++i)
	{
		ans[i] = a[i][m - 1];
	}
}
int daj(int x)
{
	cout << "? " << x << endl;
	fflush(stdout);
	int y;
	cin >> y;
	return y;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	n = 11;
	vector <vector <int>> v(n, vector <int> (n + 1, 0));
	vector <int> b(n);
	for(int i = 0; n > i; ++i)
		for(int j = 0; n + 1 > j; ++j)
		{
			if(j < n)
				v[i][j] = pt(i + 1, j);
			else
				v[i][j] = daj(i + 1);
		}
	gaus(v, b);
	for(int i = 0; mod > i; ++i)
	{
		int sum = 0;
		for(int j = 0; 10 >= j; ++j)
			sum = (sum + (ll) pt(i, j) * b[j] % mod) % mod;
		if(!sum)
		{
			cout << "! " << i << endl;
			return 0;
		}
	}
	cout << "! " << -1;
	
	return 0;
}