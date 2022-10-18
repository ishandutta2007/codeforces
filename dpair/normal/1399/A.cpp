#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int a[110]; 
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;
		scanf("%d", &n);
		for (register int i = 1;i <= n;i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ck = 0;
		for (register int i = 2;i <= n;i ++){
			if(a[i] - a[i - 1] >= 2) {
				printf("NO\n");ck = 1;
				break;
			}
		}
		if(!ck) printf("YES\n");
	}
}