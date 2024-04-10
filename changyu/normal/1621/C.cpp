#include<bits/stdc++.h>
const int N=1e5+3;
int n,p[N];
signed main(){
	int x,y;
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)p[i]=0;
	for(int i=1;i<=n;i++)if(!p[i]){
		x=0;
		while(1){
			printf("? %d\n",i),fflush(stdout),scanf("%d",&y);
			p[x]=y,x=y;
			if(p[x])break;
		}
	}
	printf("!");for(int i=1;i<=n;i++)printf(" %d",p[i]);puts(""),fflush(stdout);
	}return 0;
}