#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 100 + 10 ;

int T , n , a[MAX_N] , cnt[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 0 ; i < n ; ++i) {
			int a ; scanf("%d" , &a) ;
			++cnt[a] ;
		}
		for (int i = 0 ; i < n ; ++i)
			if (cnt[i]) printf("%d " , i) , --cnt[i] ;
		for (int i = 0 ; i <= 100 ; ++i)
			for (; cnt[i] ; --cnt[i]) printf("%d " , i) ;
		printf("\n") ;
	}

	return 0 ;
}