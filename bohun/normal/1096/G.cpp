#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int mod = 998244353;
int gen = 5;
int n, k;
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
void nnt(vector <int> &a, bool inv)
{
	int n = ss(a);
	for(int i = 1, j = 0; n > i; ++i)
	{
		int bit = n / 2;
		while(bit & j)
			j ^= bit, bit /= 2;
		j ^= bit;
		if(i < j)
			swap(a[i], a[j]);
	}
	for(int len = 2; n >= len; len *= 2)
	{
		int root = pt(gen, (mod - 1) / len);
		if(inv)
			root = pt(root, mod - 2);
		for(int b = 0; n > b; b += len)
		{
			int e = 1;
			for(int i = 0; len / 2 > i; ++i)
			{
				int u = a[i + b];
				int w = (ll) a[i + b + len / 2] * e % mod;
				a[i + b] = (u + w < mod ? u + w : u + w - mod);
				a[i + b + len / 2] = (u - w >= 0 ? u - w : u - w + mod);
				e = (ll) e * root % mod;
			}
		}
	}
	int odw = pt(n, mod - 2);
	if(inv)
	{
		for(int i = 0; n > i; ++i)
			a[i] = (ll) a[i] * odw % mod;
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	int N = (1 << 20);
	vector <int> A(N);
	for(int i = 1; k >= i; ++i)
	{
		int b;
		scanf("%d", &b);
		A[b]++;
	}
	nnt(A, 0);
	for(int i = 0; N > i; ++i)
		A[i] = pt(A[i], n / 2);
	nnt(A, 1);
	int ans = 0;
	for(int i = 0; N > i; ++i)
		ans = (ans + (ll) A[i] * A[i]) % mod;
	printf("%d", ans);
	
		
	return 0;
}