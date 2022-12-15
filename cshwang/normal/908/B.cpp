#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

struct data {int x , y ;} ;

const int MAX_N = 50 + 10 ;

data st , ed ;
int n , m , len , way[10] ;
char s[MAX_N][MAX_N] , op[MAX_N << 1] ;

data trans(int x) {
	if (x == 0) return (data){-1 , 0} ;
	else if (x == 1) return (data){1 , 0} ;
	else if (x == 2) return (data){0 , -1} ;
	else return (data){0 , 1} ;
}

bool check() {
	data p = st ;

	for (int i = 0 ; i < len ; ++i) {
		data ad = trans(way[op[i] - '0']) ;

		p.x += ad.x ; p.y += ad.y ;
		if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) return 0 ;
		if (s[p.x][p.y] == '#') return 0 ;
		if (s[p.x][p.y] == 'E') return 1 ;
	}

	return 0 ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%s" , s[i]) ;
		for (int j = 0 ; j < m ; ++j)
			if (s[i][j] == 'S') st = (data){i , j} ;
			else if (s[i][j] == 'E') ed = (data){i , j} ;
	}
	scanf("%s" , op) ;
	len = strlen(op) ;

	///

	int ans = 0 ;
	for (int i = 0 ; i < 4 ; ++i)
		for (int j = 0 ; j < 4 ; ++j)
			for (int p = 0 ; p < 4 ; ++p)
				for (int q = 0 ; q < 4 ; ++q) {
					if (i == j || i == p || i == q || j == p || j == q || p == q) continue ;

					way[0] = i ; way[1] = j ; way[2] = p ; way[3] = q ;

					if (check()) ++ans ;
				}

	printf("%d\n" , ans) ;

	return 0 ;
}