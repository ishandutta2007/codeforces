#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 100 + 10 , INF = 0x3f3f3f3f ;

int n , k , a[MAX_N] , b[MAX_N] ;

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 0 ; i < k ; ++i) scanf("%d" , &b[i]) ;

	///
	
	bool ok = 1 ;
	a[0] = -1 ; a[n + 1] = INF ;
	for (int i = 1 ; i <= n ; ++i) {
		if (!a[i]) {
			if (!a[i - 1] || !a[i + 1] || a[i - 1] > a[i + 1]) {ok = 0 ; break ;}

			bool f = 0 ;
			for (int j = 0 ; j < k ; ++j)
				if (b[j] < a[i - 1] || b[j] > a[i + 1]) {f = 1 ; break ;}
			if (f) {ok = 0 ; break ;}
		}
		else if (a[i - 1] && a[i - 1] > a[i]) {ok = 0 ; break ;}
	}

	if (ok) printf("No\n") ;
	else printf("Yes\n") ;

	 return 0 ;
}