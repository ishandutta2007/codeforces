#include <cstdio>
#include <cstring>

const int maxk = 3000020;
const int maxn = 5020;

int n, k;
int rest;
int l[maxn], r[maxn];

int it[maxk];
int ne[maxk], pr[maxk];

char st[maxk];

int par[maxk];
int a[maxk], la;

int lr[maxk];
char out[maxk], ou[maxk];

int find( int v )
{
	int i;
	la = 0;
	while ( par[v] != -1 )
	{
		a[++la] = v;
		v = par[v];
	}
	for ( i = 1; i <= la; i++ )
		par[ a[i] ] = v;
	return v;
}

int un = 0;

inline void uni( int u, int v )
{
	//printf( "UNI %d %d\n", u, v );
	un++;
	par[ find( u ) ] = v;
}

inline void add( int pos, int val )
{
	for ( int i = pos; i <= k; i += (i&(-i)) )
		it[i] += val;
}

inline int get( int pos )
{
	if ( pos <= 0 ) return 0;
	int res = 0;
	for ( int i = pos; i > 0; i -= (i&(-i)) )
		res += it[i];
	return res;
}

int getPos( int nind )
{
	int l = 0, r = k+1, m;
	
	while ( l + 1 < r )
	{
		m = (l+r)/2;
		//printf( "BS %d: %d %d (%d %d)\n", nind, l, r, m, get( m ) );
		if ( get( m ) < nind )
			l = m;
		else r = m;
	}
	return l+1;
}

void rem( int pos )
{
	pr[ne[pos]] = pr[pos];
	ne[pr[pos]] = ne[pos];
	add( pos, -1 );
}

int main()
{
	int i, j, s, c;
	int sz;
	
	//fgets( st, maxk, stdin );
	scanf( "%s", st );
	scanf( "%d", &k );
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &l[i], &r[i] );
	}
	
	memset( par, -1, sizeof( par ) );

	for ( i = 0; i <= k; ++i )
		ne[i] = i+1;
	for ( i = 1; i <= k+1; ++i )
		pr[i] = i-1;
	for ( i = 1; i <= k+1; ++i )
		add( i, 1 );
	
	rest = k;
	for ( i = n; i > 0; i-- )
	{
		if ( r[i] >= rest ) continue;
		l[i] = getPos( l[i] );
		r[i] = getPos( r[i] );
		sz = get( r[i] ) - get( l[i] ) + 1;
		/*for ( j = l[i]; pr[j] != r[i]; j = ne[j] )
		{
			lr[++sz] = j;
		}*/
		bool fl = 0;
		for ( j = ne[r[i]], c = 1, s = ne[l[i]]; c <= sz; j = ne[j], c++, s = ne[ne[s]] )
		{
//			printf( "%d %d %d %d %d\n", j, s, ne[s], c, sz );
			if ( j > k ) break;
			if ( ( c > sz/2 ) && (!fl) )
			{
				fl = 1;
				s = l[i];
			}
			uni( s, j );
			rest--;
			rem( j );
		}
	}
	
	//fprintf( stderr, "%d\n", un );
	memset( out, '@', sizeof( out ) );
	
	int le = strlen( st );
	for ( i = 0, j = getPos( 1 ); i < le; i++, j = ne[j] )
	{
		if ( j > k ) break;
		//printf( "%d %d\n", i, j );
		if ( out[ find( j ) ] == '@' )
		{
			out[ find( j ) ] = st[i];
		}
	}
	
	for ( i = 1; i <= k; i++ )
	{
		ou[i-1] = out[ find( i ) ];
	}
	ou[k] = '\0';
	puts( ou );
	return 0;
}