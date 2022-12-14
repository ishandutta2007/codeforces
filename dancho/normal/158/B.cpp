#include <cstdio>
#include <cstring>

inline int min( const int &a, const int &b )
{
	if ( a < b ) return a;
	return b;
}

int n;
int b[8];

int main()
{
	int s;
	memset( b, 0, sizeof( b ) );
	scanf( "%d", &n );
	for (int i = 0; i < n; i++)
	{
		scanf( "%d", &s );
		b[s]++;
	}
	
	int sol = b[4];
	
	s = min( b[3], b[1] );
	sol = sol + s;
	b[3] = b[3] - s;
	b[1] = b[1] - s;
	sol = sol + b[3];
	
	sol = sol + b[2]/2;
	if ( b[2]%2 == 1 )
	{
		s = min( b[1], 2 );
		sol = sol + 1;
		b[1] = b[1] - s;
	}
	sol = sol + (b[1]+3)/4;
	printf( "%d\n", sol );
	return 0;
}