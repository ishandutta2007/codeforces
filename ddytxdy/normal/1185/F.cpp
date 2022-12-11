#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,a[N],num[600],g[600],ansf=-1,ansg,id1,id2,id[600];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d",&x);
		for(int j=1;j<=x;j++)scanf("%d",&y),a[i]|=1<<(y-1);
	}
	for(int i=1;i<512;i++)for(int j=1;j<=n;j++)if((i|a[j])==i)num[i]++;
	for(int i=1;i<=m;i++){
		int z=0,c,x,y;
		scanf("%d%d",&c,&x);
		for(int j=1;j<=x;j++)scanf("%d",&y),z|=1<<(y-1);
		for(int j=1;j<512;j++){
			if((z|j)!=j||num[j]<ansf)continue;
			int w=j^z;if(!id[w])continue;
			if(num[j]>ansf||num[j]==ansf&&ansg>g[w]+c)
				ansf=num[j],ansg=g[w]+c,id1=id[w],id2=i;
		}
		for(int j=z;j;j=(j-1)&z)if(!id[j]||g[j]>c)id[j]=i,g[j]=c;
		if(!id[0]||g[0]>c)id[0]=i,g[0]=c;
	}
	printf("%d %d\n",id1,id2);
	return 0;
}