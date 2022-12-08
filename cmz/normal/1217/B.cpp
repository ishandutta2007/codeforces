#include<bits/stdc++.h>
using namespace std;
const int inf=(1<<30);
const int maxn=110;
int n,k,maxx,maxk;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		maxx=maxk=-inf;
		scanf("%d%d",&n,&k);
		for (int i=1,x,y;i<=n;++i){
			scanf("%d%d",&x,&y);
			maxx=max(maxx,x-y);
			maxk=max(maxk,x);
		}
		if (k<=0){
			puts("0");
			continue;
		}
		if (k<=maxk){
			puts("1"); 
			continue;
		}
		if (maxx<=0){
			puts("-1");
			continue;
		}
		printf("%d\n",(k-maxk+maxx-1)/maxx+1);
	}
	return 0;
}