#include <stdio.h>
#include <stdlib.h>
using namespace std ;

const int MAX_N = 50 + 10 ;

int n , m , sum[MAX_N] , color[MAX_N] ;

void filled(int x , int y)
{
	for (int i = 0 ; i <= n ; ++i)
	{
		if (sum[i]) continue ;
		color[x++] = i ; ++sum[i] ;

		if (x > y) return ;
	}
}

int main()
{
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < (n - m + 1) ; ++i)
	{
		if (i > 0) --sum[color[i]] ;

		char q[10] ; getchar() ;
		scanf("%s" , q) ;

		///

		int x = i + 1 , y = i + m ;
		if (i == 0) filled(x , y - 1) ;

		if (q[0] == 'N') color[y] = color[x] , ++sum[color[x]] ;
		else filled(y , y) ;
	}

	for (int i = 1 ; i <= n ; ++i)
	{
		char word ;
		int len = color[i] / 26 , num = color[i] % 26 ;

		if (len == 1) printf("A") ;

		word = len ? 'a' : 'A' ;
		printf("%c" , word + num) ;

		if (i == n) printf("\n") ; else printf(" ") ;
	}

	return 0 ;
}