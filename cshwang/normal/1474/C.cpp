#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e3 + 10 ;

std::multiset<int> st ;

int T , n , m , a[MAX_N] , x[MAX_N] , y[MAX_N] ;

bool work(int pd) {
	st.clear() ;
	for (int i = 1 ; i <= m ; ++i) st.insert(a[i]) ;

	x[0] = a[m] ; y[0] = a[pd] ;

	std::multiset<int> :: iterator p ;

	p = st.find(x[0]) ; st.erase(p) ;
	p = st.find(y[0]) ; st.erase(p) ;

	int nw = x[0] ;
	for (int i = 1 ; i < n ; ++i) {
		int n1 , n2 ;
		p = st.end() ; --p ;
		n1 = *p ; n2 = nw - n1 ;
		st.erase(p) ;

		if (!st.count(n2)) return 0 ;
		p = st.find(n2) ;

		x[i] = n1 ; y[i] = n2 ;
		st.erase(p) ; nw = n1 ;
	}

	return 1 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ; m = n << 1 ;
		for (int i = 1 ; i <= m ; ++i) scanf("%d" , &a[i]) ;
		std::sort(a + 1 , a + 1 + m) ;

		///

		bool ok = 0 ;
		for (int i = 1 ; i < m ; ++i)
			if (work(i)) {ok = 1 ; break ;}

		if (ok) {
			printf("YES\n%d\n" , x[0] + y[0]) ;
			for (int i = 0 ; i < n ; ++i) printf("%d %d\n" , x[i] , y[i]) ;
		}
		else printf("NO\n") ;
	}

	return 0 ;
}