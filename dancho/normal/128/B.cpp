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
int lcp[100020], cnt[100020];

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
	int i, k;
	
	scanf( "%s", s );
	n = strlen( s );
	scanf( "%d", &k );
	
	for ( i = 0; i < n; i++ )
	{
		e[i] = make_el( 0, s[i], i );
	}
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
	lcp[n-1] = 0;
	
	memset( cnt, 0, sizeof( cnt ) );
	
	int lp = 0, ll = 1;
	cnt[0]++;
	i = 0;
	k--;
	while ( k > 0 )
	{
		k--;
		if ( lcp[lp] >= ll )
		{
			cnt[lp] = ll;
			lp++;
			cnt[lp] = ll;
		}
		else if ( lcp[lp] < ll )
		{
			ll++;
			while ( ( ll > le[i] ) && ( i <= lp ) )
			{
				i++;
			}
			if ( i > lp ) ll = cnt[i]+1;
			lp = i;
		}
	}
	
	if ( lp >= n )
	{
		printf( "No such line.\n" );
		return 0;
	}
	
	for ( i = 0; i < ll; i++ )
	{
		printf( "%c", s[sa[lp]+i] );
	}
	printf( "\n" );
	
	return 0;
}