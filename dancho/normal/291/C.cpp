#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
long long v[1<<20];
int dif[1<<20];

int msbPos( long long x )
{
	int r = 0;
	while ( x )
	{
		x = (x >> 1);
		r++;
	}
	return r;
}

int main()
{
	int i, j;
	int a, b, c, d;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d.%d.%d.%d", &a, &b, &c, &d );
		v[i] = (((256LL*a)+b)*256LL+c)*256LL+d;
	}
	
	sort( v + 1, v + n+1 );
	
	j = 0;
	for ( i = 1; i < n; i++ )
	{
		j++;
		dif[j] = 33-msbPos( v[i]^v[i+1] );
		//printf( "%d\n", dif[j] );
	}

	dif[0] = 1;
	sort( dif + 1, dif + j + 1 );
	
	//for ( i = 0; i <= j; i++ )
	//	printf( "%d %d\n", i, dif[i] );
	
	int comp = 0;
	for ( i = 0; i <= j; )
	{
		int l = i;
		while ( (l <= j) && (dif[l] == dif[i]) && (l <= j) )
		{
			comp++;
			l++;
		}
//		printf( "%d %d %d %d\n", i, dif[i], comp, l );
		if ( comp == k )
			break;
		else if ( comp > k )
		{
			printf( "-1\n" );
			return 0;
		}
		i = l;
	}
	if ( i <= j )
	{
//		printf( "BC %d\n", dif[i] );
		long long ans = 0;
		for ( int l = 0; l < dif[i]; l++ )
		{
			ans = (ans | (1LL<<( 31LL-l )));
		}
		for ( i = 3; i > 0; i-- )
		{
			a = (int) (ans>>(i*8));
			printf( "%d.", a );
			ans -= ((long long) a<<(i*8));
		}
		printf( "%d\n", (int) ans );
	}
	else
	{
		printf( "-1\n" );
	}
	return 0;
}