#include <cstdio>
#include <cstring>

int n, ll;

double ex[210][412][210];
bool us[212][412][212];

double p[256];
int a[256];

double getDP( int c, int k, int l )
{
	if ( c > n )
	{
		if ( l >= ll && k >= 201 ) return 1;
		return 0;
	}
	if ( us[c][k][l] ) return ex[c][k][l];
	
	double sol = 0;
	int nk;
	if ( a[c] > -1 )
	{
		nk = k + a[c];
		if ( nk > 401 ) nk = 401;
		sol = sol + p[c]*getDP( c+1, nk, l+1 ) + (1.0-p[c])*getDP( c+1, k, l );
	}
	else
	{
		nk = k-1;
		sol = sol + p[c]*getDP( c+1, nk, l+1 );
		sol = sol + (1.0-p[c])*getDP( c+1, k, l );
	}
	
	us[c][k][l] = 1;
	ex[c][k][l] = sol;
//	printf( "DP %d %d %d -> %lf\n", c, k, l, ex[c][k][l] );
	return ex[c][k][l];
}

int main()
{
	int i, j, k;
	
	memset( us, 0, sizeof( us ) );
	
	scanf( "%d %d %d", &n, &ll, &k );
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &j );
		p[i] = (double)j/100.0;
	}
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	printf( "%.12lf\n", getDP( 1, k+201, 0 ) );
	return 0;
}