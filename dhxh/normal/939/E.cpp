#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 5e5 + 5;

int n, m, t;

double a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	double ans = 0;
	double sum = 0, cnt = 0;
	int x, y;
	int l = 1, r = 1;
	
	n = read();
	
	x = read();
	a[1] = read();
	
	sum = a[1];
	cnt = 1;
	
	for(i=2;i<=n;i++){
		x = read();
		if(x == 1){
			a[++r] = read();
			while(l < r and (sum + a[r]) / (double)(l + 1) > (sum + a[l + 1] + a[r]) / (double)(l + 2)){
				l++;
				sum += a[l];
			}
			ans = max(ans, a[r] - ((sum + a[r]) / (double)(l + 1)));
		}else{
			printf("%.12f\n", ans);
		}
	}
	
	
	return 0;
}