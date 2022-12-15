#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

ll R , xx1 , yy1 , xx2 , yy2 ;

double dis(double xx1 , double yy1 , double xx2 , double yy2) {
	double d1 = xx1 - xx2 , d2 = yy1 - yy2 ;

	return d1 * d1 + d2 * d2 ;
}

int main() {
	scanf("%lld %lld %lld %lld %lld" , &R , &xx1 , &yy1 , &xx2 , &yy2) ;

	if (dis(xx1 , yy1 , xx2 , yy2) >= R * R) {
		printf("%lld %lld %lld\n" , xx1 , yy1 , R) ;
	}
	else if (xx1 == xx2) {
		double r , x = xx1 , y ;

		if (yy1 > yy2) {
			r = (R + yy1 - yy2) / 2.0 ;
			y = yy2 + r ;
		}
		else {
			r = (R + yy2 - yy1) / 2.0 ;
			y = yy2 - r ;
		}

		printf("%0.8lf %0.8lf %0.8lf\n" , x , y , r) ;
	}
	else {
		double k = (yy1 - yy2) * 1.0 / (xx1 - xx2) , b = yy1 - k * xx1 ;
		double A = k * k + 1 , B = 2 * k * b - 2 * xx1 - 2 * k * yy1 , C = xx1 * xx1 + yy1 * yy1 + b * b - 2 * yy1 * b - R * R ;

		double delt = sqrt(B * B - 4 * A * C) ;
		double X1 = (-B + delt) / (2 * A) , X2 = (-B - delt) / (2 * A) , Y1 = k * X1 + b , Y2 = k * X2 + b ;
		double R1 = dis(X1 , Y1 , xx2 , yy2) , R2 = dis(X2 , Y2 , xx2 , yy2) ;

		if (R1 > R2) {
			X1 = (X1 + xx2) / 2 ; Y1 = (Y1 + yy2) / 2 ; R1 = sqrt(R1) / 2 ;

			printf("%0.8lf %0.8lf %0.8lf\n" , X1 , Y1 , R1) ;
		}
		else {
			X2 = (X2 + xx2) / 2 ; Y2 = (Y2 + yy2) / 2 ; R2 = sqrt(R2) / 2 ;

			printf("%0.8lf %0.8lf %0.8lf\n" , X2 , Y2 , R2) ;
		}
	}

	return 0 ;
}