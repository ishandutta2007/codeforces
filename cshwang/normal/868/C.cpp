#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10 , MAX_K = 4 + 10 , MAX_T = 16 + 10 ;

bool sta[MAX_T] , ans ;
int n , k , ed , t[MAX_K] ;

void find(int x , int tot) {
	if (x == ed) {
		if (!tot) return ;
		for (int i = 0 ; i < k ; ++i)
			if (t[i] > tot / 2) return ;

		ans = 1 ;
		return ;
	}
	if (ans) return ;

	if (!sta[x]) {
		find(x + 1 , tot) ;
		return ;
	}

	find(x + 1 , tot) ;
	for (int i = 0 ; i < k ; ++i) if ((1 << i) & x) ++t[i] ;
	find(x + 1 , tot + 1) ;
	for (int i = 0 ; i < k ; ++i) if ((1 << i) & x) --t[i] ;
}

int main() {
	scanf("%d %d" , &n , &k) ; ed = (1 << k) ;
	for (int i = 0 ; i < n ; ++i) {
		int a , s = 0 ;
		for (int j = 0 ; j < k ; ++j) {
			scanf("%d" , &a) ;
	   		if (a) s += (1 << j) ;
		}

		sta[s] = 1 ;
	}

	///
	
	find(0 , 0) ;

	if (ans) printf("YES\n") ;
	else printf("NO\n") ;

	return 0 ;
}