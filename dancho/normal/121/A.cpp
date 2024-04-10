#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int l, r, j;
long long nums[100020];

long long nex( long long x )
{
	for ( int i = 1; i <= j; i++ )
	{
		if ( nums[i] >= x )
			return nums[i];
	}
	return nums[j];
}

int main()
{
	int i, k, le;
	long long ans = 0;
	
	scanf( "%d %d", &l, &r );
	
	j = 0;
	for ( le = 1; le < 10; le++ )
	{
		for ( k = 0; k < (1<<le); k++ )
		{
			j++;
			nums[j] = 0;
			for ( i = 0; i < le; i++ )
			{
				if ( k&(1<<i) )
					nums[j] = nums[j]*10 + 7;
				else nums[j] = nums[j]*10 + 4;
			}
		}
	}
	j++;
	nums[j] = 4444444444LL;
	sort( nums + 1, nums + j + 1 );
	
	for ( i = l; i <= r; i = k )
	{
		k = min( nex( i ), (long long)r ) + 1;
		ans = ans + (k-i)*nex( i );
	}
	cout << ans << endl;
	return 0;
}