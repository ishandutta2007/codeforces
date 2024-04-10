#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e3 + 10 ;

int w , d ;
double f[MAX_N][MAX_N] ;

double pos(int x , int y) {
	if (x <= 0 || y <= 0) return 0 ;

	return x * 1.0 / y ;
}

double dp(int w , int d) {
	if (w < 0 || d < 0) return 0 ;
	if (f[w][d] > 0) return f[w][d] ;

	f[w][d] += pos(w , w + d) ;

	int sum = w + d ;
	double p1 = pos(d , sum) * pos(d - 1 , sum - 1) * pos(w ,sum - 2) ,
		   p2 = pos(d , sum) * pos(d - 1 , sum - 1) * pos(d - 2 , sum - 2) ;
	f[w][d] += p1 * dp(w - 1 , d - 2) ;
	f[w][d] += p2 * dp(w , d - 3) ;

	return f[w][d] ;
}

int main() {
	scanf("%d %d" , &w , &d) ;
	dp(w , d) ;
	printf("%0.10lf\n" , f[w][d]) ;

	return 0 ;
}