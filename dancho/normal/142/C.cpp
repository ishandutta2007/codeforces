#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

struct move
{
	int nma, vm, wm;
};

move make_move( int nma, int vm, int wm )
{
	move m;
	m.nma = nma; m.vm = vm; m.wm = wm;
	return m;
}

struct el
{
	int mx, nr, nc, nma;
	bool operator<( const el& x ) const
	{
		return mx < x.mx;
	}
};

el make_el( int mx, int nr, int nc, int nma )
{
	el e;
	e.mx = mx; e.nr = nr; e.nc = nc; e.nma = nma;
	return e;
}

int fi[4][4];

int n, m;
vector<move> mv[ 1<<18 ];

pii dp[8][1<<18];

char c[16][16];

int bit_cnt( int x )
{
	int r = 0;
	while ( x > 0 )
	{
		if ( x & 1 ) r++;
		x = x / 2;
	}
	return r;
}

void dfs( int sm, int cm, int mov, int wm )
{
	if ( sm != cm )
	{
//		printf( "ADD %d %d\n", sm, cm );
		mv[sm].push_back( make_move( cm/(1<<m), mov, wm ) );
	}
	int i, j;
	for ( i = 0; i+2 < m; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			if ( ( (cm/(1<<(2*m)))&(fi[j][0]<<i) ) == 0 )
			{
				if ( ( (cm/(1<<(m)))&(fi[j][1]<<i) ) == 0 )
				{
					if ( ( (cm)&(fi[j][2]<<i) ) == 0 )
					{
						dfs( sm, cm+(fi[j][2]<<i)+((fi[j][1]<<i)<<m)+((fi[j][0]<<i)<<(2*m)), mov+(j<<(2*i)), wm+(1<<i) );
					}
				}
			}
		}
	}
}

pii getDP( int r, int ma )
{
//	printf( "IN DP %d %d __ %d %d\n", r, ma, dp[r][ma].first, dp[r][ma].second );
	if ( r < 0 ) return make_pair( 0, -1 );
	if ( dp[r][ma].first != -1 ) return dp[r][ma];
//	printf( "CDP!\n" );
	pii sol = make_pair( 0, 0 );
	sol = make_pair( getDP( r-1, ma/(1<<m) ).first, 0 );
	int i;
	for ( i = 0; (unsigned) i < mv[ma].size(); i++ )
	{
		//if ( r == 2 )
		{
//			printf( "CHK %d : %d %d __ %d %d\n", r, i, mv[ma][i].nma, getDP( r-1, mv[ma][i].nma ).first + bit_cnt( mv[ma][i].wm ), bit_cnt( mv[ma][i].wm ) );
		}
		if ( getDP( r-1, mv[ma][i].nma ).first + bit_cnt( mv[ma][i].wm ) > sol.first )
		{
			sol = make_pair( getDP( r-1, mv[ma][i].nma ).first + bit_cnt( mv[ma][i].wm ), i );
		}
	}
	dp[r][ma] = sol;
//	if ( sol.second >= 0 && sol.second < mv[ma].size() )
//	printf( "DP %d %d : %d %d __ %d\n", r, ma, sol.first, sol.second, mv[ma][sol.second].nma );
	return dp[r][ma];
}

//int main( int argc, char *argv[] )
int main()
{
	int i, j, k, lma, vm, wm;
	int x, y;
	char lc;
	pii s;

	scanf( "%d %d", &n, &m );
	//sscanf( argv[1], "%d", &n );
	//sscanf( argv[2], "%d", &m );
	//printf( "%d %d\n", n, m );
	
	if ( n <= 2 || m <= 2 )
	{
		printf( "0\n" );
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < m; j++ )
				printf( "." );
			printf( "\n" );
		}
		return 0;
	}
	
	fi[0][0] = 7; fi[0][1] = 2; fi[0][2] = 2;
	fi[1][0] = 1; fi[1][1] = 7; fi[1][2] = 1;
	fi[2][0] = 4; fi[2][1] = 7; fi[2][2] = 4;
	fi[3][0] = 2; fi[3][1] = 2; fi[3][2] = 7;
	
	//long long jj = 0;
	for ( i = 0; i < (1LL<<(2*m)); i++ )
	{
		mv[i].push_back( make_move( i/(1<<m), 0, 0 ) );
		dfs( i, i, 0, 0 );
		//jj += mv[i].size();
	}
//	printf( "%lld\n", jj );
	
//	printf( "%d %d %d __ %d %d\n", mv[0][9].nma, mv[0][9].wm, mv[0][9].vm, mv[0][9].nma%(1<<m), mv[0][9].nma/(1<<m) );
	
	memset( dp, -1, sizeof( dp ) );
	printf( "%d\n", getDP( n-3, 0 ).first );
	
	memset( c, '.', sizeof( c ) );
	s = getDP( n-3, 0 );
	lc = 'A';
	lma = 0;
	for ( i = n-3; i >= 0; i-- )
	{
//		printf( "AAA %d _ %d %d %d\n", i, lma, s.second, mv[lma].size() );
		if ( (unsigned)s.second >= mv[lma].size() ) break;
		vm = mv[lma][s.second].vm;
		wm = mv[lma][s.second].wm;
//		printf( "%d %d %d _ %d %d\n", i, wm, vm, lma, mv[lma][s.second].nma );
		for ( j = 0; j < m-2; j++ )
		{
			if ( wm & (1<<j) )
			{
				k = (vm>>(2*j))%4;
				//na i, j slozhi k;
//				printf( "PUT %d %d %d __ %d\n", i, j, k, (vm>>(2*j)) );
				for ( x = 0; x < 3; x++ )
				{
					for ( y = 0; y < 3; y++ )
					{
						if ( fi[k][x]&(1<<y) )
							c[i+x][j+y] = lc;
					}
				}
				lc++;
			}
		}
//		printf( "ZAC %d\n", i );
		if ( i > 0 )
		{
			lma = mv[lma][s.second].nma;
			s = getDP( i-1, lma );
//			printf( "EDP\n" );
		}
	}
//	printf( "END\n" );
	
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			printf( "%c", c[i][j] );
		}
		printf( "\n" );
	}
	return 0;
}