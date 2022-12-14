#include <cstdio>
#include <cstring>

inline double max( const double &a, const double &b )
{
	if ( a > b ) return a;
	return b;
}

inline double min( const double &a, const double &b )
{
	if ( a < b ) return a;
	return b;
}

const int bsz = 400;

int n, m;

double c;
double x[300020], pr[300020];

double ps[300020], f[300020];

double mib[300020], mxb[300020], sb[300020];

int main()
{
	int i, j, k, l;
	double ans = 0, sl;
	
	scanf( "%d %d %d", &n, &m, &k );
	c = (double) k;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		x[i] = (double)k;
		//scanf( "%lf", &x[i] );
	}
	for ( i = 1; i < n; i++ )
	{
		scanf( "%d", &k );
		pr[i] = (double)k/100.0;
	}
	
	ps[0] = 0;
	for ( i = 1; i < n; i++ )
	{
		ps[i] = ps[i-1] + c*pr[i];
		f[i] = x[i+1]/2.0 - ps[i];
		
//		printf( "F %d %lf\n", i, f[i] );
	}
	
	double mi;
	k = 0;
		mi = 1e100;
		mib[k] = 1e100;
		mxb[k] = -1e100;
		sb[k] = 0.0;
	for ( i = 1; i < n; i++ )
	{
		if ( i % bsz == 0 )
		{
			k++;
			mi = 1e100;
			mib[k] = 1e100;
			mxb[k] = -1e100;
			sb[k] = 0.0;
		}
		mxb[k] = max( mxb[k], f[i] );
		sb[k] = max( sb[k], f[i] - mib[k] );
		mib[k] = min( mib[k], f[i] );
	}
	
	f[0] = 0.0;
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &j, &k );
		sl = max( 0.0, f[k-1]-f[j-1] );
		mi = f[j-1];
		for ( l = j; l < k; l++ )
		{
			if ( l%bsz == 0 ) break;
			mi = min( mi, f[l] );
			sl = max( sl, f[l] - mi );
		}
		if ( l < k )
		{
			for ( l = l/bsz; (l+1)*bsz-1 < k; l++ )
			{
				sl = max( sl, sb[l] );
				sl = max( sl, mxb[l] - mi );
				mi = min( mi, mib[l] );
			}
			for ( l = l*bsz; l < k; l++ )
			{
				mi = min( mi, f[l] );
				sl = max( sl, f[l] - mi );
			}
		}
		//printf( "HOHO %d %d %lf\n", j, k, sl );
		ans = ans + sl;
	}
	
	printf( "%.9lf\n", ans );
	return 0;
}