#include <cstdio>
#include <cstring>

int n, w[1<<20], l, r, ql, qr;
long long ps[1<<20];

int main()
{
	scanf( "%d %d %d %d %d", &n, &l, &r, &ql, &qr );
	int i, j, k;
	
	ps[0] = 0;
	for ( i = 1; i <= n; ++i )
	{
		scanf( "%d", &w[i] );
		ps[i] = ps[i-1] + w[i];
	}
	
	long long bsol = (1LL<<60);
	for ( i = 0; i <= n; ++i )
	{
		int cl = i;
		int cr = n-i;
		long long pr = ps[i] * l + (ps[n]-ps[i])*r;
		if ( cl > cr )
			pr += ql*(cl-cr-1);
		else if ( cr > cl )
			pr += qr*(cr-cl-1);
		if ( pr < bsol )
			bsol = pr;
	}
	printf( "%I64d\n", bsol );
	return 0;
}