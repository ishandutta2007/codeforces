#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int isl( int x )
{
	while ( x > 0 )
	{
		if ( ( x % 10 != 4 ) && ( x % 10 != 7 ) )
			return 0;
		x = x / 10;
	}
	return 1;
}

typedef pair<int,int> pii;

vector<pii> op;

int n;
int a[100020];
int c[100020];
int pos[100020];
pii s[100020];

int main()
{
	int mpos = -1, mn;
	int i, j;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		if ( mpos == -1 )
		{
			if ( isl( a[i] ) == 1 )
			{
				mpos = i;
				mn = a[i];
			}
		}
		s[i] = make_pair( a[i], i );
		c[i] = i;
		pos[i] = i;
	}
	
	sort( s + 1, s + n + 1 );
	
	if ( mpos == -1 )
	{
		for ( i = 1; i <= n; i++ )
			if ( a[i] != s[i].first )
				break;
		if ( i <= n )
			printf( "-1\n" );
		else printf( "0\n" );
		return 0;
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( s[i].second != c[i] )
		{
			j = s[i].second;
			//printf( "%d %d %d %d _ %d\n", i, s[i].first, s[i].second, c[i], pos[j] );
			//swap( a[mpos], a[i] );
			if ( mpos != i )
			{
				op.push_back( make_pair( mpos, i ) );
//				printf( "A %d %d\n", mpos, i );
				pos[c[mpos]] = i;
				pos[c[i]] = mpos;
				swap( c[mpos], c[i] );
				mpos = i;
			}
			if ( c[i] != s[i].second )
			{
				op.push_back( make_pair( mpos, pos[j] ) );
//				printf( "B %d %d\n", mpos, pos[j] );
				pos[c[mpos]] = pos[j];
				swap( c[mpos], c[pos[j]] );
				swap( mpos, pos[j] );
			}
		}
	}
	
//	for ( i = 1; i <= n; i++ )
		//printf( "%d %d %d\n", s[i].first, s[i].second, c[i] );
	
	printf( "%d\n", op.size() );
	for ( i = 0; (unsigned)i < op.size(); i++ )
	{
		printf( "%d %d\n", op[i].first, op[i].second );
	}
	return 0;
}