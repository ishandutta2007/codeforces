#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

int a[10];

int main(){
	long long i, j, k;
	long long cnt;
	long long ans;
	long long tmp;
	
	scanf("%lld", &t);
	
	while(t--){
		scanf("%lld", &n);
		cnt = 0;
		for(i=0;i<7;i++){
			scanf("%d", &a[i]);
			cnt += a[i];
		}
		
		tmp = n / cnt;
		
		if(tmp >= 2){
			ans = (tmp - 1) * 7ll;
			tmp = 1;
			n = cnt + n % cnt;
		}else{
			ans = 0;
		}
		
		long long minx = 100;
		
		for(i=0;i<21;i++){
			for(j=i;j<21;j++){
				cnt = 0;
				for(k=i;k<=j;k++){
					cnt += a[k % 7];
				}
				
				if(cnt == n){
					minx = min(minx, j - i + 1);
				}
			}
		}
		
		printf("%lld\n", ans + minx);
	}
	
	return 0;
}
/*
3
2
0 1 0 0 0 0 0
100000000
1 0 0 0 1 0 1
1
1 0 0 0 0 0 0
*/