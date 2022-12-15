#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

char s[20] ;
int n , k , x , y ;

bool check(int x , int y) {
	printf("1 %d %d\n" , x , y) ;
	fflush(stdout) ;

	scanf("%s" , s) ;
	if (s[0] == 'T') return 1 ;
	else return 0 ;
}

int find(int x , int y) {
	if (x > y) return -1 ;

	for (; x < y ;) {
		int mid = (x + y) >> 1 ;
		if (check(mid , mid + 1)) y = mid ;
		else x = mid + 1 ;
	}

	return x ;
}

int main() {
	scanf("%d %d" , &n , &k) ;

	x = find(1 , n) ;
	y = find(1 , x - 1) ;
	if (y == -1 || !check(y , x)) y = find(x + 1 , n) ;

	printf("2 %d %d\n" , x , y) ;

	return 0 ;
}