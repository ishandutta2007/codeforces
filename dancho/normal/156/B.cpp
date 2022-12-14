#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int cntp[100020];
int cntm[100020];

int n, m;
char s[100020];
int a[100020];

int ap, am;
int bp[100020], bm[100020];

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

int main()
{
	int i, k;
	char x[1024];
	
//	set<pii>::iterator it;
	
	memset( bp, 0, sizeof( bp ) );
	memset( bm, 0, sizeof( bm ) );
	am = ap = 0;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%s", x );
		
		cntp[i] = n;
		cntm[i] = 0;
		
		s[i] = x[0];
		sscanf( x, "%d", &a[i] );
		a[i] = ia( a[i] );
		if ( s[i] == '+' )
		{
//			lp.insert( a[i] );
//			tp.insert( a[i] );
			bp[ a[i] ]++;
			ap++;
		}
		else if ( s[i] == '-' )
		{
//			lm.insert( a[i] );
//			tm.insert( a[i] );
			bm[ a[i] ]++;
			am++;
		}
		
//		printf( "%d %c %d\n", i, s[i], a[i] );
	}
	
	k = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( bp[ i ] + am-bm[i] == m )
		{
//			printf( "STAVA %d\n", i );

			cntp[ i ]--; //ako e + i e != x
			cntm[ i ]++; //ako e - i e == x
		}
		else k++;
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( s[i] == '+' )
		{
			if ( cntp[ a[i] ] == k )
				printf( "Truth\n" );
			else if ( cntp[ a[i] ] == n )
				printf( "Lie\n" );
			else printf( "Not defined\n" );
		}
		else if ( s[i] == '-' )
		{
			if ( cntm[ a[i] ] == 0 )
			{
				printf( "Truth\n" );
			}
			else if ( cntm[ a[i] ] == n-k )
				printf( "Lie\n" );
			else printf( "Not defined\n" );
		}
	}
	return 0;
}