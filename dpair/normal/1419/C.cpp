#include <bits/stdc++.h>
using namespace std;
int a[1005], n, x;
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		scanf("%d%d", &n, &x);int sig = 0;
		bool ck = 1, ckk = 0;
		for (register int i = 1;i <= n;i ++){
			scanf("%d", &a[i]);
			sig += a[i];
			if(a[i] == x) ckk = 1;
			else ck = 0;
		}
		if(ck) {
			printf("0\n");
			continue;
		}
		if(ckk){
			printf("1\n");
//			return 0;
			continue;
		}
		if(sig == x * n){
			printf("1\n");
			continue;
		}
		printf("2\n");
	}
}