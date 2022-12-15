#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX_N = 1e3 + 10 ;

int n , cnt , ans[MAX_N] ;

bool check(int a , int tot) {
	int s = 0 ;
	for (; a > 0 ; s += (a % 10) , a /= 10) ;

	return s == tot ;
}

int main() {
	scanf("%d" , &n) ;

	for (int i = 0 ; i <= 100 ; ++i) {
		int a = n - i ;
		if (check(a , i)) ans[cnt++] = a ;
	}
	
	///

	std::sort(ans + 0 , ans + cnt) ;

	///

	printf("%d\n" , cnt) ;
	for (int i = 0 ; i < cnt ; ++i) printf("%d\n" , ans[i]) ;

	return 0 ;
}