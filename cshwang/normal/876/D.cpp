#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 3e5 + 10 ;

int n , minp , p[MAX_N] , BIT[MAX_N] ;

///

int lowbit(int x) {return x & (-x) ;}

void add(int x) {
	for (; x <= n ; x += lowbit(x)) ++BIT[x] ;
}

int GetSum(int x) {
	int s = 0 ;
	for (; x > 0 ; x -= lowbit(x)) s += BIT[x] ;

	return s ;
}

int sum(int x , int y) {
	if (x <= 0) return GetSum(y) ;
	else return GetSum(y) - GetSum(x - 1) ;
}

///

int findONE() {
	int L = -1 , R = n ;
	while (L + 1 < R) {
		int mid = (L + R) >> 1 , len = R - mid + 1 ;
		if (sum(mid , R) == len) R = mid ;
		else L = mid ;
	}

	if (sum(R , R)) return L ;
	else return R ;
}

///

int main() {
	scanf("%d" , &n) ;
	printf("1 ") ; minp = n ;
	for (int i = 0 ; i < n ; ++i) {
		int a ; scanf("%d" , &a) ;
		add(a) ; minp = std::min(minp , a) ;

		int p = findONE() , s = sum(1 , p) + 1 ;
		printf("%d " , s) ;
	}
	printf("\n") ;

	return 0 ;
}