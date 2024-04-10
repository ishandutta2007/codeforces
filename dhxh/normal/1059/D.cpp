#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath> 
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

double eps = 1e-7;

const int maxn = 1e5 + 5;

int n;

double px[maxn];
double py[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

double sqr(double x){
	return x * x;
}

double check(double x){
	double ret = 0;
	int i, j;
	
	for(i=1;i<=n;i++){
		ret = max(ret, (sqr(px[i] - x) + sqr(py[i])) / (2.0 * fabs(py[i])));
	}
	
	return ret;
}

int main(){
	int i, j;
	double l = -1e7, r = 1e7;
	int t = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		px[i] = read();
		py[i] = read();
		if(i == 1){
			t = py[i] / fabs(py[i]);
		}else{
			if(py[i] / fabs(py[i]) != t){
				printf("-1\n");
				return 0;
			}
		}
	}
	
	while(r - l >= eps){
		double mida = (2 * l + r) / 3.0;
		double midb = (2 * r + l) / 3.0;
		
		if(check(mida) < check(midb)){
			r = midb;
		}else{
			l = mida;
		}
	}
	
	printf("%.12f\n", check(l));
	
	return 0;
}