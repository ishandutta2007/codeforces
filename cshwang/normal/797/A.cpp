#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 100000 + 10 ;

int n , k , cur , a[MAX_N] ;

int main()
{
	scanf("%d %d" , &n , &k) ;
	int i = 2 ;
	for (; n > 1 ; ++i)
		for (; !(n % i) ; n /= i) a[cur++] = i ;

	if (k > cur) printf("-1\n") ;
	else
	{
		for (int i = 0 ; i < k - 1 ; ++i)
			printf("%d " , a[i]) ;

		int sum = a[k - 1] ;
		for (int i = k ; i < cur ; ++i) sum *= a[i] ;
		printf("%d\n" , sum) ;
	}

	return 0 ;
}