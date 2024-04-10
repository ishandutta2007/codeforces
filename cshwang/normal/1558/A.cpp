#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 ;

int T , a , b ;
bool ap[MAX_N] ;

void check(int x , int y) {
	for (int i = 0 ; i <= std::min(a , x) ; ++i)
		if (a - i <= y) ap[x - i + a - i] = 1 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &a , &b) ;

		///

		int n = a + b ;
		for (int i = 0 ; i <= n ; ++i) ap[i] = 0 ;

		check(n >> 1 , n - (n >> 1)) ; check(n - (n >> 1) , n >> 1) ;

		int tot = 0 ;
		for (int i = 0 ; i <= n ; ++i) if (ap[i]) ++tot ;

		printf("%d\n" , tot) ;
		for (int i = 0 ; i <= n ; ++i) if (ap[i]) printf("%d " , i) ;
		printf("\n") ;
	}

	return 0 ;
}