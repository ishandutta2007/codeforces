#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n;
int a[100020];
multiset<int, greater<int> > ms;

int main()
{
	int i, j;
	int bmi, bmip1;
	int ami;
	int amx;
	multiset<int, greater<int> >::iterator it, jt;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		ms.insert( a[i] );
	}
	if ( n == 2 )
	{
		if ( ( a[1] == a[2] + 1 ) || ( a[1] == a[2] - 1 ) )
			printf( "YES\n" );
		else
			printf( "NO\n" );
		return 0;
	}
	if ( n % 2 == 1 )
	{
		printf( "NO\n" );
		return 0;
	}
	ami = a[1];
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] < ami ) ami = a[i];
	}
	bmi = 0; bmip1 = 0;
	
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] == ami ) bmi++;
		else if ( a[i] == ami+1 ) bmip1++;
	}
	if ( bmip1 < 2 )
	{
		printf( "NO\n" );
		return 0;
	}
	
	amx = a[1];
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] > amx ) amx = a[i];
	}
	for ( j = ami+2; j <= amx; j++ )
	{
		it = ms.find( j );
		if ( it == ms.end() )
		{
			printf( "NO\n" );
			return 0;
		}
		ms.erase( it );
	}
	for  ( j = amx-1; j >= ami+2; j-- )
	{
		it = ms.find( j );
		if ( it == ms.end() )
		{
			printf( "NO\n" );
			return 0;
		}
		ms.erase( it );
	}
	if ( amx >= ami+2 )
		bmip1--;
	
	while ( (*ms.begin()) > ami+1 )
	{
		jt = ms.begin();
		it = ms.find( (*jt)-1 );
		if ( it == ms.end() )
		{
			printf( "NO\n" );
			return 0;
		}
		if ( (*it) == ami+1 )
			bmip1--;
		ms.erase( it );
		ms.erase( jt );
	}
	if ( bmi == bmip1 )
		printf( "YES\n" );
	else
		printf( "NO\n" );
	return 0;
}