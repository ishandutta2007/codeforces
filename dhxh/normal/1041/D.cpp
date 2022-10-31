#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

pair <long long, long long> a[maxn];
long long sum[maxn];

long long ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long check(long long x){
	int l = 1, r = n;
	
	if(x >= a[n].second){
		return sum[n];
	}
	
	while(l < r){
		int mid = (l + r) / 2;
		
		if(a[mid].second < x){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	return sum[l - 1] + max(0ll, x - a[l].first);
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i].first = read();
		a[i].second = read();
		sum[i] = sum[i - 1] + a[i].second - a[i].first;
	}
	
	for(i=1;i<=n;i++){
		long long l = m, r = m + sum[n] - sum[i - 1];
		
		while(l < r){
			long long mid = (l + r) / 2;
			
			if(check(a[i].first + mid) - sum[i - 1] + m > mid){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		
		ans = max(ans, l);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}