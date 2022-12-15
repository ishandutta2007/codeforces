#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e5 + 10 ;

struct Val
{
	long long w1 , w2 , dw ;
}list[MAX_N] ;

int n , f ;
long long sum ;

bool cmp(Val x , Val y)
{
	return x.dw > y.dw ;
}

int main()
{
	sum = 0 ;

	scanf("%d %d" , &n , &f) ;
	for (int i = 0 ; i < n ; ++i)
	{
		long long k , l ; scanf("%I64d %I64d" , &k , &l) ;
		list[i].w1 = std::min(k , l) ;
		list[i].w2 = std::min(2 * k , l) ;
		list[i].dw = list[i].w2 - list[i].w1 ;

		sum += list[i].w1 ;
	}

	///

	std::sort(list + 0 , list + n , cmp) ;

	///
	
	for (int i = 0 ; i < f ; ++i) sum += list[i].dw ;
	printf("%I64d\n" , sum) ;

	return 0 ;
}