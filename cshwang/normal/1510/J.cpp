#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e5 + 10 ;

struct data {int x , y ;} ;

std::vector<data> a ;

int n , m ;
char s[MAX_N] , tmp[MAX_N] ;

void pick() {
	a.clear() ;
	s[n + 1] = '_' ;

	int c = 0 ;
	for (int i = 1 ; i <= n + 1 ; ++i)
		if (s[i] == '#') ++c ;
		else {
			if (c) a.push_back((data){i - c , i - 1}) ;
			c = 0 ;
		}
	m = a.size() ;
}

void print() {
	printf("%d\n" , m) ;
	for (int i = 0 ; i < m ; ++i) printf("%d " , a[i].y - a[i].x + 1) ;

	printf("\n") ;
}

bool empty(int x , int y) {
	for (int i = x ; i <= y ; ++i) if (tmp[i] == '#') return 0 ;
	return 1 ;
}

inline void fill(int x , int y) {
	for (int i = x + 1 ; i <= y ; ++i) tmp[i] = '#' ;
}

bool work(int x , int y , bool ty) {
	if (x > y) return 1 ;
	if (x == y) return 0 ;

	int len = y - x + 1 , tw = len >> 1 , tr = 0 ;
	if (len & 1) {--tw ; ++tr ;}
	if (!ty && tr) return 0 ;

	for (int i = 0 ; i < tw ; ++i , x += 2) fill(x , x + 1) ;
	if (tr) fill(x , x + 2) ;

	return 1 ;
}

bool check(int x) {
	for (int i = 0 ; i <= n ; ++i) tmp[i] = s[i] ;

	if (!empty(n - x + 1 , n)) return 0 ;
	if (!work(a[m - 1].y + 1 , n - x , x > 1)) return 0 ;

	for (int i = m - 1 ; i >= 0 ; --i) {
		data *p = &a[i] ;
		int pre = i ? a[i - 1].y + 1 : 0 ;

		for (int j = 1 ; j <= x ; ++j) {
			if (p->x - j < 1 || tmp[p->x - j] == '#') return 0 ;
			tmp[p->x - j] = '#' ;
		}
		if (p->x - x - 1 >= 0 && tmp[p->x - x - 1] == '#') return 0 ;

		if (!work(pre , p->x - x - 2 , x > 1)) return 0 ;
	}

	return 1 ;
}

int main() {
	scanf("%s" , s) ; n = strlen(s) ;
	for (int i = n ; i ; --i) s[i] = s[i - 1] ;
	s[0] = '_' ;

	///

	pick() ;
	if (!m) {printf("0\n") ; return 0 ;}
	if (a[m - 1].y == n) {
		if (a[0].x == 1) print() ;
		else printf("-1\n") ;
		return 0 ;
	}

	bool ok = 0 ;
	for (int i = 1 ; i <= 3 ; ++i)
		if (check(i)) {ok = 1 ; break ;}

	if (ok) {
		for (int i = 1 ; i <= n ; ++i) s[i] = tmp[i] ;
		pick() ; print() ;
	}
	else printf("-1\n") ;

	return 0 ;
}