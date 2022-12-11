#include <cstdio>
#include <cstring>

const int MAXN = 3005, MAXC = 30;

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

int f[MAXN][MAXN];
int ch[MAXN][MAXC], mx[MAXN], fa[MAXN], seq[MAXN], cnt[MAXN];
int N, K, tot, lst, rt;
char S[MAXN];
bool good[MAXC];

void copy( int a, int b ) { mx[a] = mx[b], fa[a] = fa[b], memcpy( ch[a], ch[b], sizeof ch[b] ); }

void expand( const char c )
{
	int id = c - 'a', p = lst, cur = ++ tot;
	mx[cur] = mx[lst] + 1, lst = cur;
	while( p && ! ch[p][id] ) ch[p][id] = cur, p = fa[p];
	if( ! p ) { fa[cur] = rt; return; }
	int q = ch[p][id];
	if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
	int nq = ++ tot; copy( nq, q );
	mx[nq] = mx[p] + 1, fa[q] = fa[cur] = nq;
	while( p && ch[p][id] == q ) ch[p][id] = nq, p = fa[p];
}

void topo()
{
	for( int i = 1 ; i <= tot ; i ++ ) cnt[mx[i]] ++;
	for( int i = 1 ; i <= N ; i ++ ) cnt[i] += cnt[i - 1];
	for( int i = tot ; i ; i -- ) seq[cnt[mx[i]] --] = i;
}

int main()
{
	rt = lst = ++ tot;
	scanf( "%s", S + 1 ), N = strlen( S + 1 );
	for( int i = 0 ; i < 26 ; i ++ ) scanf( "%1d", &good[i] );
	read( K );
	for( int i = 1 ; i <= N ; i ++ ) expand( S[i] );
	topo();
	for( int i = tot, u, v ; i ; i -- )
	{
		f[u = seq[i]][0] = 1;
		for( int c = 0 ; c < 26 ; c ++ )
			if( v = ch[u][c] )
				for( int j = ! good[c] ; j <= K ; j ++ )
					f[u][j] += f[v][j - ( ! good[c] )];
	}
	int ans = 0;
	for( int i = 0 ; i <= K ; i ++ ) ans += f[rt][i];
	write( ans - 1 ), putchar( '\n' );
	return 0;
}