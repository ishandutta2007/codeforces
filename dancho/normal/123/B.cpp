#include <cstdio>

long long ia( long long x )
{
	if ( x < 0 ) return -x;
	return x;
}

long long sign( long long x )
{
	if ( x < 0 ) return -1;
	return 1;
}

int main()
{
	int A, B, X1, Y1, X2, Y2;
	long long a, b, x1, y1, x2, y2;
	long long ds, dr, cs, cr, rs, rr, nrs, nrr;
	//a = 2000000000;
	scanf( "%d %d %d %d %d %d", &A, &B, &X1, &Y1, &X2, &Y2 );
	a = A; b = B; x1 = X1; y1 = Y1; x2 = X2; y2 = Y2;
	
	ds = ia( (x1+y1) - (x2+y2) );
	dr = ia( (x1-y1) - (x2-y2) );
	cs = ds / (2LL*a);
	cr = dr / (2LL*b);
	rs = ds - cs*2LL*a;
	rr = dr - cr*2LL*b;
	nrs = (x1+y1)%(2LL*a);
	nrr = (x1-y1)%(2LL*b);
	
//	printf( "%lld\n", (-sign((x1-y1) - (x2-y2) ) ) );
	
	if ( ( nrs < 0 ) && ( nrs+rs*(-sign((x1+y1) - (x2+y2) ) ) > 0 ) )
		cs++;
	else if ( ( nrs < 0 ) && ( nrs+rs*(-sign((x1+y1) - (x2+y2) )) < -2LL*a ) )
		cs++;
	else if ( ( nrs > 0 ) && (nrs + rs*(-sign((x1+y1) - (x2+y2) )) > 2LL*a ) )
		cs++;
	else if ( ( nrs > 0 ) && (nrs + rs*(-sign((x1+y1) - (x2+y2) )) < 0 ) )
		cs++;
	
	if ( ( nrr < 0 ) && ( nrr+rr*(-sign((x1-y1) - (x2-y2))) > 0 ) )
		cr++;
	else if ( ( nrr < 0 ) && ( nrr+rr*(-sign((x1-y1) - (x2-y2))) < -2LL*b ) )
		cr++;
	else if ( ( nrr > 0 ) && ( nrr + rr*(-sign( (x1-y1) - (x2-y2))) > 2LL*b ) )
		cr++;
	else if ( ( nrr > 0 ) && ( nrr+rr*(-sign( (x1-y1) - (x2-y2))) < 0 ) )
		cr++;
	
//	printf( "%lld %lld\n", cs, cr );
//	printf( "%lld %lld _ %lld %lld : %lld %lld %lld %lld\n", ds, dr, cs, cr, rs, rr, nrs, nrr );
	if ( cs >= cr )
	{
		printf( "%I64d\n", cs );
	}
	else
	{
		printf( "%I64d\n", cr );
	}
	
	return 0;
}