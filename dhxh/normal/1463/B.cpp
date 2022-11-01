#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int a[55];

int lowbit(int x){
	return x & -x;
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=1;i<=n;i++) scanf("%d", &a[i]);
		
		for(i=1;i<=n;i++){
			while(a[i] != lowbit(a[i])){
				a[i] -= lowbit(a[i]);
			}
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	
	return 0;
}