#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 3e5 + 5;

long long n, m;

long long c[maxn];
long long d[maxn];

long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long sqr(long long x){
	return x * x;
}

int dfs(int l, int r){
	int mid = (l + r) / 2;
	int i, j;
	
	if(l == r){
		ans = max(ans, m - c[l]);
	}else{
		dfs(l, mid);
		dfs(mid + 1, r);
		vector <long long> a[2];
		vector <long long> b[2];
		
		a[0].resize(mid - l + 1);
		a[1].resize(mid - l + 1);
		b[0].resize(r - mid);
		b[1].resize(r - mid);
		
		a[0][0] = m - c[mid];
		a[1][0] = d[mid + 1] - d[mid];
		for(i=1;i<mid-l+1;i++){
			a[0][i] = a[0][i - 1] + m - c[mid - i];
			a[1][i] = max(a[1][i - 1], d[mid - i + 1] - d[mid - i]);
		}
		b[0][0] = m - c[mid + 1];
		b[1][0] = d[mid + 1] - d[mid];
		for(i=1;i<r-mid;i++){
			b[0][i] = b[0][i - 1] + m - c[mid + i + 1];
			b[1][i] = max(b[1][i - 1], d[mid + i + 1] - d[mid + i]);
		}
		
		i = 0, j = 0;
		long long maxa = a[0][0], maxb = b[0][0];
		
		while(i < mid - l + 1){
			 maxa = max(maxa, a[0][i]);
			 
			 while(j + 1 < r - mid and b[1][j + 1] <= a[1][i]){
			 	j++;
			 	maxb = max(maxb, b[0][j]);
			 }
			 
			 ans = max(ans, maxa + maxb - sqr(a[1][i]));
			 i++;
		}
		
		i = 0, j = 0;
		maxa = a[0][0], maxb = b[0][0];
		
		while(j < r - mid){
			 maxb = max(maxb, b[0][j]);
			 
			 while(i + 1 < mid - l + 1 and a[1][i + 1] <= b[1][j]){
			 	i++;
			 	maxa = max(maxa, a[0][i]);
			 }
			 
			 ans = max(ans, maxa + maxb - sqr(b[1][j]));
			 j++;
		}
	}
	
	
	return 0;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		d[i] = read();
		c[i] = read();
	}
	
	dfs(1, n);
	
	printf("%lld\n", ans);
	
	return 0;
}