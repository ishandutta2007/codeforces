#include <cmath>
#include <cstdio>
#include <iostream>
#include <cassert>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const double eps = 0;
const int MAXN = 505;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

double mat[MAXN][MAXN];
double ans[MAXN];

bool reach[MAXN][MAXN];
double G[MAXN][MAXN];
double p[MAXN];

int N, M, A, B;

#define ID( a, b ) ( ( (a) - 1 ) * N + (b) )

//void Gauss( const int n, const int m )
//// $n equations and $m variables.
//{
//	int idx = -1; double tmp;
//	for( int i = 1, opt = 1 ; i <= n && opt <= m ; i ++, opt ++ )
//	{
//		idx = -1;
//		for( int j = i ; j <= n ; j ++ )
//			if( fabs( mat[j][opt] ) > eps && ( idx == -1 ||
//				  fabs( mat[idx][opt] ) < fabs( mat[j][opt] ) ) )
//				idx = j;
//		if( idx == -1 ) { i --; continue; }
//		assert( fabs( mat[idx][opt] ) > eps );
//		if( idx ^ i )
//			for( int j = 1 ; j <= m + 1 ; j ++ )
//				std :: swap( mat[i][j], mat[idx][j] );
//		double tmp = mat[i][opt];
//		assert( fabs( tmp ) > eps );
//		for( int j = 1 ; j <= m + 1 ; j ++ )
//			mat[i][j] /= tmp;
//		for( int j = i + 1 ; j <= n ; j ++ )
//			if( fabs( mat[j][opt] ) > eps )
//			{
//				tmp = mat[j][opt] / mat[i][opt];
//				for( int k = 1 ; k <= m + 1 ; k ++ )
//					mat[j][k] -= mat[i][k] * tmp;
//			}
//	}
//	for( int i = n ; i ; i -- )
//	{
//		idx = -1;
//		for( int j = 1 ; j <= m ; j ++ )
//			if( fabs( mat[i][j] ) > eps ) { idx = j; break; }
//		if( idx == -1 ) continue;
//		ans[idx] = mat[i][m + 1] / mat[i][idx];
//		for( int j = 1 ; j < i ; j ++ )
//			if( fabs( mat[j][idx] ) > eps )
//				mat[j][m + 1] -= mat[j][idx] * ans[idx], mat[j][idx] = 0;
//	}
//}

void Gauss( const int n, const int m )
// $n equations and $m variables.
{
	int idx = -1; double tmp;
	for( int i = 1, opt = 1 ; i <= n && opt <= m ; i ++, opt ++ )
	{
		idx = -1;
		for( int j = i ; j <= n ; j ++ )
			if( fabs( mat[j][opt] ) > eps && ( idx == -1 ||
				  fabs( mat[idx][opt] ) < fabs( mat[j][opt] ) ) )
				idx = j;
		if( idx == -1 ) { i --; continue; }
		if( idx ^ i ) std :: swap( mat[i], mat[idx] );
		tmp = mat[i][opt];
		for( int j = 1 ; j <= m + 1 ; j ++ )
			mat[i][j] /= tmp;
		for( int j = 1 ; j <= n ; j ++ )
			if( fabs( mat[j][opt] ) > eps && i ^ j )
			{
				tmp = mat[j][opt] / mat[i][opt];
				for( int k = 1 ; k <= m + 1 ; k ++ )
					mat[j][k] -= mat[i][k] * tmp;
			}
	}
	for( int i = 1 ; i <= n ; i ++ )
	{
		int idx = -1;
		for( int j = 1 ; j <= m ; j ++ )
			if( fabs( mat[i][j] ) > eps )
			{ idx = j; break; }
		ans[idx] = mat[i][m + 1] / mat[i][idx];
	}
}

int main()
{
	read( N ), read( M ), read( A ), read( B );
	rep( i, 1, M )
	{
		int u, v;
		read( u ), read( v );
		reach[u][v] = reach[v][u] = true;
	}
	rep( i, 1, N ) scanf( "%lf", &p[i] );
	rep( i, 1, N )
	{
		int deg = 0;
		rep( j, 1, N ) deg += reach[i][j];
		rep( j, 1, N ) if( reach[i][j] )
			G[i][j] = ( 1 - p[i] ) / deg;
		G[i][i] += p[i];
	}
	if( A == B )
		rep( i, 1, N ) ans[ID( i, i )] = i == A;
	else
	{
		rep( u, 1, N ) rep( v, 1, N )
		{
			int cur = ID( u, v );
			mat[cur][cur] = 1;
			if( u == v ) continue;
			mat[cur][N * N + 1] = u == A && v == B;
			rep( p, 1, N ) rep( q, 1, N )
				mat[ID( p, q )][cur] -= G[u][p] * G[v][q];
		}
		Gauss( N * N, N * N );
	}
	rep( i, 1, N ) printf( "%.12f\n", ans[ID( i, i )] );
	return 0;
}