#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long x, y, m;

int main()
{
	cin >> x >> y >> m;
	if ( x >= m || y >= m )
	{
		cout << 0 << endl;
		return 0;
	}
	if ( x <= 0 && y <= 0 )
	{
		cout << -1 << endl;
		return 0;
	}
	
	if ( x > y )
		swap( x, y );
	long long k = y;
	long long op = 0;
	
	while ( x + y < 0 )
	{
		long long j = 1;
		k = y;
		while ( x + k < 0 )
		{
			k = k*2;
			j = j * 2;
		}
		k = k / 2;
		j = j / 2;
		if ( j < 10 )
			break;
		op += j;
		x += k;
	}
	
	while ( ( x < m && y < m ) )
	{
		if ( x > y )
			swap( x, y );
		x = x + y;
		op++;
	}
	
	cout << op << endl;
	return 0;
}