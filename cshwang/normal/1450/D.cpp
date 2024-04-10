#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 ;

int T , n , a[MAX_N] , ap[MAX_N] , tre[MAX_N << 2] , ans[MAX_N] ;

void build(int t , int x , int y) {
	if (x == y) {tre[t] = a[x] ; return ;}

	int mid = (x + y) >> 1 ;
	build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
	tre[t] = std::min(tre[t << 1] , tre[t << 1 | 1]) ;
}

int getmin(int t , int x , int y , int fx , int fy) {
	if (fy < x || y < fx) return n + 1 ;
	if (fx <= x && y <= fy) return tre[t] ;

	int mid = (x + y) >> 1 ,
		s1 = getmin(t << 1 , x , mid , fx , fy) ,
		s2 = getmin(t << 1 | 1 , mid + 1 , y , fx , fy) ;

	return std::min(s1 , s2) ;
}

void work(int k , int x , int y) {
	if (k == n) return ;

	int nw = n - k + 1 ;
	if (getmin(1 , 1 , n , x , y) != k) return ;
	ans[nw] = 1 ;

	if (a[x] == k) {
		if (getmin(1 , 1 , n , x + 1 , y) != k) work(k + 1 , x + 1 , y) ;
	}
	else {
		if (getmin(1 , 1 , n , x , y - 1) != k) work(k + 1 , x , y - 1) ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 1 ; i <= n ; ++i) ap[i] = ans[i] = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			scanf("%d" , &a[i]) ;
			++ap[a[i]] ;
		}
		ans[1] = 1 ;
		for (int i = 1 ; i <= n ; ++i) if (ap[i] != 1) ans[1] = 0 ;

		///

		build(1 , 1 , n) ;
		work(1 , 1 , n) ;

		for (int i = 1 ; i <= n ; ++i) printf("%d" , ans[i]) ;
		printf("\n") ;
	}

	return 0 ;
}