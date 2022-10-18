#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;
		scanf("%d", &n);
		if(n < 1 + 6 + 10 + 14) {printf("NO\n");continue;}
		n -= (6 + 10 + 14);
		printf("YES\n");
		if(n == 6 || n == 10 || n == 14){
			n --;
			printf("%d 6 10 15\n", n);
		}
		else printf("%d 6 10 14\n", n);
	}
}