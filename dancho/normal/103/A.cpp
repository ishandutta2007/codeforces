#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[10000];
long long sm[1000];

int main()
{
	int i;
	long long ans = 0;
	
	scanf( "%d", &n );
	sm[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		sm[i] = sm[i-1] + a[i];
	}
	
	for ( i = 1; i <= n; i++ )
	{
		ans = ans + (long long)(i-1)*(a[i]-1) + a[i];
	}
	cout << ans << endl;
	return 0;
}