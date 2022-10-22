#include<bits/stdc++.h>

const int N = 110;

int n, k;
int a[N], b[N];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; ++ i){
		scanf("%d", &b[i]);
	}
	if (k >= 2){
		return printf("Yes\n"), 0;
	}
	for (int i = 0; i < n; ++ i){
		if (!a[i]){
			a[i] = b[0];
		}
	}
	for (int i = 0; i < n - 1; ++ i){
		if (a[i] > a[i + 1]){
			return printf("Yes\n"), 0;
		}
	}
	return printf("No\n"), 0;
}