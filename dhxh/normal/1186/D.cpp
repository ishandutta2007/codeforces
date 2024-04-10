#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

double a[maxn];
int b[maxn];
int c[maxn];

int cnta = 0;
int cntb = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long sum = 0;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%lf", &a[i]);
		b[i] = floor(a[i]);
		sum += b[i];
		c[i] = ceil(a[i]) - floor(a[i]);
	}
	
	if(sum > 0){
		for(i=1;i<=n;i++){
			if(sum > 0 and c[i] < 0){
				sum += c[i];
				b[i] = ceil(a[i]);
			}
		}
	}else if(sum < 0){
		for(i=1;i<=n;i++){
			if(sum < 0 and c[i] > 0){
				sum += c[i];
				b[i] = ceil(a[i]);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		printf("%d\n", b[i]);
	}
	
	return 0;
}