#include <cstdio>

int n, k, pr = 0;
int a[128];

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	
	int i;
	pr = 0;
	fscanf( fin, "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		fscanf( fin, "%d", &a[i] );
		if ( a[i] >= k )
		{
			a[i] = a[i] - k;
		}
		if ( a[i] >= k )
		{
			a[i] = a[i] - k;
		}
		if ( a[i] >= k )
		{
			a[i] = a[i] - k;
		}
		pr = pr + a[i];
	}
	fprintf( fout, "%d\n", pr );
	
	fclose( fin );
	fclose( fout );
	return 0;
}