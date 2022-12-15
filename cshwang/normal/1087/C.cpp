#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 5 , MAX_P = 1e6 + 10 ;

struct data {
	int x , y ;
}pt[MAX_N] , ans[MAX_P] ;

int n , m ;

bool cmp(data a , data b) {return a.x < b.x ;}

void link(int x1 , int y1 , int x2 , int y2) {
	for (int i = x1 ; i <= x2 ; ++i) {   // (i , y1)
		if ((i == x1) || (i == x2 && y1 == y2)) continue ;
		ans[m++] = (data){i , y1} ;
	}

	int L , R ;
	if (y1 > y2) L = y2 , R = y1 ;
	else L = y1 , R = y2 ;

	for (int i = L ; i <= R ; ++i) {  // (x2 , i)
		if ((x2 == x1 && i == y1) || (i == y2) || (i == y1)) continue ;
		ans[m++] = (data){x2 , i} ;
	}
}

int main() {
	n = 3 ;
	for (int i = 0 ; i < n ; ++i) scanf("%d %d" , &pt[i].x , &pt[i].y) ;
	std::sort(pt + 0 , pt + n , cmp) ;

	///

	link(pt[0].x , pt[0].y , pt[1].x , pt[1].y) ;

	int L = std::min(pt[1].y , pt[0].y) , R = std::max(pt[1].y , pt[0].y) ;

	if (pt[2].y < L) link(pt[1].x , L , pt[2].x , pt[2].y) ;
	else if (pt[2].y > R) link(pt[1].x , R , pt[2].x , pt[2].y) ;
	else link(pt[1].x , pt[2].y , pt[2].x , pt[2].y) ;

	for (int i = 0 ; i < n ; ++i) {
		bool sm = 0 ;
		for (int j = 0 ; j < m ; ++j) if (pt[i].x == ans[j].x && pt[i].y == ans[j].y) sm = 1 ;
		if (!sm) ans[m++] = pt[i] ;
	}

	printf("%d\n" , m) ;
	for (int i = 0 ; i < m ; ++i) printf("%d %d\n" , ans[i].x , ans[i].y) ;

	return 0 ;
}