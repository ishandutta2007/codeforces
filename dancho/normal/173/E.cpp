#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

struct el
{
	int r, a, no;
	bool operator<( const el &x ) const
	{
		return r < x.r;
	}
};

bool cmpa( el a, el b )
{
	return a.a < b.a;
}

struct que
{
	int x, l, u, on, ans;
	bool operator<( const que &y ) const
	{
		return x < y.x;
	}
};

bool cmpon( que a, que b )
{
	return a.on < b.on;
}

int n, k, bq;
int r[100020], a[100020];
int na[100020], oa[100020];
int g[100020];

el e[100020];
que q[100020];

int sm[100020];

int mx[1<<19];

void addToMax( int pos, int v )
{
	int p = pos+(1<<17)-1;
	while ( p > 0 )
	{
		if ( mx[p] < v ) mx[p] = v;
		p = p / 2;
	}
}

int qmax( int nd, int nl, int nr, int l, int r )
{
	if ( ( l > nr ) || ( nl > r ) )
		return -1;
	if ( ( l <= nl ) && ( nr <= r ) )
		return mx[nd];
	int i = qmax( 2*nd, nl, (nl+nr)/2, l, r );
	int j = qmax( 2*nd+1, (nl+nr)/2+1, nr, l, r );
	if ( i > j ) return i;
	return j;
}

int qmax( int le, int ri )
{
	if ( le > ri ) return -1;
	return qmax( 1, 1, (1<<17), le, ri );
}

void addToSum( int pos, int v )
{
//	printf( "AS %d %d\n", pos, v );
	for ( int i = pos; i <= n; i=i+(i&(-i)) )
		sm[i] = sm[i] + v;
}

inline int LB( int v )
{
	int l, r, m;
	l = 0; r = n;
	while ( l + 1 < r )
	{
		m = (l+r)/2;
		if ( v <= oa[ m ] )
			r = m;
		else l = m;
	}
	return r;
}

inline int RB( int v )
{
	int l, r, m;
	l = 1; r = n+1;
	while ( l + 1 < r )
	{
		m = (l+r)/2;
		if ( v >= oa[m] )
			l = m;
		else r = m;
	}
	return l;
}

int queSum( int pos )
{
	if ( pos <= 0 ) return 0;
	int r = 0;
	for ( int i = pos; i > 0; i=i-(i&(-i)) )
		r = r + sm[i];
	return r;
}

int queSum( int le, int ri )
{
//	printf( "QS %d %d\n", le, ri );
	if ( le <= ri )
		return queSum( ri ) - queSum( le-1 );
	return 0;
}

int main()
{
	int i, j;
	int x, y;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &r[i] );
		e[i].r = r[i];
		e[i].no = i;
	}
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		e[i].a = a[i];
	}
	
	sort( e + 1, e + n + 1, cmpa );
	for ( i = 1; i <= n; i++ )
	{
		na[ e[i].no ] = i;
		oa[ i ] = e[i].a;
	}
	
	sort( e + 1, e + n + 1 );
	
	memset( sm, 0, sizeof( sm ) );
	j = 1;
	for ( i = 1; i <= n; i++ )
	{
		while ( ( e[j].r <= e[i].r ) && ( j <= n ) )
		{
			addToSum( na[ e[j].no ], 1 );
			j++;
		}
		g[ e[i].no ] = queSum( LB( e[i].a-k ), RB( e[i].a+k ) );
//		printf( "%d %d %d : %d\n", e[i].no, e[i].r, e[i].a, g[ e[i].no ] );
	}
	
	scanf( "%d", &bq );
	for ( i = 1; i <= bq; i++ )
	{
		scanf( "%d %d", &x, &y );
		q[i].on = i;
		q[i].x = r[x];
		if ( r[y] > q[i].x ) q[i].x = r[y];
		if ( ia( a[x] - a[y] ) > 2*k )
			q[i].ans = -1;
		else q[i].ans = -2;
		if ( a[x] < a[y] ) swap( x, y );
		q[i].l = a[x] - k;
		q[i].u = a[y] + k;
		if ( q[i].l > q[i].u ) q[i].ans = -1;
	}
	
	sort( q + 1, q + bq + 1 );
	
	memset( mx, -1, sizeof( mx ) );
	j = n;
	for ( i = bq; i > 0; i-- )
	{
		while ( ( e[j].r >= q[i].x ) && ( j > 0 ) )
		{
			addToMax( na[ e[j].no ], g[ e[j].no ] );
			j--;
		}
//		printf( "%d : %d %d %d\n", i, q[i].x, q[i].l, q[i].u );
		if ( q[i].l <= q[i].u )
		{
			q[i].ans = qmax( LB(q[i].l), RB(q[i].u) );
		}
	}
	
	sort( q + 1, q + bq + 1, cmpon );
	for ( i = 1; i <= bq; i++ )
	{
		printf( "%d\n", q[i].ans );
	}
	return 0;
}