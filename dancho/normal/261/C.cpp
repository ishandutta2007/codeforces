#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long com[64][64];

long long gc( int n, int k )
{
	if ( n < k ) return 0;
	if ( n == k ) return 1;
	if ( k == 0 ) return 1;
	if ( com[n][k] != -1 ) return com[n][k];
	com[n][k] = gc( n-1, k ) + gc( n-1, k-1 );
	return com[n][k];
}

long long n, t;
int k;

int getk( long long x )
{
	int res = 0;
	while ( x > 1 )
	{
		if ( x&1 )
			return -1;
		res++;
		x = x / 2;
	}
	return res;
}

int main()
{
	int i, j;
	long long ans = 0;
	
	memset( com, -1, sizeof( com ) );
	
	cin >> n >> t;
	k = getk( t );
//	printf( "%d\n", k );
	if ( k == -1 )
	{
		printf( "0\n" );
		return 0;
	}
	k++;
	//proverka za 2
	
	long long head = 0;
	int rest = k;
//	printf( "%d\n", rest );
	for ( i = 60; i >= 0; i-- )
	{
		if ( head+(1LL<<i) <= n+1 )
		{
			head += (1LL<<i);
			//ima go v n+1;
			if ( rest > 1 )
				ans = ans + gc( i, rest );
			else
				ans = ans + gc( i+1, rest );
			rest--;
		}
		if ( rest == 0 )
			break;
	}
	
	if ( t == 1 ) ans--;
	cout << ans << endl;
	return 0;
}