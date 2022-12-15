#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 500 + 10 , MAX_K = 10 + 5 , INF = 0x3f3f3f3f ;

struct Link {
	int x , y , val ;
	Link *next ;
}list[MAX_N * MAX_N * 4] ;

Link *head[MAX_N][MAX_N] ;
int n , m , k , cur , f[MAX_N][MAX_N][MAX_K] ;

void ins(int x , int y , int nx , int ny , int d) {
	list[cur].x = nx ;
	list[cur].y = ny ;
	list[cur].val = d ;
	list[cur].next = head[x][y] ;
	head[x][y] = &list[cur++] ;
}

int main() {
	scanf("%d %d %d" , &n , &m , &k) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j < m ; ++j) {
			int x ; scanf("%d" , &x) ;
			ins(i , j , i , j + 1 , x) ;
			ins(i , j + 1 , i , j , x) ;
		}
	for (int i = 1 ; i < n ; ++i)
		for (int j = 1 ; j <= m ; ++j) {
			int x ; scanf("%d" , &x) ;
			ins(i , j , i + 1 , j , x) ;
			ins(i + 1 , j , i , j , x) ;
		}

	///

	if (k & 1) {
		for (int i = 1 ; i <= n ; ++i , printf("\n"))
			for (int j = 1 ; j <= m ; ++j) printf("-1 ") ;
		return 0 ;
	}

	k >>= 1 ;
	for (int p = 1 ; p <= k ; ++p)
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= m ; ++j) {
				f[i][j][p] = INF ;

				for (Link *h = head[i][j] ; h ; h = h->next) {
					f[i][j][p] = std::min(f[h->x][h->y][p - 1] + h->val , f[i][j][p]) ;
				}
			}

	for (int i = 1 ; i <= n ; ++i , printf("\n"))
		for (int j = 1 ; j <= m ; ++j)
			printf("%d " , (f[i][j][k] << 1)) ;

	return 0 ;
}