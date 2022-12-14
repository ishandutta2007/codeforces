#include <cstdio>
#include <cstring>

long long sm;
long long el[1<<20];
long long ch[1<<20];

int main()
{
	int k, x, a;
	int stop;
	int n;
	scanf( "%d", &n );
	sm = 0;
	memset( ch, 0, sizeof( ch ) );
	stop = 1;
	el[stop] = ch[stop] = 0;
	for ( int te = 0; te < n; te++ )
	{
		int t;
		scanf( "%d", &t );
		if ( t == 1 )
		{
			scanf( "%d %d", &a, &x );
			sm += (long long) x * a;
			ch[a] += (-x);
		}
		else if ( t == 2 )
		{
			scanf( "%d", &k );
			sm += k;
			stop++;
			ch[stop] = 0;
			el[stop] = k;
		}
		else if ( t == 3 )
		{
			sm -= el[stop];
			sm += ch[stop];
			ch[stop-1] += ch[stop];
			stop--;
		}
		
		printf( "%.10lf\n", (double)sm/stop );
	}
	return 0;
}