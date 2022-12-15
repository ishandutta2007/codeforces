#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const ll INF = 1e16 ;
const int MAX_N = 1e7 + 10 ;

int n , m , num[MAX_N] , cnt[MAX_N] ;

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;

	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

int main() {
	n = read() ;
	for (int i = 0 ; i < n ; ++i) {
		int a = read() ; num[i] = a ;

		m = std::max(m , a) ; ++cnt[a] ;
	}

	///

	ll lcm = INF ; int pa = -1 , pb = -1 ;
	for (int i = 1 ; i <= m ; ++i) {
		int lef = 2 , a , b ;
		for (int j = i ; j <= m ; j += i)
			if (cnt[j]) {
				if (lef == 2 && cnt[j] > 1) {a = j ; b = j ; lef = 0 ;}
				else if (lef == 2 && cnt[j] == 1) {a = j ; lef = 1 ;}
				else if (lef == 1) {b = j ; lef = 0 ;}
			}

		if (!lef) {
			ll tmp = (ll)a * b / i ;

			if (tmp < lcm) lcm = tmp , pa = a , pb = b ;
		}
	}

	for (int i = 0 ; i < n ; ++i) if (pa == num[i]) {pa = i ; break ;}
	for (int i = 0 ; i < n ; ++i) if (pb == num[i] && pa != i) {pb = i ; break ;}

	++pa ; ++pb ;
	if (pa > pb) std::swap(pa , pb) ;
	printf("%d %d\n" , pa , pb) ;

	return 0 ;
}