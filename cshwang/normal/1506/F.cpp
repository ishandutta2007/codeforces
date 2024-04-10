#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

struct data {int x , y ;}a[MAX_N] ;

int T , n ;

bool cmp(data a , data b) {return a.x < b.x ;}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;
		for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i].x) ;
		for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i].y) ;

		///

		data pre = (data){1 , 1} ;
		std::sort(a + 0 , a + n , cmp) ;

		int ans = 0 ;
		for (int i = a[0].x > 1 ? 0 : 1 ; i < n ; ++i) {
			int st = (a[i].x + a[i].y) & 1 , c1 = a[i].x - a[i].y , c2 = pre.x - pre.y ;
			if (c1 == c2 && !st) ans += a[i].x - pre.x ;
			else if (st) ans += (c1 - c2) >> 1 ;
			else ans += (c1 - c2 + 1) >> 1 ;

			pre = a[i] ;
		}

		printf("%d\n" , ans) ;
	}

	return 0 ;
}