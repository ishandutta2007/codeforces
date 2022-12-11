#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int t,n,m,kk;bool c[N],d[N];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(d+1,0,n*3);kk=0;
		scanf("%d%d",&n,&m);
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(!d[x]&&!d[y])d[x]=d[y]=c[i]=1,kk++;
			else c[i]=0;
		}
		if(kk>=n){puts("Matching");for(int i=1,j=1;j<=n;i++)if(c[i])printf("%d ",i),j++;}
		else {puts("IndSet");for(int i=1,j=1;j<=n;i++)if(!d[i])printf("%d ",i),j++;}
		puts("");
	}
	return 0;
}