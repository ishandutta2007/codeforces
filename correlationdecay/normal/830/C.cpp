#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <iostream>
#define maxn 109
using namespace std;
int n, tot;
int a[maxn];
long long k;
long long X[20000009];
long long d = 1;

long long check(long long x){
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		sum += ((a[i] + x - 1) / x) * x - a[i];
	}
	return sum;
}

void solve(long long L, long long R){
	if(check(R) <= k){
		d = R;
		return;
	}
	if(check(L) > k){
		return;
	}
	while(L < R){
		long long M = (L + R + 1) >> 1;
		if(check(M) <= k){
			L = M;
			d = max(d, L);
		}
		else
			R = M - 1;
	}
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; ){
			int r = a[i] / (a[i] / j);
			X[tot++] = j;
			X[tot++] = r;
			//printf("%d %d %d\n", a[i], j, r);
			j = r + 1;	
		}
	}
	X[tot++] = 1e15;
	sort(X, X + tot);
	tot = unique(X, X + tot) - X;
	
	for(int i = tot - 1; i > 0; i--){
		solve(X[i - 1], X[i]);
		if(d != 1)
			break;
	}
	cout << d << endl;
	return 0;
}