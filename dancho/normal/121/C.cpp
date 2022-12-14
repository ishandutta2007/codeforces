#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n, K, j;
long long nums[100020];
long long f[16];
int a[16];
int us[16];

bool findN( int x )
{
	for ( int i = 1; i <= j; i++ )
		if ( nums[i] == x ) return 1;
	return 0;
}

long long nex( long long x )
{
	for ( int i = 1; i <= j; i++ )
	{
		if ( nums[i] > x )
			return nums[i];
	}
	return nums[j];
}

int main()
{
	int i, k, le;
	int ans = 0;
	
	scanf( "%d %d", &n, &K );

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
	
	//cout << "op\n";
	ans = 0;
	for ( i = 1; i <= j; i++ )
	{
		if ( nums[i] + 13 <= n )
		{
			ans++;
		}
		else break;
	}
	
	//cout << "hA\n";
	f[0] = 1;
	us[0] = 1;
	for ( i = 1; i <= 13; i++ )
	{
		a[i] = i;
		f[i] = f[i-1] * i;
		us[i] = 0;
	}
	
	//cout << "ST " << endl;
	
	if ( n <= 13 )
	{
		if ( f[n] < K )
		{
			printf( "-1\n" );
			return 0;
		}
	}
	if ( f[13] < K )
	{
		printf( "-1\n" );
		return 0;
	}
	K--;
	for ( i = 1; i <= 13; i++ )
	{
		//cout << "OP " << i << endl;
		k = 0;
		while ( (long long)k*f[13-i] <= K )
			k++;
		k--;
		K = K - f[13-i]*k;
		for ( int l = 1; l <= 13; l++ )
		{
			if ( us[l] == 0 )
			{
				if ( k == 0 )
				{
					a[i] = l;
					us[l] = 1;
					break;
				}
				k--;
			}
		}
	}
	
	//cout << ans << endl;
	for ( i = 1; i <= 13; i++ )
	{
		if ( ( findN( a[i]-13+n ) == 1 ) && ( findN( i-13+n ) == 1 ) )
		{
			ans++;
		}
	}
	
	cout << ans << endl;
		
	return 0;
}