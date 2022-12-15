#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 , mod = 1e9 + 7 ;

int n , pa , pb , f[MAX_N][MAX_N] ;

int qpow(int a , int t) {
	int s = 1 , tmp = a ;
	for (; t ; t >>= 1 , tmp = (ll)tmp * tmp % mod)
		if (t & 1) s = (ll)s * tmp % mod ;

	return s ;
}

int getf(int x , int y) {
	if (x >= n) return x ;
	else if (y >= n) return (ll)x + y - 1 + qpow(pb , mod - 2) % mod ;
	else return f[x][y] ;
}

int main() {
	scanf("%d %d %d" , &n , &pa , &pb) ;
	int s = pa + pb ;
	pa = (ll)pa * qpow(s , mod - 2) % mod ; pb = (ll)pb * qpow(s , mod - 2) % mod ;

	///

	for (int i = n - 1 ; i >= 0 ; --i)
		for (int j = n - 1 ; j ; --j) {
			int st1 = getf(i , j + 1) , st2 = getf(i + j , j) ;
			f[i][j] = ((ll)pa * st1 + (ll)pb * st2) % mod ;
		}

	printf("%d\n" , getf(0 , 1)) ;

	return 0 ;
}