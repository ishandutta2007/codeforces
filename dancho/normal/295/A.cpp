#include <cstdio>
#include <cstring>

int n, m, k;
long long a[1<<20];
long long b[1<<20];
long long l[1<<20], r[1<<20], d[1<<20];
long long opd[1<<20];

int main()
{
	int i, j;
	int x, y;
	
	long long s;
	
	scanf( "%d %d %d", &n, &m, &k );
	a[0] = b[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &j );
		a[i] = j;
		b[i] = a[i] - a[i-1];
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d", &x ); l[i] = x;
		scanf( "%d", &x ); r[i] = x;
		scanf( "%d", &x ); d[i] = x;
	}
	
	memset( opd, 0, sizeof( opd ) );
	for ( i = 1; i <= k; i++ )
	{
		scanf( "%d %d", &x, &y );
		opd[x]++;
		opd[y+1]--;
	}
	
	s = 0;
	for ( i = 1; i <= m; i++ )
	{
		s += opd[i];
		b[ l[i] ] += s*d[i];
		b[ r[i]+1 ] -= s*d[i];
	}
	
	s = 0;
	for ( i = 1; i < n; i++ )
	{
		s += b[i];
		printf( "%I64d ", s );
	}
	s += b[n];
	printf( "%I64d\n", s );
	return 0;
}