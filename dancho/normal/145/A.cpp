#include <cstdio>
#include <cstring>

char a[1000000];
int a4, a7;
char b[1000000];
int b4, b7;

int main()
{
	int i;
	int f4 = 0, f7 = 0, ans = 0;
	int n;
	
	scanf( "%s", a );
	scanf( "%s", b );
	n = strlen( a );
	
	a4 = a7 = b4 = b7 = 0;
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] == '4' ) a4++;
		else if ( a[i] == '7' ) a7++;
		if ( b[i] == '4' ) b4++;
		else if ( b[i] == '7' ) b7++;
	}
	
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] == b[i] ) continue;
		else if ( ( f4 > 0 ) && ( a[i] == '7' ) )
		{
			f4--;
			continue;
		}
		else if ( ( f7 > 0 ) && ( a[i] == '4' ) )
		{
			f7--;
			continue;
		}
		else
		{
			if ( ( a[i] == '4' ) && ( a7 > 0 ) )
			{
				f4++;
				a7--;
				ans++;
			}
			else if ( ( a[i] == '4' ) && ( a7 == 0 ) )
			{
				ans++;
			}
			else if ( ( a[i] == '7' ) && ( a4 > 0 ) )
			{
				f7++;
				a4--;
				ans++;
			}
			else if ( ( a[i] == '7' ) && ( a4 == 0 ) )
			{
				ans++;
			}
		}
	}
	printf( "%d\n", ans );
	return 0;
}