#include <cstdio>

int n, k, A;
int b[16], l[16];
int nl[16];

double be;

void solve()
{
	int ma, i, j;
	int B;
	double pr, cr = 0;
	
	for ( ma = 0; ma < (1<<n); ma++ )
	{
		pr = 1;
		B = 0;
		j = 0;
		for ( i = 0; i < n; i++ )
		{
			if ( ma&(1<<i) )
			{
				pr = pr * (double)nl[i+1]/100.0;
				j++;
			}
			else
			{
				pr = pr*(double)(100-nl[i+1])/100.0;
				B = B + b[i+1];
			}
		}
		if ( j > n-j )
		{
//			printf( "PR %lf\n", pr );
			cr = cr + pr;
		}
		else
		{
//			printf( "PR %d %d -> %lf %lf\n", A, B, pr, pr*((double)A/((double)A+(double)B)) );
			cr = cr + pr*((double)A/((double)A+(double)B));
		}
	}
	if ( cr > be )
	{
		be = cr;
	}
}

void rec( int cr, int re )
{
	if ( cr > n )
	{
		solve();
		return;
	}
	for ( int i = 0; i <= re && l[cr]+10*i <= 100; i++ )
	{
		nl[cr] = l[cr] + i*10;
		rec( cr+1, re-i );
	}
}

int main()
{
	be = 0;
	int i;
	
	scanf( "%d %d %d", &n, &k, &A );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &b[i], &l[i] );
		nl[i] = l[i];
	}
	
	rec( 1, k );
	printf( "%.10lf\n", be );
	return 0;
}