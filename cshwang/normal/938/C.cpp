#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

int t , x ;

int find(int n , int k) {
	if (!k) return 0 ;

	int L = 0 , R = n + 1 ;

	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;

		if (n / mid == k) return mid ;
		else if (n / mid > k) L = mid ;
		else R = mid ;
	}

	return 0 ;
}

void work(int x) {
	bool ok = 0 ;
	for (int i = 1 ; i * i <= x && !ok ; ++i) {
		if (x % i) continue ;

		int j = x / i ;

		if ((i + j) % 2) continue ;

		int n = (i + j) / 2 , nm = j - n , m = find(n , nm) ;
		if (!m) continue ;

		printf("%d %d\n" , n , m) ;
		ok = 1 ;
	}

	if (!ok) printf("-1\n") ;
}

int main() {
	scanf("%d" , &t) ;
	for (; t-- ;) {
		scanf("%d" , &x) ;

		if (x == 0) printf("1 1\n") ;
		else work(x) ;
	}

	return 0 ;
}