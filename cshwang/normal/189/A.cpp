#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 4e3 + 10 ;

int n , a , b , c , f[MAX_N] ;

int main() {
	scanf("%d %d %d %d" , &n , &a , &b , &c) ;

	f[0] = 1 ;
	for (int i = 0 ; i <= n ; ++i) {
		int s1 = i - a >= 0 ? f[i - a] : 0 ,
			s2 = i - b >= 0 ? f[i - b] : 0 ,
			s3 = i - c >= 0 ? f[i - c] : 0 ;

		if (!s1 && !s2 && !s3) continue ;
		f[i] = std::max(s1 , std::max(s2 , s3)) + 1 ;
	}

	printf("%d\n" , f[n] - 1) ;

	return 0 ;
}