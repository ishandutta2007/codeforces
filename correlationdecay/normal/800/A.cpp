#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#define maxn 100009
using namespace std;
int n, a[maxn],b[maxn], p;
bool check(double M){
	double sum = 0;
	for(int i = 1;i <= n; i++){
		if(a[i] * M > b[i])
			sum += a[i] * M - b[i];
	}
	return M * p >= sum;
}
int main(){
	scanf("%d%d", &n, &p);
	for(int i = 1; i <=n; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	double L = 0, R = 1e15;
	for(int i = 0; i < 500; i++){
		double M = (L + R) / 2;
		if(check(M))
			L = M;
		else
			R = M;
	}
	if(L > 1e14){
		puts("-1");
	}
	else{
		printf("%.8f\n", L);
	}
	return 0;
}