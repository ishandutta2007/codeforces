#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n, r, v, s, t;

double f(double x){
	return 1.0*r * (x + 2 * sin(x / 2));
}

double f2(double x){
	return 1.0*r * (x - 2 * sin(x / 2));
}

double solve(double x){
	double bottom = 0, top = 1e9;
	for(int i = 0;i < 100;i++){
		double mid = (top + bottom) / 2;
		if(f(mid) < x)bottom = mid;
		else top = mid;
	}
	double res = top * r / v;
	bottom = 0, top = 1e9;
	for(int i = 0;i < 100;i++){
		double mid = (top + bottom) / 2;
		if(f2(mid) < x)bottom = mid;
		else top = mid;
	}
	res = min(res, top * r / v);
	return res;
}


int main(){
	scanf("%d%d%d", &n, &r, &v);
	for(int i = 0;i < n;i++){
		scanf("%d%d", &s, &t);
		printf("%.10lf\n", solve(t - s));
	}
	return 0;
}