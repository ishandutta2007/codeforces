#include <cstdio>

const int MAXN = 1e6 + 5;

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

char S[MAXN];
int N;
bool a[MAXN];

int main()
{
	read( N );
	scanf( "%s", S + 1 );
	int cnt = 0;
	for( int i = 1 ; i <= N ; i ++ ) cnt += ( a[i] = S[i] == ')' );
	if( ( N & 1 ) || ( cnt != N >> 1 ) ) { puts( "-1" ); return 0; }
	bool flag;
	int tot[2];
	int ans = 0;
	for( int i = 1, r, top ; i <= N ; )
	{ 
		top = tot[0] = tot[1] = 0;
		flag = true;
		for( r = i ; r <= N ; r ++ )
		{
			tot[a[r]] ++;
			if( a[r] ) 
			{
				if( top ) top --;
				else flag = false;
			}
			else top ++;
			if( tot[0] == tot[1] ) break;
		}
		if( ! flag ) ans += r - i + 1;
		i = r + 1;
	}
	write( ans ), putchar( '\n' );
	return 0;
}
/*
10
((((()))))
*/