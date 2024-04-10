#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring> 
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n;

double a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

double mabs(double x){
	return x < 0 ? -x : x;
}

double check(double x){
	int i;
	double maxx = a[1] - x, minx = a[1] - x;
	double ret = mabs(a[1] - x);
	
	for(i=2;i<=n;i++){
		maxx = max(maxx + a[i] - x, a[i] - x);
		minx = min(minx + a[i] - x, a[i] - x);
		ret = max(ret, mabs(maxx));
		ret = max(ret, mabs(minx));
	}
	
	return ret;
}

int main(){
	int i, j;
	double l, r, midl, midr;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	l = -1e4;
	r = 1e4;
	
	for(i=1;i<=100;i++){
		midl = (2 * l + r) / 3;
		midr = (l + 2 * r) / 3;
		
		if(check(midl) > check(midr)){
			l = midl;
		}else{
			r = midr;
		}
	}
	
	printf("%.12lf", check(l));
	
	return 0;
}