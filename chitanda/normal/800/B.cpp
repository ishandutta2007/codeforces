#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int x[1010], y[1010];

double cross(double x, double y, double xx, double yy){
	return fabs(1. * x * yy - 1. * y * xx);
}

double dis(double x, double y, double xx, double yy){
	return sqrt(1. * (xx - x) * (xx - x) + 1. * (yy - y) * (yy - y));
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", x + i, y + i);
	}
	double ans = (2e9) + 10;
	for(int i = 0; i < n; ++i){
		int l = (i - 1 + n) % n, r = (i + 1) % n;
		double area = cross(x[i] - x[l], y[i] - y[l], x[r] - x[l], y[r] - y[l]);
		double L = dis(x[l], y[l], x[r], y[r]);
		double dis = area / L;
		ans = min(ans, dis / 2);
	}
	printf("%.10f\n", ans);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}