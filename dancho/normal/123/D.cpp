#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct el
{
	int cr, ne, fr;
	bool operator<( const el& x ) const
	{
		if ( cr == x.cr )
			return ne < x.ne;
		return cr < x.cr;
	}
	bool operator==( const el& x )
	{
		if ( ( cr == x.cr ) && ( ne == x.ne ) )
			return 1;
		return 0;
	}
	bool operator!=( const el& x )
	{
		if ( ( cr != x.cr ) || ( ne != x.ne ) )
			return 1;
		return 0;
	}
};

el make_el( int cr, int ne, int fr )
{
	el r;
	r.cr = cr; r.ne = ne; r.fr = fr;
	return r;
}

int n, ms;
char s[100020];

int pos[100020][18];
el e[100020];
int sa[100020], le[100020];
int lcp[100020];

int ch[1<<18], is0[1<<18];
long long sm[1<<18];
int sz[1<<18];

int common( int l, int r, int nl, int nr )
{
	return min( r, nr ) - max( l, nl );
}

void upd( int nd, int nl, int nr, int l, int r, int v, bool m0 )
{
	if ( ( l > nr ) || ( nl > r ) ) return;
	if ( is0[nd] ) 
	{
		sm[nd] = 0;
		ch[nd] = 0;
		m0 = 1;
		is0[nd] = 0;
		if ( nl != nr )
		{
			is0[2*nd] = 1;
			is0[2*nd+1] = 1;
			sm[2*nd] = 0;
			sm[2*nd+1] = 0;
			ch[2*nd] = 0;
			ch[2*nd+1] = 0;
		}
	}
	if ( nl != nr )
	{
		if ( is0[2*nd] )
		{
			is0[2*nd] = 0;
			sm[2*nd] = 0;
			ch[2*nd] = 0;
			if ( 2*nd < (1<<17) )
			{
				is0[2*2*nd] = 1;
				is0[2*2*nd+1] = 1;
			}
		}
		ch[2*nd] += ch[nd];
		sm[2*nd] += (long long)sz[2*nd]*ch[nd];
		if ( is0[2*nd+1] )
		{
			is0[2*nd+1] = 0;
			sm[2*nd+1] = 0;
			ch[2*nd+1] = 0;
			if ( 2*nd+1 < (1<<17) )
			{
				is0[2*(2*nd+1)] = 1;
				is0[2*(2*nd+1)+1] = 1;
			}
		}
		ch[2*nd+1] += ch[nd];
		sm[2*nd+1] += (long long)sz[2*nd+1]*ch[nd];
		ch[nd] = 0;
	}
	if ( m0 )
	{
		ch[nd] = 0;
		if ( nl != nr )
		{
			ch[2*nd] = 0;
			ch[2*nd+1] = 0;
		}
	}
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		ch[nd] += v;
		if ( m0 )
		{
			sm[nd] = (long long)v*sz[nd];
			if ( nl != nr )
			{
				is0[2*nd] = 1;
				is0[2*nd+1] = 1;
			}
		}
		else
		{
			sm[nd] = sm[nd] + (long long)v*sz[nd];
		}
//		printf( "UPD_END %d %d %d %d %d : %lld; %d _ %d\n", nd, nl, nr, l, r, sm[nd], ch[nd], sz[nd] );
		return;
	}
	upd( 2*nd, nl, (nl+nr)/2, l, r, v, m0 );
	upd( 2*nd+1, (nl+nr)/2+1, nr, l, r, v, m0 );
	sm[nd] = sm[2*nd] + sm[2*nd+1] + ch[nd]*sz[nd];
//	printf( "UPD %d %d %d %d %d : %lld; %d\n", nd, nl, nr, l, r, sm[nd], ch[nd] );
	/*if ( m0 )
		sm[nd] = common( l, r, nl, nr )*v;
	else
		sm[nd] = sm[nd] + common( l, r, nl, nr )*v;*/
}

void upd( int l, int r, int v )
{
	upd( 1, 1, (1<<17), l, r, v, 0 );
}

