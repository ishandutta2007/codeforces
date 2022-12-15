#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std ;

const int MAX_N = 100000 + 10 ;

bool sock[MAX_N] ;
int n , t , sum , res ;

int main()
{
	sum = 0 ; res = 0 ;
	memset(sock , 0 , sizeof(sock)) ;

	scanf("%d" , &n) ;

	for (int i = 0 ; i < 2 * n ; ++i)
	{
		int t ;
		scanf("%d" , &t) ;

		if (!sock[t]) {sock[t] = 1 ; ++sum ; res = max(res , sum) ;}
		else {sock[t] = 0 ; --sum ;}
	}

	printf("%d\n" , res) ;

	return 0 ;
}