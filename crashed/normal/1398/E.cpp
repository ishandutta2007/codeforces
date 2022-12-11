#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

#define int LL

#ifdef _DEBUG
const int MAXN = 105;
#else
const int MAXN = 2e5 + 5;
#endif

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

template<typename _T>
_T ABS( const _T a )
{
	return a < 0 ? -a : a;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct ReHeap
{
	#define emp( a ) a.empty()
	priority_queue<int, vector<int>, greater<int> > q, rub;
	
	ReHeap() { while( ! emp( q ) ) q.pop(); while( ! emp( rub ) ) rub.pop(); }
	void maintain() { while( ! emp( q ) && ! emp( rub ) && q.top() == rub.top() ) q.pop(), rub.pop(); }
	int top() { return maintain(), q.top(); }
	void remove( const int v ) { rub.push( v ); }
	void push( const int v ) { q.push( v ); }
	#undef emp
}S;

struct order
{
	int tp, d;
}O[MAXN];

int siz[MAXN << 2]; LL su[MAXN << 2];

int seq[MAXN], tot;
int N;

void upt( const int x ) 
{ 
	siz[x] = siz[x << 1] + siz[x << 1 | 1]; 
	su[x] = su[x << 1] + su[x << 1 | 1];
}

void update( const int x, const int l, const int r, const int p, const int delt )
{
	if( l == r ) { siz[x] += delt, su[x] += delt * seq[l]; return ; }
	int mid = l + r >> 1;
	if( p <= mid ) update( x << 1, l, mid, p, delt );
	else update( x << 1 | 1, mid + 1, r, p, delt );
	upt( x );
}

LL query( const int x, const int l, const int r, const int rnk )
{
	if( l == r ) return 1ll * rnk * seq[l];
	int mid = l + r >> 1;
	if( rnk <= siz[x << 1 | 1] ) return query( x << 1 | 1, mid + 1, r, rnk );
	return su[x << 1 | 1] + query( x << 1, l, mid, rnk - siz[x << 1 | 1] );
}

signed main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ )
	{
		read( O[i].tp ), read( O[i].d );
		seq[++ tot] = ABS( O[i].d );
	}
	std :: sort( seq + 1, seq + 1 + tot );
	tot = std :: unique( seq + 1, seq + 1 + tot ) - seq - 1;
	
	LL allSum = 0;
	int cntF = 0, cntL = 0;
	for( int i = 1 ; i <= N ; i ++ )
	{
		int pos = std :: lower_bound( seq + 1, seq + 1 + tot, ABS( O[i].d ) ) - seq;
		allSum += O[i].d;
		if( O[i].d > 0 )
		{
			if( O[i].tp == 0 ) cntF ++;
			else cntL ++, S.push( pos );
			update( 1, 1, tot, pos, 1 );
		}
		else
		{
			if( O[i].tp == 0 ) cntF --;
			else cntL --, S.remove( pos );
			update( 1, 1, tot, pos, -1 );
		}
		if( cntL )
		{
			update( 1, 1, tot, S.top(), -1 ); 
			LL tmp = query( 1, 1, tot, MIN( siz[1], cntL ) );
			update( 1, 1, tot, S.top(), 1 ); 
			write( allSum + tmp ), putchar( '\n' );
		}
		else write( allSum ), putchar( '\n' );
	}
	return 0;
}