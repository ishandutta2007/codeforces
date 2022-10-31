#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

double r, xa, xb, ya, yb;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

double sqr(double x){
	return x * x;
}

double distsqr(double x, double y, double a, double b){
	return sqr(x - a) + sqr(y - b);
}

double dist(double x, double y, double a, double b){
	return sqrt(sqr(x - a) + sqr(y - b));
}

int main(){
	int i, j;
	
	cin >> r >> xa >> ya >> xb >> yb;
	
	if(r * r <= distsqr(xa, ya, xb, yb)){
		printf("%.12f %.12f %.12f\n", xa, ya, r);
	}else if(xa == xb){
		double f = (ya > yb ? 1 : -1);
		printf("%.12f %.12f %.12f\n", xa, ya +  f * (r - (r + dist(xa, ya, xb, yb)) / 2.0), (r + dist(xa, ya, xb, yb)) / 2.0);
	}else{
		double ll = 0, rr = r;
		double f = (xa > xb ? 1 : -1);
		double x = xa, y = ya;
		double mid;
		
		for(i=1;i<=100;i++){
			mid = (ll + rr) / 2.0;
			if(dist(xb, yb, xa + f * mid, ya + (ya - yb) / (xa - xb) * f * mid) <= r - dist(xa, ya, xa + f * mid, ya + (ya - yb) / (xa - xb) * f * mid)){
				ll = mid;
			}else{
				rr = mid;
			}
		}
		mid = (ll + rr) / 2.0;
		x = xa + f * mid;
		y = ya + (ya - yb) / (xa - xb) * f * mid;
		printf("%.12f %.12f %.12f\n", x, y, dist(x, y, xb, yb));
	}
	
	return 0;
}