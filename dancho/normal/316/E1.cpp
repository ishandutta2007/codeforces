#include <cstdio>
#include <cstring>

const int mod = 1000000000;

int n, m, t;
long long f[1<<20];
long long a[1<<20];

int main()
{
	int i, j, k;
	f[0] = f[1] = 1;
	
	for ( i = 2; i <= 1000000; i++ )
	{
		f[i] = f[i-1] + f[i-2];
		if ( f[i] >= mod )
			f[i] %= mod;
	}
	
	long long sm;
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		a[i] = k;
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d %d", &t, &j, &k );
		if ( t == 1 )
		{
			a[j] = k;
		}
		else
		{
			sm = 0;
			for ( int l = 0; l <= k-j; l++ )
			{
				sm += f[l]*a[l+j];
				if ( sm >= mod )
					sm %= mod;
			}
			printf( "%d\n", (int) sm );
		}
	}
	return 0;
}