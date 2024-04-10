#include <cstdio>
#include <cstring>

long long gcd( long long a, long long b )
{
	if ( b == 0 ) return a;
	return gcd( b, a%b );
}

int n, m, x, y, a, b;

int main()
{
	long long x1, y1, x2, y2;
	long long X1, Y1, X2, Y2;
	long long dx, dy;
	int i, j, k;
	long long le, ri, mi;
	long long X, Y;
	
	
	scanf( "%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b );
	long long d = gcd( a, b );
	a = a / d;
	b = b / d;

	le = 0; ri = n+1;
	while ( le+1 < ri )
	{
		mi = (le+ri)/2;
		if ( ( mi*b <= m ) && ( mi*a <= n ) )
			le = mi;
		else
			ri = mi;
	}
	
	dx = le*a;
	dy = le*b;
	X = 2LL*x;
	Y = 2LL*y;
	
	X1 = X - dx;
	X2 = X + dx;
	
	Y1 = Y - dy;
	Y2 = Y + dy;
	
	if ( X1 < 0 )
	{
		long long de = -X1;
		X1 += de;
		X2 += de;
	}
	else if ( X2 > 2LL*n )
	{
		long long de = X2 - 2LL*n;
		X1 -= de;
		X2 -= de;
	}
	
	if ( Y1 < 0 )
	{
		long long de = -Y1;
		Y1 += de;
		Y2 += de;
	}
	else if ( Y2 > 2LL*m )
	{
		long long de = Y2 - 2LL*m;
		Y1 -= de;
		Y2 -= de;
	}
	
	if ( X1 % 2 )
	{
		X1--;
		X2--;
	}
	if ( Y1 % 2 )
	{
		Y1--;
		Y2--;
	}
	
	printf( "%d %d %d %d\n", (int) (X1/2), (int) (Y1/2), (int) (X2/2), (int) (Y2/2) );
	return 0;
}