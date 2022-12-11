#include <cstdio>
#include <vector>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 3005;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = - x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

typedef std :: pair<int, int> Compon;
typedef std :: pair<int, Compon> Number;

std :: vector<std :: vector<int> > op;

Number num[MAXN];

int d[MAXN], siz[MAXN], app[MAXN];
int N;

void Bond()
{
	int tot = 0;
	for( int i = 1, j ; i <= N ; i = j )
	{
		int s = 0;
		for( j = i ; j <= N && d[j] - j == d[i] - i ; s += siz[j ++] );
		tot ++, num[tot] = Number( d[i], Compon( tot, s ) );
	}
	std :: sort( num + 1, num + 1 + tot );
	rep( i, 1, tot ) d[num[i].second.first] = i,
				     siz[num[i].second.first] = num[i].second.second;
	rep( i, tot + 1, N ) d[i] = siz[i] = 0; N = tot;
}

void Perform( const std :: vector<int> &act )
{
	static int tmp[MAXN], tmpd[MAXN];
	int n = act.size(), su = 0, len = 0;
	for( int i = n - 1, j = N, k ; ~ i ; i --, j = k )
	{
		for( su = 0, k = j ; k ; k -- )
			if( ( su += siz[k] ) > act[i] ) break;
		for( int p = k + 1 ; p <= j ; p ++ )
			len ++, tmpd[len] = d[p], tmp[len] = siz[p];
	}
	rep( i, 1, N ) d[i] = tmpd[i], siz[i] = tmp[i];
}

void TryMeld()
{
	std :: vector<int> res; res.clear();
	int p, q, t, su = 0;
	rep( i, 1, N ) app[i] = 0;
	rep( i, 1, N )
	{
		if( d[i] < N && app[d[i] + 1] ) { p = app[d[i] + 1], q = i; break; }
		app[d[i]] = i;
	}
	for( t = p ; t < q ; t ++ )
		if( d[t] > d[t + 1] ) break;
	rep( i, 1, p - 1 ) su += siz[i];
	if( su ) res.push_back( su ); su = 0;
	rep( i, p, t ) su += siz[i];
	if( su ) res.push_back( su ); su = 0;
	rep( i, t + 1, q ) su += siz[i];
	if( su ) res.push_back( su ); su = 0;
	rep( i, q + 1, N ) su += siz[i];
	if( su ) res.push_back( su ); su = 0;
	Perform( res ), op.push_back( res );
}

int main()
{
	read( N );
	rep( i, 1, N ) read( d[i] ), siz[i] = 1;
	while( Bond(), N > 1 ) TryMeld();
	write( op.size() ), putchar( '\n' );
	rep( i, 0, ( int ) op.size() - 1 )
	{
		write( op[i].size() ), putchar( ' ' );
		rep( j, 0, ( int ) op[i].size() - 1 )
			write( op[i][j] ), putchar( " \n"[j == ( int ) op[i].size() - 1] );
	}
	return 0;
}