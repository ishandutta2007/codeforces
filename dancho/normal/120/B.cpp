#include <cstdio>

int n, k;
int a[1024];

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	
	int i, j;
	fscanf( fin, "%d %d", &n, &k );
	for ( i = 0; i < n; i++ )
	{
		fscanf( fin, "%d", &a[i] );
	}
	for ( j = k-1; ; j = (j+1)%n )
	{
		if ( a[j] == 1 )
		{
			fprintf( fout, "%d\n", j+1 );
			break;
		}
	}
	
	fclose( fin );
	fclose( fout );
	return 0;
}