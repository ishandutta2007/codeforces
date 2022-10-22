#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
const int nax = 6*1e6+9;
int t[nax][2];
int k = 0;
const int MAX = 2 * 1e5 + 9;
int a[MAX];
ll res = 0;
void add(int x)
{
	int g = 0;
	for(int i = 29; i >= 0; --i)
	{
		int bit = ((1 << i) & x);
		if(bit)
			bit = 1;
		if(t[g][bit] == 0)
		{
			k++;
			t[k][0] = t[k][1] = 0;
			t[g][bit] = k;
		}
		g = t[g][bit];
	}
}
ll mini(int x)
{
	ll ans = 0, g = 0;
	for(int i = 29; i >= 0; --i)
	{
		int bit = ((1 << i) & x);
		if(bit)
			bit = 1;
		if(t[g][bit] != 0)
			g = t[g][bit];
		else
		{
			ans += (1 << i);
			g = t[g][!bit];
		}
	}
	return ans;
}
void go(int bit, int l, int r)
{
	if(bit == -1)
		return ;
	int b = r + 1;
	for(int i = l; i <= r; ++i)
	{
		if((1 << bit) & a[i])
		{
			b = i;
			break;
		}
	}
	if(l <= b - 1)
		go(bit - 1, l, b - 1);
	if(b <= r)
		go(bit - 1, b , r);
	if(l <= b - 1 && b <= r)
	{
		k = 0;
		t[k][0] = t[k][1] = 0;
		for(int i = l; b > i; ++i)
			add(a[i]);
		ll wynik = 1e12;
		for(int i = b; r >= i; ++i)
			wynik = min(wynik, mini(a[i]));
		res += wynik;
	}
}
		
int main()
{
	int n;
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	go(29, 1, n);
	cout << res;
	
	
}