#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

bool cp( pii a, pii b )
{
	return a.second < b.second ;
}

int n;
pii s[1<<20];
pii a[1<<20], b[1<<20];
int ba, bb;

set<int> A, B;

int main()
{
	int i, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &s[i].first );
		s[i].second = i;
	}
	
	sort( s + 1, s + n + 1 );
	
	ba = bb = 0;
	for ( i = 1; i <= n; i++ )
	{
		a[i].second = b[i].second = s[i].second;
		k = s[i].first/2;
		if ( A.find( k ) == A.end() && B.find( s[i].first-k ) == B.end() )
		{
			a[i].first = k;
			b[i].first = s[i].first-k;
		}
		else if ( B.find( k ) == B.end() && A.find( s[i].first-k ) == A.end() )
		{
			a[i].first = s[i].first-k;
			b[i].first = k;
		}
		else
		{
			if ( ba < bb )
			{
				a[i].first = 0;
				b[i].first = s[i].first;
			}
			else
			{
				b[i].first = 0;
				a[i].first = s[i].first;
			}
			if ( A.find( a[i].first ) != A.end() )
				ba++;
			if ( B.find( b[i].first ) != B.end() )
				bb++;
		}
		A.insert( a[i].first );
		B.insert( b[i].first );
	}
	
	sort( a + 1, a + n + 1, cp );
	sort( b + 1, b + n + 1, cp );
	
	printf( "YES\n" );
	for ( i = 1; i < n; i++ )
		printf( "%d ", a[i].first );
	printf( "%d\n", a[n].first );

	for ( i = 1; i < n; i++ )
		printf( "%d ", b[i].first );
	printf( "%d\n", b[n].first );

	return 0;
}