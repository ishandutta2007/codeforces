#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 4e6 + 10 ;

char s[MAX_N] ;
bool ap[MAX_N] ;
int T , n , k , m , pl[MAX_N] ;

void print(int x) {
	int tmp[40] , s = 0 ;
	for (; x ; x >>= 1) tmp[++s] = x & 1 ;

	for (int i = 0 ; i < k - s ; ++i) printf("0") ;
	for (int i = s ; i ; --i) printf("%d" , tmp[i]) ;
	printf("\n") ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ; getchar() ;
		scanf("%s" , s) ; for (int i = 0 ; i < n ; ++i) s[i] ^= 1 ;

		///

		int mk = 0 ; m = 1 ;
		for (int i = 0 ; i < k ; ++i) {
			m <<= 1 ; ++mk ;
			if (m > n - k + 1) break ;
		}
		for (int i = 0 ; i < m ; ++i) ap[i] = 0 ;

		///

		int tot = 0 , pt = 0 ;
		for (int i = 0 ; i < n ; ++i) if (s[i] == '1') pl[tot++] = i ;

		for (int i = 0 ; i < n ; ++i) {
			int j = i + k - 1 ;
			if (j >= n) break ;

			if (pl[pt] < i && pt < tot) ++pt ;
			if (pt == tot) {ap[0] = 1 ; continue ;}
			if (j - pl[pt] >= mk) continue ;

			int res = 0 ;
			for (int p = 0 ; p < mk ; ++p)
				if (s[j - p] == '1') res += (1 << p) ;
			ap[res] = 1 ;
		}

		///

		int ans = -1 ;
		for (int i = 0 ; i < m ; ++i) if (!ap[i]) {ans = i ; break ;}

		if (ans != -1) {printf("YES\n") ; print(ans) ;}
		else printf("NO\n") ;
	}

	return 0 ;
}