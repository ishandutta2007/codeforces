#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long d2[32];
int bl1[32], br1[32], bl2[32], br2[32];

long long getS( long long l, long long r, long long k )
{
	if ( l < 0 ) return -2;
	long long s;
	s = (l + 1 - d2[k])/d2[k+1];
	while ( s*d2[k+1]+d2[k]-1 < l ) s++;
	if ( s*d2[k+1]+d2[k]-1 > r ) return -2;
	return s*d2[k+1]+d2[k]-1;
}

int main()
{
	int i, k;
	int mx = -1;
	int l1, r1, l2, r2;
	long long b, mk, le, ri;
	
	d2[0] = 1;
	for ( i = 1; i <= 31; i++ )
		d2[i] = 2LL*d2[i-1];
	
	scanf( "%d %d %d %d", &l1, &r1, &l2, &r2 );
	
	l1--; r1--; l2--; r2--;
	
	memset( bl1, -1, sizeof( bl1 ) );
	memset( br1, -1, sizeof( bl1 ) );
	memset( bl2, -1, sizeof( bl1 ) );
	memset( br2, -1, sizeof( bl1 ) );
	
	for ( k = 0; k <= 30; k++ )
	{
		mk = d2[k]-1;
		b = getS( l1, r1, k );
		le = b - max( (long long)l1, b-mk );
		ri = min( (long long)r1, b+mk ) - b;
		
		if ( ( le > bl1[k] ) && ( b != -2 ) )
		{
			bl1[k] = le;
			br1[k] = ri;
		}

		mk = d2[k]-1;
		b = getS( b+1, r1, k );
		le = b - max( (long long)l1, b-mk );
		ri = min( (long long)r1, b+mk ) - b;
		
		if ( le > bl1[k] && b != -2 )
		{
			bl1[k] = le;
			br1[k] = ri;
		}


		mk = d2[k]-1;
		b = getS( l2, r2, k );
		le = b - max( (long long)l2, b-mk );
		ri = min( (long long)r2, b+mk ) - b;
		
		if ( le > bl2[k] && b != -2 )
		{
			bl2[k] = le;
			br2[k] = ri;
		}

		mk = d2[k]-1;
		b = getS( b+1, r2, k );
		le = b - max( (long long)l2, b-mk );
		ri = min( (long long)r2, b+mk ) - b;
		
		if ( le > bl2[k] && b != -2 )
		{
			bl2[k] = le;
			br2[k] = ri;
		}
		
		if ( ( bl1[k] != -1 ) && ( bl2[k] != -1 ) )
		{
			mx = max( mx, min( bl1[k], bl2[k] ) + min( br1[k], br2[k] ) + 1 );
//			printf( "%d -> %d %d %d %d\n", k, bl1[k], br1[k], bl2[k], br2[k] );
		}
	}
	

	memset( bl1, -1, sizeof( bl1 ) );
	memset( br1, -1, sizeof( bl1 ) );
	memset( bl2, -1, sizeof( bl1 ) );
	memset( br2, -1, sizeof( bl1 ) );
	
	for ( k = 0; k <= 30; k++ )
	{
		mk = d2[k]-1;
		b = getS( l1, r1, k );
		le = b - max( (long long)l1, b-mk );
		ri = min( (long long)r1, b+mk ) - b;
		
		if ( ri > br1[k] && b != -2 )
		{
			bl1[k] = le;
			br1[k] = ri;
		}

		mk = d2[k]-1;
		b = getS( b+1, r1, k );
		le = b - max( (long long)l1, b-mk );
		ri = min( (long long)r1, b+mk ) - b;
		
		if ( ri > br1[k] && b != -2 )
		{
			bl1[k] = le;
			br1[k] = ri;
		}


		mk = d2[k]-1;
		b = getS( l2, r2, k );
		le = b - max( (long long)l2, b-mk );
		ri = min( (long long)r2, b+mk ) - b;
		
		if ( ri > br2[k] && b != -2 )
		{
			bl2[k] = le;
			br2[k] = ri;
		}

		mk = d2[k]-1;
		b = getS( b+1, r2, k );
		le = b - max( (long long)l2, b-mk );
		ri = min( (long long)r2, b+mk ) - b;
		
		if ( ri > br2[k] && b != -2 )
		{
			bl2[k] = le;
			br2[k] = ri;
		}
		
		if ( ( bl1[k] != -1 ) && ( bl2[k] != -1 ) )
		{
			mx = max( mx, min( bl1[k], bl2[k] ) + min( br1[k], br2[k] ) + 1 );
//			printf( "%d -> %d %d %d %d\n", k, bl1[k], br1[k], bl2[k], br2[k] );
		}
	}
	
	if ( mx >= 0 )
		printf( "%d\n", mx );
	else printf( "0\n" );
	return 0;
}