#include <cstdio>

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	int t, T, n;
	fscanf( fin, "%d", &T );
	for ( t = 0; t < T; t++ )
	{
		fscanf( fin, "%d", &n );
		if ( n % 2 == 0 ) fprintf( fout, "1\n" );
		else fprintf( fout, "0\n" );
	}
	
	fclose( fin );
	fclose( fout );
	return 0;
}