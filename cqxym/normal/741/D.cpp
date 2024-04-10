#include<stdio.h>
#define R register int
#define I inline void
#define N 500001
#define INF -999999999
int f[N],dis[N],h[N],ct[4194304],Next[N],Last[N],dep[N],sz[N],ans[N];
I Max(int&x,const int y){
	if(x<y){
		x=y;
	}
}
I PreDFS(int x){
	sz[x]=1;
	for(R i=Last[x];i!=0;i=Next[i]){
		//printf("G%d %d\n",x,i);
		PreDFS(i);
		sz[x]+=sz[i];
		if(sz[i]>sz[h[x]]){
			h[x]=i;
		}
	}
}
I Clear(int x){
	ct[dis[x]]=INF;
	for(R i=Last[x];i!=0;i=Next[i]){
		Clear(i);
	}
}
I Calc(int x,int&ans){
	Max(ans,ct[dis[x]]+dep[x]);
	for(R i=0;i!=22;i++){
		Max(ans,ct[dis[x]^1<<i]+dep[x]);
	}
	for(R i=Last[x];i!=0;i=Next[i]){
		Calc(i,ans);
	}
}
I Update(int x){
	Max(ct[dis[x]],dep[x]);
	for(R i=Last[x];i!=0;i=Next[i]){
		Update(i);
	}
}
I ReDFS(int x){
	for(R i=Last[x];i!=0;i=Next[i]){
		if(i!=h[x]){
			ReDFS(i);
			Clear(i);
		}
	}
	if(h[x]!=0){
		ReDFS(h[x]);
		for(R i=Last[x];i!=0;i=Next[i]){
			if(i!=h[x]){
				Calc(i,ans[x]);
				Update(i);
			}
		}
	}
	Max(ct[dis[x]],dep[x]);
	Max(ans[x],ct[dis[x]]+dep[x]);
	for(R i=0;i!=22;i++){
		Max(ans[x],ct[dis[x]^1<<i]+dep[x]);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(R i=2;i<=n;i++){
		scanf("%d ",f+i);
		Next[i]=Last[f[i]];
		Last[f[i]]=i;
		dis[i]=dis[f[i]]^1<<getchar()-'a';
		dep[i]=dep[f[i]]+1;
	}
	for(R i=0;i!=4194304;i++){
		ct[i]=INF;
	}
	PreDFS(1);
	for(R i=1;i<=n;i++){
		ans[i]=INF;
	}
	ReDFS(1);
	for(R i=1;i<=n;i++){
		ans[i]-=dep[i]<<1;
	}
	for(R i=n;i!=0;i--){
		Max(ans[f[i]],ans[i]);
	}
	for(R i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}