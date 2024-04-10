#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 2e5 + 10 ;

struct Node {int num , lazy ;}tre[MAX_N << 2] ;

char s1[MAX_N] , s2[MAX_N] ;
int T , n , q , L[MAX_N] , R[MAX_N] ;

void build(int t , int x , int y) {
	if (x == y) {
		tre[t] = (Node){0 , -1} ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
}

void down(int t , int x , int y) {
	int L = t << 1 , R = t << 1 | 1 , mid = (x + y) >> 1 , a = tre[t].lazy ;
	if (a == -1) return ;

	tre[L].num = (mid - x + 1) * a ; tre[L].lazy = a ;
	tre[R].num = (y - mid) * a ; tre[R].lazy = a ;
	tre[t].lazy = -1 ;
}

void modify(int t , int x , int y , int fx , int fy , int a) {
	if (y < fx || fy < x) return ;
	if (fx <= x && y <= fy) {
		tre[t].num = (y - x + 1) * a ;
		tre[t].lazy = a ; return ;
	}
	down(t , x , y) ;

	int mid = (x + y) >> 1 ;
	modify(t << 1 , x , mid , fx , fy , a) ;
	modify(t << 1 | 1 , mid + 1 , y , fx , fy , a) ;

	tre[t].num = tre[t << 1].num + tre[t << 1 | 1].num ;
}

int find(int t , int x , int y , int fx , int fy) {
	if (y < fx || fy < x) return 0 ;
	if (fx <= x && y <= fy) return tre[t].num ;
	down(t , x , y) ;

	int mid = (x + y) >> 1 ,
		s1 = find(t << 1 , x , mid , fx , fy) ,
		s2 = find(t << 1 | 1 , mid + 1 , y , fx , fy) ;

	return s1 + s2 ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &q) ;
		scanf("%s%s" , s1 , s2) ;
		for (int i = n ; i ; --i) s1[i] = s1[i - 1] , s2[i] = s2[i - 1] ;

		///

		build(1 , 1 , n) ;
		for (int i = 1 ; i <= n ; ++i) modify(1 , 1 , n , i , i , s2[i] - '0') ;
		for (int i = 0 ; i < q ; ++i) scanf("%d %d" , &L[i] , &R[i]) ;

		bool ok = 1 ;
		for (int i = q - 1 ; i >= 0 ; --i) {
			int x = L[i] , y = R[i] , t = find(1 , 1 , n , x , y) , ti = (y - x) >> 1 , len = y - x + 1 ;

			if (t <= ti) modify(1 , 1 , n , x , y , 0) ;
			else if (len - t <= ti) modify(1 , 1 , n , x , y , 1) ;
			else if (t != len && t) ok = 0 ;
		}

		for (int i = 1 ; i <= n ; ++i) {
			int t = find(1 , 1 , n , i , i) ;
			if (t != s1[i] - '0') ok = 0 ;
		}

		if (ok) printf("YES\n") ;
		else printf("NO\n") ;
	}

	return 0 ;
}