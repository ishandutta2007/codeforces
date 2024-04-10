#include <cstdio>
#include <cstring>

char op[256];

int n, be, bl, br;
char b[100020];

int st[100020], stop;

int cnt[100020];

int main()
{
	int i;
	
	scanf( "%s", b );
	n = strlen( b );
	
	cnt[0] = (b[0] == '[');
	for ( i = 1; i < n; i++ )
	{
		cnt[i] = cnt[i-1] + (b[i] == '[');
	}
	
	memset( op, -1, sizeof( op ) );
	op[ (int) ')' ] = '(';
	op[ (int) ']' ] = '[';
	
	stop = 0;
	st[stop] = -1;
	be = -1;
	for ( i = 0; i < n; i++ )
	{
		if ( ( b[i] == ']' ) || ( b[i] == ')' ) )
		{
			if ( ( st[stop] == -1 ) || ( op[ (int) b[i] ] != b[ st[stop] ] ) )
			{
				//ne moga da se zatvorya => probvam dotuk st[stop] + 1 do i-1
				if ( st[stop]+1 <= i-1 )
				{
					if ( cnt[i-1] - cnt[ st[stop] ] > be )
					{
						be = cnt[i-1] - cnt[ st[stop] ];
						bl = st[stop]+1;
						br = i-1;
					}
				}
				st[++stop] = i;
			}
			else stop--;
		}
		else
		{
			if ( st[stop]+1 <= i-1 )
			{
				if ( cnt[i-1] - cnt[ st[stop] ] > be )
				{
					be = cnt[i-1] - cnt[ st[stop] ];
					bl = st[stop]+1;
					br = i-1;
				}
			}
			st[++stop] = i;
		}
	}
	
	i = n;
			if ( st[stop]+1 <= i-1 )
			{
				if ( cnt[i-1] - cnt[ st[stop] ] > be )
				{
					be = cnt[i-1] - cnt[ st[stop] ];
					bl = st[stop]+1;
					br = i-1;
				}
			}
	
	if ( be == -1 )
	{
		printf( "0\n" );
	}
	else
	{
		printf( "%d\n", be );
		for ( i = bl; i <= br; i++ )
			printf( "%c", b[i] );
		printf( "\n" );
	}
	return 0;
}