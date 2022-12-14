#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

long long ans = 1;

char s[1<<20];
char out[1<<20];
int len;
set<char> us;

int main()
{
	int i, j, k;
	int t0 = 0;
	scanf( "%s", s );
	len = strlen( s );
	
	long long p = 10;;
	
	if ( s[0] == '?' || (s[0] >='A'&&s[0]<='J') )
	{
		ans = 9;
		if ( s[0] != '?' )
		{
			p = 9;
			us.insert( s[0] );
		}
	}
	for ( i = 1; i < len; i++ )
	{
		if ( s[i] == '?' )
		{
			out[t0++] = '0';
		}
		if ( s[i] >= 'A' && s[i] <= 'J' )
		{
			if ( us.find( s[i] ) == us.end() )
			{
				ans *= p;
				p--;
				us.insert( s[i] );
			}
		}
	}
	out[t0] = '\0';
	printf( "%I64d", ans );
	printf( "%s\n", out );
	return 0;
}