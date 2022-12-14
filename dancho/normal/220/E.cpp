#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int n;
long long k;
pii a[100020];
int nn[100020];
int le[100020], ri[100020];
long long ans, cinv;

void add( int it[], int pos, int val )
{
	for ( int i = pos; i <= n; i += (i&(-i)) )
		it[i] += val;
}

int get( int it[], int pos )
{
	if ( pos <= 0 ) return 0;
	int res = 0;
	for ( int i = pos; i > 0; i -= (i&(-i)) )
		res += it[i];
	return res;
}

void addL( int pos )
{
	add( le, n+1-nn[pos], 1 );
}

void addR( int pos )
{
	add( ri, nn[pos], 1 );
}

void remR( int pos )
{
	add( ri, nn[pos], -1 );
}

int weight( int pos )
{
//	printf( "GET %d %d %d %d\n", pos, nn[pos], get( le, n+1-(nn[pos]-1) ), get( ri, nn[pos]-1 ) );
	return get( le, n+1-(nn[pos]+1) ) + get( ri, nn[pos]-1 );
}

int main()
{
	int i, j;
	
	memset( le, 0, sizeof( le ) );
	memset( ri, 0, sizeof( ri ) );
	
	cin >> n >> k;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i].first );
		a[i].second = i;
	}
	
	sort( a + 1, a + n + 1 );
	
	for ( i = 1; i <= n; )
	{
		j = i;
		while ( ( a[i].first == a[j].first ) && ( j <= n ) )
		{
			nn[ a[j].second ] = i;
			j++;
		}
		i = j;
	}
	
	ans = 0;
	cinv = 0;

	int l, r;
	
	r = n;
	while ( ( cinv <= k ) && ( r > 0 ) )
	{
		if ( cinv + weight( r ) <= k )
		{
			cinv += weight( r );
			addR( r );
			r--;
		}
		else break;
	}
	
	r++;
	//fprintf( stderr, "START %d\n", r );
	for ( l = 1; l < n; l++ )
	{
		if ( l == r )
		{
			cinv -= weight( r );
			remR( r );
			r++;
		}
		cinv += weight( l );
		addL( l );

		//fprintf( stderr, "LRa %d %d %d\n", l, r, (int)cinv );
		while ( ( r <= n ) && ( cinv > k ) )
		{
			cinv -= weight( r );
			remR( r );
			r++;
		}
		
		if ( r > n ) break;
		
//		fprintf( stderr, "LR %d %d %d\n", l, r, (int)cinv );
		ans += n-r+1;
	}
	
	cout << ans << endl;
	return 0;
}