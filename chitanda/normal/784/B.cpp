#include<bits/stdc++.h>
using namespace std;

const int a[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};

int main(){
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("1\n");
		return 0;
	}
	int ans = 0;
	while(n){
		int x = n % 16;
		ans += a[x];
		n /= 16;
	}
	printf("%d\n", ans);
	return 0;
}