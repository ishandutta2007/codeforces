#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#include<cmath>
#include<cstdio>

using namespace std;


double x, y, xx[108000], yy[108000];
int n;
double solve(double x1, double y1, double x2, double y2){
	double a = x1*x1 + y1*y1;
	double b = x2*x2 + y2*y2;
	double c = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if(a > b + c || b > a + c)return min(sqrt(a), sqrt(b));
	return abs(x1 * y2 - x2 * y1) /sqrt(c);
}

int main(){
	cin >> n >> x >> y;
	double inside = 1e10, outside = 0;
	for(int i = 0;i < n;i++){
		cin >> xx[i] >> yy[i];
		xx[i] -= x;
		yy[i] -= y;
		double dist = sqrt(xx[i]*xx[i] + yy[i]*yy[i]);
		outside = max(outside, dist);
	}
	for(int i = 0;i < n;i++){
		double dist = solve(xx[i], yy[i], xx[(i+1)%n], yy[(i+1)%n]);
		inside = min(inside, dist);
	}
	printf("%.10lf\n",(outside * outside - inside * inside) * 3.14159265358979);
	return 0;
}