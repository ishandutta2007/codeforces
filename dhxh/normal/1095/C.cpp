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

int n, m, t, k;

int a[105];

int main(){
	int i, j, l;
	int x, y;
	int cnt = 0;
	scanf("%d%d", &n, &k);
	
	x = n;
	
	i = 0;
	while(x){
		a[i++] = (x & 1);
		cnt += a[i - 1];
		x >>= 1;
	}
	
	if(cnt > k){
		printf("NO\n");
		return 0;
	}
	
	if(cnt == k){
		printf("YES\n");
		for(j=0;j<i;j++){
			if(a[j
			]){
				printf("%d ", (1 << j));
			}
		}
		printf("\n");
		return 0;
	}
	
	for(i--;i>0;i--){
		if(cnt < k){
			if(cnt + a[i] < k){
				cnt += a[i];
				a[i - 1] += a[i] * 2;
				
			}else{
				a[i - 1] += (k - cnt) * 2;
				a[i] -= k - cnt;
				cnt = k;
				break;
			}
		}
	}
	
	if(cnt < k){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	for(l=0;l<=i;l++){
		for(j=1;j<=a[l];j++){
			printf("%d ", (1 << l));
		}
	}
	printf("\n");
	return 0;
	
	return 0;
}