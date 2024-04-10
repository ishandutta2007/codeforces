#include <bits/stdc++.h>

#define db double

const int T = 50 ;

int x1 , y1 , x2 , y2 , x3 , y3 ;

inline db squ(db x) {return x * x ;}

inline db euclid(db x1 , db y1 , db x2 , db y2) {
	return sqrt(squ(x1 - x2) + squ(y1 - y2)) ;
}

inline db calc_dis(db x1 , db y1 , db x2 , db y2 , db x3 , db y3 , db x , db y) {
	return euclid(x1 , y1 , x , y) + euclid(x2 , y2 , x , y) + euclid(x3 , y3 , x , y) ;
}

inline db find_dis_y(db x1 , db y1 , db x2 , db y2 , db x3 , db y3 , db x) {
	db yl = -1e4 , yr = 1e4 ;
	for (int i = 0 ; i < T ; ++i) {
		db len = (yr - yl) / 3 , yp = yl + len , yq = yr - len ;
		if (calc_dis(x1 , y1 , x2 , y2 , x3 , y3 , x , yl) > calc_dis(x1 , y1 , x2 , y2 , x3 , y3 , x , yr)) yl = yp ;
		else yr = yq ;
	}
	return calc_dis(x1 , y1 , x2 , y2 , x3 , y3 , x , yl) ;
}

inline db find_dis(db x1 , db y1 , db x2 , db y2 , db x3 , db y3) {
	db xl = -1e4 , xr = 1e4 ;
	for (int i = 0 ; i < T ; ++i) {
		db len = (xr - xl) / 3 , xp = xl + len , xq = xr - len ;
		if (find_dis_y(x1 , y1 , x2 , y2 , x3 , y3 , xp) > find_dis_y(x1 , y1 , x2 , y2 , x3 , y3 , xq)) xl = xp ;
		else xr = xq ;
	}
	db res = find_dis_y(x1 , y1 , x2 , y2 , x3 , y3 , xl) ;
	return res ;
}

inline db calc(db x , db y) {
	return std::max({
		find_dis(x1 , y1 , x2 , y2 , x , y) ,
		find_dis(x1 , y1 , x3 , y3 , x , y) ,
		find_dis(x2 , y2 , x3 , y3 , x , y)
	}) ;
}

inline db find_y(db x) {
	db yl = -1e4 , yr = 1e4 ;
	for (int i = 0 ; i < T ; ++i) {
		db len = (yr - yl) / 3 , yp = yl + len , yq = yr - len ;
		if (calc(x , yp) > calc(x , yq)) yl = yp ;
		else yr = yq ;
	}
	return calc(x , yl) ;
}

int main() {
	scanf("%d %d %d %d %d %d" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3) ;

	db xl = -1e4 , xr = 1e4 ;
	for (int i = 0 ; i < T ; ++i) {
		db len = (xr - xl) / 3 , xp = xl + len , xq = xr - len ;
		if (find_y(xp) > find_y(xq)) xl = xp ;
		else xr = xq ;
	}
	db ans = find_y(xl) ;
	printf("%0.8lf\n" , ans) ;

	return 0 ;
}