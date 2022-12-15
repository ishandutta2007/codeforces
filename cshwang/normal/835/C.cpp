#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10 , MAX_X = 100 + 10 ;

int n , q , c , star[15][MAX_X][MAX_X] ;

int main() {
	scanf("%d %d %d" , &n , &q , &c) ; ++c ;
	for (int i = 0 ; i < n ; ++i) {
		int x , y , s ;
		scanf("%d %d %d" , &x , &y , &s) ;

		for (int j = 0 ; j < c ; ++j) star[j][x][y] += (s + j) % c ;
	}

	///

	for (int i = 0 ; i < c ; ++i)
		for (int x = 1 ; x <= 100 ; ++x)
			for (int y = 1 ; y <= 100 ; ++y)
				star[i][x][y] += star[i][x - 1][y] + star[i][x][y - 1] - star[i][x - 1][y - 1] ;

	///
	
	for (int i = 0 ; i < q ; ++i) {
		int t , x1 , y1 , x2 , y2 ;
		scanf("%d %d %d %d %d" , &t , &x1 , &y1 , &x2 , &y2) ;

		t %= c ;
		int res = star[t][x2][y2] - star[t][x1 - 1][y2] - star[t][x2][y1 - 1] + star[t][x1 - 1][y1 - 1] ;
		printf("%d\n" , res) ;
	}

	return 0 ;
}