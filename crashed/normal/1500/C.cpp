#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1505;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

vector<int> disor[MAXN];

int tmp[MAXN], seq[MAXN], buc[MAXN];

int q[MAXN];

int inv[MAXN];
bool used[MAXN];
int A[MAXN][MAXN], B[MAXN][MAXN];
int N, M;

int main()
{
	int h = 1, t = 0;
	read( N ), read( M );
	rep( i, 1, N ) rep( j, 1, M ) read( A[i][j] );
	rep( i, 1, N ) rep( j, 1, M ) read( B[i][j] );
	rep( j, 1, M )
	{
		rep( i, 1, N - 1 )
			if( B[i][j] > B[i + 1][j] )
				inv[j] ++, disor[i].push_back( j );
		if( ! inv[j] ) q[++ t] = j;
	}
	for( int j ; h <= t ; )
	{
		j = q[h ++];
        rep( i, 1, N - 1 )
			if( ! used[i] && B[i][j] < B[i + 1][j] )
			{
				used[i] = true;
				rep( k, 0, ( int ) disor[i].size() - 1 )
                    if( ! ( -- inv[disor[i][k]] ) )
						q[++ t] = disor[i][k];
			}
	}
	rep( i, 1, N ) seq[i] = i;
	per( k, t, 1 )
	{
		int col = q[k];
		rep( i, 1, N ) buc[i] = 0;
		rep( i, 1, N ) buc[A[seq[i]][col]] ++;
        rep( i, 1, N ) buc[i] += buc[i - 1];
		per( i, N, 1 ) tmp[buc[A[seq[i]][col]]--] = seq[i];
		rep( i, 1, N ) seq[i] = tmp[i];
	}
	rep( i, 1, N ) rep( j, 1, M )
		if( A[seq[i]][j] ^ B[i][j] )
		{ puts( "-1" ); return 0; }
	write( t ), putchar( '\n' );
	per( k, t, 1 ) write( q[k] ), putchar( k == 1 ? '\n' : ' ' );
	return 0;
}