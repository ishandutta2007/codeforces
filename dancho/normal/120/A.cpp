#include <cstdio>

int main()
{
	FILE * fin = fopen( "input.txt", "r" );
	FILE * fout = fopen( "output.txt", "w" );
	char x[16];
	int a;
	fscanf( fin, "%s", x );
	fscanf( fin, "%d", &a );
	if ( ( x[0] == 'f' ) && ( a == 1 ) )
	{
		fprintf( fout, "L\n" );
	}
	else if ( ( x[0] == 'f' ) && ( a == 2 ) ) 
		fprintf(fout, "R\n" );
	else if ( ( x[0] == 'b' ) && ( a == 1 ) )
		fprintf( fout, "R\n" );
	else
		fprintf( fout, "L\n" );
	fclose( fin );
	fclose( fout );
	return 0;
}