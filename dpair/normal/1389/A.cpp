#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int l, r;
		scanf("%d%d", &l, &r);
		if((l << 1) <= r){
			printf("%d %d\n", l, (l << 1));
		}
		else{
			printf("-1 -1\n");
		}
	}
}