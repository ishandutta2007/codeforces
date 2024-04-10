#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 3e5 + 10 , MOD = 1e9 + 7 ;

int n ;
long long x[MAX_N] , fra , sum , res ;

int main()
{
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%I64d" , &x[i]) ;

	///

	std::sort(x + 0 , x + n) ;

	///
	
	fra = 2 ; sum = 0 ; res = 0 ;
	for (int i = 1 ; i < n ; ++i , fra = (fra * 2) % MOD , sum = (sum * 2) % MOD)
	{
		long long a1 = fra * (x[i] - x[0]) % MOD , a2 = x[i - 1] - x[i] ;

		res = (res + ((a1 + sum) % MOD + a2 + MOD) % MOD) % MOD ;

		sum = (sum + a2 + MOD) % MOD ;
	}

	printf("%I64d\n" , res) ;

	return 0 ;
}