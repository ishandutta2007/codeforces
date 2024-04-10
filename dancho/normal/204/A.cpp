#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long d10[64];

long long solve( long long x )
{
	long long fd, dcnt;
	long long ans = 0;
	if ( x <= 9 ) return x;
	if ( x >= 10 ) ans += 9;
	for ( dcnt = 1; dcnt <= 100; dcnt++ )
	{
		for ( fd = 1; fd <= 9; fd++ )
		{
			if ( (fd+1LL)*d10[dcnt] <= x )
			{
				ans = ans + d10[dcnt-1];
			}
			else break;
		}
		if ( fd <= 9 ) break;
	}
	
//	cout << dcnt << " " << fd << " " << ans << endl;
	
	if ( x % 10 < fd ) ans--;
	long long add = 1, mul = 1;
	x = x / 10;
	while ( x > fd )
	{
		add = add + (x%10)*mul;
		mul = mul * 10;
		x = x / 10;
	}
	ans += add;
	return ans;
}

int main()
{
	long long l, r;
	
	d10[0] = 1;
	for (int i = 1; i < 30; i++)
	{
		d10[i] = d10[i-1]*10;
	}
	
	cin >> l >> r;
//	cout << r << " " << solve( r ) << endl;
//	cout << l-1 << " " << solve( l-1 ) << endl;
	cout << solve( r ) - solve( l-1 ) << endl;
	return 0;
}