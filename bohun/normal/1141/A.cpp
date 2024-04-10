#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;



int main()
{
	int n, m, a, b, c, d;
	cin >> n >> m;
	a = b = c = d = 0;
	while(n % 2 == 0)
		{
			a++;
			n /= 2;
		}
	while(n % 3 ==	0)
	{
		b++;
		n /= 3;
	}
	while(m % 2 == 0)
	{
		c++;
		m /= 2;
	}
	while(m % 3 == 0)
	{
		d++;
		m /= 3;
	}
	if(a > c or b > d or m != n)
		cout << -1;
	else
		cout << d - b + c - a;
	return 0;
}