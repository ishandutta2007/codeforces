#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 500 + 10 , MAX_T = 25e4 + 10 , dx[4] = {1 , -1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1} ;

struct data {int x , y ;}que[MAX_T] ;

int r , c , tot ;
char s[MAX_N][MAX_N] ;
bool ap[MAX_N][MAX_N] ;

void dfs(int x , int y) {
	if (s[x][y] != 'S') return ;

	ap[x][y] = 1 ;
	que[tot++] = (data){x , y} ;
	for (int i = 0 ; i < 4 ; ++i) {
		int nx = x + dx[i] , ny = y + dy[i] ;

		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue ;
		if (ap[nx][ny]) continue ;

		dfs(nx , ny) ;
	}
}

int main() {
	scanf("%d %d" , &r , &c) ;
	for (int i = 0 ; i < r ; ++i)
		scanf("%s" , s[i]) ;

	///

	bool ok = 1 ;
	for (int i = 0 ; i < r && ok ; ++i)
		for (int j = 0 ; j < c && ok ; ++j) {
			if (ap[i][j]) continue ;
			if (s[i][j] != 'S') continue ;

			tot = 0 ; dfs(i , j) ;

			for (int k = 0 ; k < tot ; ++k) {
				data p = que[k] ;
				for (int x = 0 ; x < 4 ; ++x) {
					int nx = p.x + dx[x] , ny = p.y + dy[x] ;

					if (nx < 0 || ny < 0 || nx > r || ny > c) continue ;
					if (s[nx][ny] == 'W') ok = 0 ;
					else if (s[nx][ny] == '.') s[nx][ny] = 'D' ;
				}
			}
		}

	if (ok) {
		printf("Yes\n") ;
		for (int i = 0 ; i < r ; ++i , printf("\n"))
			for (int j = 0 ; j < c ; ++j) printf("%c" , s[i][j]) ;
	}
	else printf("No\n") ;

	return 0 ;
}