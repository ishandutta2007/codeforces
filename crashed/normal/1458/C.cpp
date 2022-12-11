#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1005, MAXM = 1e5 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int stt[3], tag[3];

int fin[MAXN][MAXN];
int sqr[MAXN][MAXN];

char oper[MAXM];

int N, M;

int main() {
	int T; read( T );
	while( T -- ) {
		read( N ), read( M );
		rep( i, 1, N ) rep( j, 1, N ) read( sqr[i][j] );
		scanf( "%s", oper + 1 );
		rep( i, 0, 2 ) stt[i] = i, tag[i] = 0;
		rep( i, 1, M )
			switch( oper[i] ) {
				case 'R': {
					tag[stt[1]] ++;
					break;
				}
				case 'L' : {
					tag[stt[1]] --;
					break;
				}
				case 'D' : {
					tag[stt[0]] ++;
					break;
				}
				case 'U' : {
					tag[stt[0]] --;
					break;
				}
				case 'I' : {
					std :: swap( stt[1], stt[2] );
					break;
				}
				case 'C' : {
					std :: swap( stt[0], stt[2] );
					break;
				}
			}
		rep( i, 1, N ) rep( j, 1, N ) {
			int tri[3] = { i, j, sqr[i][j] };
			fin[( ( tri[stt[0]] - 1 + tag[stt[0]] ) % N + N ) % N + 1]
			   [( ( tri[stt[1]] - 1 + tag[stt[1]] ) % N + N ) % N + 1] =
			   ( ( tri[stt[2]] - 1 + tag[stt[2]] ) % N + N ) % N + 1;
		}
		rep( i, 1, N ) rep( j, 1, N )
			write( fin[i][j] ), putchar( " \n"[j == N] );
		puts( "" );
	}
	return 0;
}