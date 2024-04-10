#include <bits/stdc++.h>

int T , n , m , ma , mb ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		ma = mb = 0 ;
		for (int i = 0 ; i < m ; ++i) {
			int a , b ; scanf("%d %d" , &a , &b) ;
			ma = std::max(ma , a) ; mb = std::max(mb , b) ;
		}

		if (ma + mb > n) {printf("IMPOSSIBLE\n") ; continue ;}
		for (int i = 0 ; i < ma ; ++i) printf("R") ;
		for (int i = 0 ; i < n - ma ; ++i) printf("W") ;
		printf("\n") ;
	}

	return 0 ;
}