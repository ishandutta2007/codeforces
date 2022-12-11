#pragma GCC optimize( 2 )
#pragma GCC optimize( 3 )
#pragma GCC optimize("Ofast","inline","-ffast-math")
#include <map>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef unsigned long long ull;
typedef unsigned long long Nimber;

const ull ORD = ( ull ) -1;
const int MAXB = 2600;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

ull fac[10] = { 0, 3, 5, 17, 257, 641, 65537, 6700417 }; 
int tot = 7; bool exists;

ull nim[256][256]; // 
ull Mul(ull x,ull y,int len=32) {
    if(x==0||y==0) return 0;
    if(x==1||y==1) return x*y;
    if(len<=4&&nim[x][y]) return nim[x][y];
    ull xa=x>>len,xb=x^(xa<<len),ya=y>>len,yb=y^(ya<<len);
    ull a=Mul(xb,yb,len>>1),b=Mul(xa^xb,ya^yb,len>>1),c=Mul(xa,ya,len>>1),d=Mul(c,1ull<<len-1,len>>1);
    ull re=((b^a)<<len)^a^d;
    if(len<=4) nim[x][y]=re;
//	debug("%llu %llu %llu\n",x,y,re);
    return re;
}

Nimber Qkpow( Nimber a, ull indx )
{
	Nimber ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = Mul( ret, a );
		a = Mul( a, a ), indx >>= 1;
	}
	return ret;
}

ull Ord( const Nimber x )
{
	ull ret = ORD;
	per( i, tot, 1 )
		if( Qkpow( x, ret / fac[i] ) == 1 )
			ret /= fac[i];
	return ret;
}

namespace HashMap
{	
	const int MAXS = 10009;

	int head[MAXS], stk[MAXS];
	int nxt[MAXB], val[MAXB]; Nimber key[MAXB];
	int cnt = 0, top = 0;

	void Clean()
	{
		cnt = 0;
		while( top ) head[stk[top]] = 0, stk[top --] = 0;
	}
	
	void Insert( const Nimber nKey, const int nVal )
	{
		int has = nKey % MAXS;
		for( int i = head[has] ; i ; i = nxt[i] )
			if( key[i] == nKey ) return ;
		if( ! head[has] ) stk[++ top] = has;
		cnt ++; val[cnt] = nVal, key[cnt] = nKey;
		nxt[cnt] = head[has], head[has] = cnt;
	}
	
	int Find( const Nimber nKey )
	{
		int has = nKey % MAXS;
		for( int i = head[has] ; i ; i = nxt[i] )
			if( key[i] == nKey ) return val[i];
		return -1;
	}
}

int BSGS( const Nimber a, const Nimber b, const int lim, const ull ord )
{
	using namespace HashMap; Clean();
	int B = ceil( sqrt( lim ) );
	Nimber pw = 1;
	rep( i, 0, B - 1 )
		Insert( pw, i ), pw = Mul( pw, a );
	Nimber tmp = 1, base = Qkpow( a, ord - B % ord ), t;
	rep( i, 0, B - 1 )
	{
		if( ~ ( t = Find( Mul( tmp, b ) ) ) )
			return t + i * B;
		tmp = Mul( tmp, base );
	}
	return -1;
}

ull Solve( const int indx, const Nimber a, const Nimber b, const ull n )
{
	if( a == b ) return n == 1 ? 0 : 1;
	if( indx > tot ) { exists = false; return 0; }
	if( n % fac[indx] ) return Solve( indx + 1, a, b, n );
	ull p = n / fac[indx], q = fac[indx];
	int v = BSGS( Qkpow( a, p ), Qkpow( b, p ), q, n );
	if( ! ( ~ v ) ) { exists = false; return 0; }
	return q * Solve( indx + 1, Qkpow( a, q ), Mul( b, Qkpow( a, n - v ) ), p ) + v;
}

int main()
{
	int T;
	read( T );
	while ( T -- )
	{
		Nimber a, b;
		read( a ), read( b );
		
		if( a == b )
		{ puts( "1" ); continue; }
		
		exists = true; 
		ull ans = Solve( 1, a, b, Ord( a ) );
		if( exists ) write( ans ), putchar( '\n' );
		else puts( "-1" );
	}
	return 0;
}