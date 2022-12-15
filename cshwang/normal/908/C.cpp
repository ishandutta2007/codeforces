#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define eps 1e-6
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 1e3 + 10 ;

int n , r , maxx , x[MAX_N] ;
double y[MAX_N] , my[MAX_N] ;

int squ(int x) {return x * x ;}

double find(int nx , int x , int y) {
	x = std::max(x , 0) ;
	y = std::min(y , maxx) ;

	double ans = -1 ;

	for (int i = x ; i <= y ; ++i) {
		double tmp ;

		if (!my[i]) tmp = r ;
		else tmp = my[i] + sqrt(squ(r << 1) - squ(nx - i)) ;
		ans = std::max(tmp , ans) ;
	}

	return ans ;
}

int main() {
	scanf("%d %d" , &n , &r) ;
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d" , &x[i]) ;
		 maxx = std::max(maxx , x[i]) ;
	}

	///

	for (int i = 0 ; i < n ; ++i) {
		double tmp = find(x[i] , x[i] - (r << 1) , x[i] + (r << 1)) ;

		y[i] = tmp ;
		my[x[i]] = std::max(my[x[i]] , y[i]) ;
	}

	for (int i = 0 ; i < n ; ++i) printf("%0.8lf\n" , y[i]) ;

	return 0 ;
}