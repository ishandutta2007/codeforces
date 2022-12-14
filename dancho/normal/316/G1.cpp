#include <cstdio>
#include <cstring>
#include <set>
#include <string>
using namespace std;

int n;
int ln;
char S[2048];

char p[16][2048];
int l[16], r[16];

set<string> crap;

int main()
{
	int i, j, k;
	int sol = 0;
	
	scanf( "%s", S );
	scanf( "%d", &n );
	
	for ( i = 0; i < n; i++ )
	{
		scanf( "%s %d %d", p[i], &l[i], &r[i] );
	}
	
	char *s = S;
	while ( *s != '\0' )
	{
//		printf( "%s\n", s );
		for ( j = 1; ; j++ )
		{
			char x = s[j];
			s[j] = '\0';
//			printf( "JJ %s %d\n", s, j );
			for ( k = 0; k < n; k++ )
			{
				int oc = 0;
				
				char *pi = p[k];
				while ( pi != NULL )
				{
					pi = strstr( pi, s );
					if ( pi == NULL ) break;
					pi++;
					oc++;
				}
				
				if ( oc < l[k] || oc > r[k] )
					break;
			}
			if ( k >= n )
			{
				if ( crap.find( s ) == crap.end() )
				{
					crap.insert( s );
					sol++;
				}
			}
			s[j] = x;
			if ( s[j] == '\0' )
				break;
		}
		s++;
	}
	printf( "%d\n", sol );
	return 0;
}