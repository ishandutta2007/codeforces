#include <cstdio>
#include <cstring>

#define maxn (1<<20)

int n;
int a[maxn];

int rmq[ 2*maxn ];

long long de[ 2*maxn ];

long long sm[ maxn ];

void addD( int nd, int nl, int nr, int l, int r, int d )
{
	if ( ( nl > r ) || ( l > nr ) ) return;
	if ( nl != nr )
	{
		de[ 2*nd ] += de[nd];
		de[ 2*nd+1 ] += de[nd];
		de[nd] = 0;
	}
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		de[ nd ] += d;
		return;
	}
	
	addD( 2*nd, nl, (nl+nr)/2, l, r, d );
	addD( 2*nd+1, (nl+nr)/2+1, nr, l, r, d );
}

void addD( int l, int r, int d )
{
	if ( l <= r )
		addD( 1, 1, maxn, l, r, d );
}

long long getD( int x )
{
	int p = x+maxn-1;
	long long ans = 0;
	while ( p > 0 )
	{
		ans += de[p];
		p = p / 2;
	}
	return ans;
}

void addRmq( int pos )
{
	int p = pos + maxn-1;
	rmq[p] = pos;
	p = p / 2;
	while ( p > 0 )
	{
		if ( a[ rmq[2*p] ] <= a[ rmq[2*p+1] ] )
			rmq[p] = rmq[2*p];
		else rmq[p] = rmq[2*p+1];
		p = p / 2;
	}
}

int queryRmq( int nd, int nl, int nr, int l, int r )
{
	if ( ( nl > r ) || ( l > nr ) ) return 0;
	if ( ( l <= nl ) && ( nr <= r ) ) return rmq[nd];
	
	int i = queryRmq( 2*nd, nl, (nl+nr)/2, l, r ),
		j = queryRmq( 2*nd+1, (nl+nr)/2+1, nr, l, r );
	if ( a[i] <= a[j] ) return i;
	return j;
}

int queryRmq( int l, int r )
{
	return queryRmq( 1, 1, maxn, l, r );
}

void solve( int l, int r )
{
	if ( l > r ) return;
	int sz = r-l+1;
	int i = queryRmq( l, r );
	int b1, b2;
	b1 = sz-(i-l+1)+1;
	b2 = i-l+1;
	if ( b1 > b2 )
	{
		b1 = i-l+1;
		b2 = sz-(i-l+1)+1;
	}
	
	
	addD( 1, b1, a[i] );
	addD( b2+1, sz, -a[i] );
	
	addD( sz+1, sz+1, -a[i] );
	solve( l, i-1 );
	solve( i+1, r );
}

int main()
{
	a[0] = (1<<30);
	
	int i, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	
	for ( i = 1; i <= n; i++ )
	{
		addRmq( i );
	}
	
	memset( de, 0, sizeof( de ) );
	
	solve( 1, n );
	
	for ( i = 1; i <= n; i++ )
	{
		sm[i] = getD( i ) + sm[i-1];
	}
	
	int m;
	scanf( "%d", &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d", &k );
		printf( "%.10lf\n", (double) sm[k] / (n-k+1) );
	}
	return 0;
}