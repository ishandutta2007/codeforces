#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,i,maxn=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		int t;
		scanf("%d",&t);
		printf("%d ",t+maxn);
		if(t>0) {
			maxn+=t;
		}
	}
	return 0;
}