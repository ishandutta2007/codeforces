#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBGU printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

int n , a[MAX_N] , mxl[MAX_N] , mxr[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	int ans = 0 ;
	mxl[1] = mxr[n] = 0 ;
	for (int i = 2 ; i <= n ; ++i)
		if (a[i - 1] > a[i]) ++mxl[1] ;
		else break ;
	for (int i = n - 1 ; i ; --i)
		if (a[i + 1] > a[i]) ++mxr[n] ;
		else break ;

	for (int i = 2 ; i < n ; ++i)
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			int l = 0 , r = 0 ;
			for (; i - l - 1 > 0 && a[i - l] > a[i - l - 1] ; ++l) ;
			for (; i + r + 1 <= n && a[i + r] > a[i + r + 1] ; ++r) ;

			mxl[i] = std::max(mxl[i - 1] , std::max(l , r)) ;
		}
		else mxl[i] = mxl[i - 1] ;

	for (int i = n - 1 ; i > 1 ; --i)
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			int l = 0 , r = 0 ;
			for (; i - l - 1 > 0 && a[i - l] > a[i - l - 1] ; ++l) ;
			for (; i + r + 1 <= n && a[i + r] > a[i + r + 1] ; ++r) ;

			mxr[i] = std::max(mxr[i + 1] , std::max(l , r)) ;
		}
		else mxr[i] = mxr[i + 1] ;

	for (int i = 2 ; i < n ; ++i)
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			int l = 0 , r = 0 ;
			for (; i - l - 1 > 0 && a[i - l] > a[i - l - 1] ; ++l) ;
			for (; i + r + 1 <= n && a[i + r] > a[i + r + 1] ; ++r) ;

			int p1 = l & 1 ? l : l - 1 , p2 = r & 1 ? r : r - 1 , p3 = std::max(mxl[i - 1] , mxr[i + 1]) ;
			if (r > p1 && l > p2 && l > p3 && r > p3) ++ans ;
		}

	printf("%d\n" , ans) ;

	return 0 ;
}