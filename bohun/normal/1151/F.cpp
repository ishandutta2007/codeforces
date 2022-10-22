#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 105, mod = 1e9 + 7;
int n, k, t[nax];
struct matrix{
	int t[nax][nax];
	matrix ()
	{
		memset(t, 0, sizeof(t));
	}
	matrix operator *(const matrix x)
	{
		matrix w = matrix();
		for(int i = 0; nax > i; ++i)
			for(int k = 0; nax > k; ++k)
				for(int j = 0; nax > j; ++j)
					w.t[i][j] = (w.t[i][j] + (ll) t[i][k] * x.t[k][j]) % mod;
		return w;
	}
};
int pt(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a  % mod;
		b /= 2;
	}
	return res;
}
void cat(matrix x)
{
	for(int i = 0; 5 > i; ++i)
	{
		for(int j = 0; 5 > j; ++j)
			cout << x.t[i][j] << " ";
		cout << endl;
	}
}
matrix pot(matrix a, ll k)
{
	matrix w = matrix();
	for(int i = 0; nax > i; ++i)
		w.t[i][i] = 1;
	while(k)
	{
		if(k & 1)
			w = w * a;
		a = a * a;
		k /= 2;
	}
	return w;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int zera = 0;
	for(int i = 1; n >= i; ++i)
		cin >> t[i], zera += (t[i] == 0);
	int e = 0;
	for(int i = 1; zera >= i; ++i)
		e += t[i] == 0;
	matrix a = matrix();
	// max(0, zera - (n - zera))
	for(int i = 0; zera >= i; ++i)
	{
		if(i - 1 >= 0)
		{
			a.t[i - 1][i] += (zera - (i - 1)) * (zera - (i - 1));
		}
		if(i >= 0)
		{
			a.t[i][i] +=  zera * (zera - 1) / 2 + (n - zera) * (n - zera - 1) / 2 + i * (zera - i) + (zera - i) * (n - zera - (zera - i));
		}
		if(i + 1 <= zera)
		{
			a.t[i + 1][i] += (i + 1) * (n - zera - (zera - (i + 1)));
		}
	}
	a = pot(a, k);
	matrix b = matrix();
	b.t[0][e] = 1;
	b = b * a;
	int ans = (ll) b.t[0][zera] * pt(pt(n * (n - 1) / 2, k), mod - 2) % mod;
	cout << ans;
	
	
			
	return 0;
}