#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long rv[101][2601];

long long gr( int p, int s )
{
	if ( p == 0 && s == 0 ) return 1;
	if ( p == 0 && s != 0 ) return 0;
	if ( p < 0 || s < 0 ) return 0;
	if ( rv[p][s] != -1 ) return rv[p][s];
	long long sol = 0;
	for (int i = 0; i <= 25; i++)
	{
		sol = sol + gr( p-1, s-i );
		if ( sol >= mod ) sol = sol % mod;
	}
	rv[p][s] = sol;
	return rv[p][s];
}

char s[128];

int main()
{
	int i, j, l;
	
	memset( rv, -1, sizeof( rv ) );
	
	int t, T;
	long long ans;
	
	scanf( "%d", &T );
	for ( t = 0; t < T; t++ )
	{
		scanf( "%s", s );
		j = 0;
		for ( l = strlen( s ), i = 0; i < l; i++ )
		{
			j = j + s[i]-'a';
		}
		ans = gr( l, j );
		ans = (ans+mod-1) % mod;
		printf( "%d\n", (int) ans );
	}
	return 0;
}