#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int n , k , sum ;

int main()
{
	scanf("%d %d" , &n , &k) ;
	for (int i = 0 ; i < n ; ++i)
	{
		int a ; scanf("%d" , &a) ;
		sum += a ;
	}

	///

	int t = n ;
	while (floor(sum * 1.0 / t + 0.5) < k)
	{
		sum += k ; ++t ;
	}

	printf("%d\n" , t - n) ;

	return 0 ;
}