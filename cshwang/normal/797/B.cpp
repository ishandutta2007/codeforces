#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 100000 + 10 ;

int n ;
int c1 , c2 , js[MAX_N] , os[MAX_N] ;

bool cmp(int x , int y) {return x > y ;}

int main()
{
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i)
	{
		int a ;
		scanf("%d" , &a) ;
		if (a % 2) js[c1++] = a ;
		else os[c2++] = a ;
	}
	std::sort(js + 0 , js + c1 , cmp) ;
	std::sort(os + 0 , os + c2 , cmp) ;

	///
	
	int sum = js[0] ;
	for (int i = 1 ; i + 1 < c1 ; i += 2)
		if (js[i] + js[i + 1] > 0) sum += (js[i] + js[i + 1]) ;
		else break ;
	for (int i = 0 ; i < c2 ; ++i)
		if (os[i] > 0) sum += os[i] ;
		else break ;

	printf("%d\n" , sum) ;

	return 0 ;
}