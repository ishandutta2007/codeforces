#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e6 + 10 ;

bool chk[MAX_N] ;
int T , n , m , tot , prime[MAX_N] ;

void euler() {
	n = 1e6 ;

	chk[1] = 1 ;
	for (int i = 2 ; i <= n ; ++i) {
		if (!chk[i]) prime[tot++] = i ;
		for (int j = 0 ; j < tot ; ++j) {
			ll tmp = (ll)i * prime[j] ;
			if (tmp > n) break ;

			chk[tmp] = 1 ;
			if (!(i % prime[j])) break ;
		}
	}
}

int find(int x) {
	for (int i = 0 ; i < tot ; ++i)
		if (prime[i] >= x) return prime[i] ;
}

int main() {
	euler() ;

	scanf("%d" , &T) ;
	for (; T-- ;) {
		int d ; scanf("%d" , &d) ;
		int a = find(1 + d) , b = find(a + d) ;

		printf("%d\n" , a * b) ;
	}

	return 0 ;
}