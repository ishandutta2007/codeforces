#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;scanf("%d", &n);
		bool ck[2] = {0, 0};
		for (register int i = 1;i <= n;i ++){
			int x;scanf("%1d", &x);
			if((x & 1) == (i & 1)){
				ck[x & 1] = 1;
			}
		}
		if(ck[n & 1]){
			if(n & 1) printf("1\n");
			else printf("2\n");
		}
		else{
			if(n & 1) printf("2\n");
			else printf("1\n");
		}
	}
}