#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> hp;

struct pii
{
	int first, second, tr;
};

pii make_pair( int fi, int se, int tr )
{
	pii a;
	a.first = fi;
	a.second = se;
	a.tr = tr;
	return a;
}

pii gcd( int a, int b )
{
	if ( b == 0 ) return make_pair( a, 0, 0 );
	pii x = gcd( b, a%b );
	return make_pair( x.first, x.second + a/b, x.tr + 1 );
}

vector<int> vh;
void gcd2( int a, int b )
{
	if ( b == 0 ) return;
	vh.push_back( a/b );
	gcd2( b, a%b );
}

int n, r;

int be, bi;
int cur;

int main()
{
	int i, j, k, x;
	pii a;
	scanf( "%d %d", &n, &r );
	
	be = (1<<29); bi = -1;
	
	for ( x = 1; x <= r; x++ )
	{
		a = gcd( r, x );
		if ( a.first != 1 ) continue;
		if ( a.second != n ) continue;
		
		cur = a.second - a.tr-1;
		if ( cur < 0 ) cur = 0;
		if ( cur < be )
		{
			be = cur;
			bi = x;
		}
	}
	if ( bi == -1 )
	{
		printf( "IMPOSSIBLE\n" );
		return 0;
	}

	x = bi;
	//fprintf( stderr, "%d %d\n", bi, be );
	printf( "%d\n", be );
	gcd2( r, x );
	
	k = 0;
	for ( i = 0; i < (int) vh.size(); i++ )
		k += vh[i];
	//fprintf( stderr, "%d\n", k );
	i = (int) vh.size()-1;
	vh[i] = vh[i] - 1;
	
	if ( vh[0] > 1 || k != n ) while ( 1 );
	printf( "T" );
	char p = 'B';
	while ( i >= 0 )
	{
		while ( vh[i] > 0 )
		{
			printf( "%c", p );
			vh[i]--;
		}
		if ( p == 'B' ) p = 'T';
		else p = 'B';
		i--;
	}
	printf( "\n" );
	
	return 0;
}