void set0( int nd, int nl, int nr, int l, int r )
{
	if ( ( l > nr ) || ( nl > r ) ) return;
	if ( nl != nr )
	{
		if ( is0[2*nd] )
		{
			is0[2*nd] = 0;
			sm[2*nd] = 0;
			ch[2*nd] = 0;
			if ( 2*nd < (1<<17) )
			{
				is0[2*2*nd] = 1;
				is0[2*2*nd+1] = 1;
			}
		}
		ch[2*nd] += ch[nd];
		sm[2*nd] += (long long)sz[2*nd]*ch[nd];
		if ( is0[2*nd+1] )
		{
			is0[2*nd+1] = 0;
			sm[2*nd+1] = 0;
			ch[2*nd+1] = 0;
			if ( 2*nd+1 < (1<<17) )
			{
				is0[2*(2*nd+1)] = 1;
				is0[2*(2*nd+1)+1] = 1;
			}
		}
		ch[2*nd+1] += ch[nd];
		sm[2*nd+1] += (long long)sz[2*nd+1]*ch[nd];
		ch[nd] = 0;
	}
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		sm[nd] = 0;
		ch[nd] = 0;
		is0[nd] = 1;
		return;
	}
	set0( 2*nd, nl, (nl+nr)/2, l, r );
	set0( 2*nd+1, (nl+nr)/2+1, nr, l, r );
	sm[nd] = sm[2*nd] + sm[2*nd+1] + (long long)sz[nd]*ch[nd];
//	printf( "SETV %d %d %d %d %d : %lld; %d\n", nd, nl, nr, l, r, sm[nd], ch[nd] );
}

void set0( int l, int r )
{
	set0( 1, 1, (1<<17), l, r );
}

long long getSm()
{
	return sm[1];
}

void getsz( int nd, int nl, int nr )
{
	if ( nl == nr )
	{
		sz[nd] = 1;
		return;
	}
	getsz( 2*nd, nl, (nl+nr)/2 );
	getsz( 2*nd+1, (nl+nr)/2+1, nr );
	sz[nd] = sz[2*nd] + sz[2*nd+1];
}

void getsz()
{
	getsz( 1, 1, (1<<17) );
}

int getLcp( int k, int l, int si )
{
	int i = si;
	while ( ( pos[k][i] != pos[l][i] ) && ( i >= 0 ) )
		i--;
	if ( i >= 0 )
		return (1<<i) + getLcp( k+(1<<i), l+(1<<i), i-1 );
	return 0;
}

int getLcp( int k, int l )
{
	return getLcp( k, l, ms );
}

int main()
{
	int i;
	long long ans;
	
	scanf( "%s", s );
	n = strlen( s );
	
	for ( i = 0; i < n; i++ )
	{
//		pos[i][0] = s[i]-'a';
		e[i] = make_el( 0, s[i], i );
	}
//	pos[n][0] = 30;
	e[n] = make_el( 0, 'a'-1, n );
	
	sort( e, e + n + 1 );
	
	int po = 1, st = 0;
	while ( po < n )
	{
		ms = st;
		pos[e[0].fr][st] = 0;
		for ( i = 1; i <= n; i++ )
		{
			if ( e[i] == e[i-1] )
				pos[e[i].fr][st] = pos[e[i-1].fr][st];
			else pos[e[i].fr][st] = pos[e[i-1].fr][st] + 1;
		}
		for ( i = 0; i <= n; i++ )
		{
			if ( i + po <= n )
				e[i] = make_el( pos[i][st], pos[i+po][st], i );
			else e[i] = make_el( pos[i][st], -1, i );
		}
		sort( e, e + n + 1 );
		st++;
		po = po * 2;
	}
	
	for ( i = 1; i <= n; i++ )
	{
		sa[i-1] = e[i].fr;
	}
	
	for ( i = 0; i < n-1; i++ )
	{
		lcp[i] = getLcp( sa[i], sa[i+1] );
		le[i] = n-sa[i];
	}
	le[n-1] = n-sa[n-1];
	
	getsz();
	memset( is0, 0, sizeof( is0 ) );
	memset( sm, 0, sizeof( sm ) );
	memset( ch, 0, sizeof( ch ) );
	
	ans = 0;

	upd( 1, le[0], 1 );
	ans = ans + getSm();
	for ( i = 1; i < n; i++ )
	{
		set0( lcp[i-1]+1, n+10 );
		if ( lcp[i-1] > 0 )
		{
			upd( 1, lcp[i-1], 1 );
		}
		upd( lcp[i-1]+1, le[i], 1 );
		ans = ans + getSm();
//		printf( "%d %d %d %d : %lld %lld\n", i, lcp[i-1], le[i], sa[i], getSm(), ans );
	}
	
	printf( "%I64d\n", ans );
	
	return 0;
}