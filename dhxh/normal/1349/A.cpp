#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
priority_queue <int> q[maxn];
int minx[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		int x = a[i];
		for(j=2;j*j<=a[i];j++){
			if(x % j == 0){
				int c = 0;
				while(x % j == 0){
					x /= j;
					c++;
				}
				q[j].push(-c);
			}
		}
		
		if(x > 1){
			q[x].push(-1);
		}
	}
	
	long long ans = 1;
	for(i=2;i<=2e5;i++){
		if(q[i].size() == n){
			q[i].pop();
			long long x = -q[i].top();
			while(x--){
				ans *= i;
			}
		}else if(q[i].size() == n - 1){
			long long x = -q[i].top();
			while(x--){
				ans *= i;
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}