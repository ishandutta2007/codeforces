#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

double eps = 1e-7;

int n;

double px[100005];
double v[100005];

double ans = 10000000000007;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool check(double x){
	int i, j;
	double maxn = -1000000007;
	double minn = 1000000007;
	double tmp;
	int num;
	
	for(i=1;i<=n;i++){
		maxn = max(maxn, px[i] - v[i] * x);
		minn = min(minn, px[i] + v[i] * x);
	}
	
	ans = min(ans, maxn);
	
	return maxn > minn;
}

int main(){
	int i, j;
	int x;
	double l = 0, r = 1000000007;
	double mid;
	
	n = read();
	
	for(i=1;i<=n;i++){
		px[i] = read();
	}
	
	for(i=1;i<=n;i++){
		v[i] = read();
	}
	
	while(r - l >= eps){
		mid = (l + r) / 2;
		
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	
	printf("%.12f\n", (l + r) / 2);
	
	return 0;
}