#include <cstdio>
#include <cstring>

int mxsz = 0;
int et = 0;
int n, t, x;

int main()
{
	int i;
	int qsz = 0;
	
	int lt = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &t, &x );
		qsz = qsz - (t-lt);
		if ( qsz < 0 ) qsz = 0;
		
		qsz += x;
		if ( qsz > mxsz )
			mxsz = qsz;
		
		lt = t;
	}
	
	et = lt + qsz;
	
	printf( "%d %d\n", et, mxsz );
	return 0;
}