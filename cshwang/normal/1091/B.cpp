#include <map>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

struct data {
	int x , y ;

	bool friend operator <(data p , data q) {return p.x < q.x || (p.x == q.x && p.y < q.y) ;}
}A[MAX_N] , B[MAX_N] , ans ;

std::map<data , int> cnt ;

int n ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d %d" , &A[i].x , &A[i].y) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d %d" , &B[i].x , &B[i].y) ;

	///

	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < n ; ++j) {
			data tmp = (data){A[i].x + B[j].x , A[i].y + B[j].y} ;

			++cnt[tmp] ;
			if (cnt[tmp] == n) ans = tmp ;
		}

	printf("%d %d\n" , ans.x , ans.y) ;

	return 0 ;
}