#include<stdio.h>
#define R register int
#define L long long
#define I inline void
#define N 200001
#define M 400000
int Last[N],End[M],Next[M],sz[N],n,ct;
I Link(int&x,int&y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
L f[N];
I PreDFS(int x,int F){
	sz[x]=1;
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			PreDFS(End[i],x);
			f[x]+=f[End[i]];
			sz[x]+=sz[End[i]];
		}
	}
	f[x]+=sz[x];
}
I ReDFS(int x,int F,L&ans){
	f[x]+=f[F]-sz[x]+n;
	if(f[x]>ans){
		ans=f[x];
	}
	for(R i=Last[x];i!=0;i=Next[i]){
		int v=End[i];
		if(v!=F){
			sz[x]=n-sz[v];
			f[x]-=f[v]+n-sz[x];
			ReDFS(v,x,ans);
			f[x]+=f[v]+n-sz[x];
		}
	}
	sz[x]=n-sz[F];
	f[x]-=f[F]-sz[x]+n;
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		Link(x,y);
		Link(y,x);
	}
	PreDFS(1,0);
	L ans=0;
	ReDFS(1,0,ans);
	printf("%lld",ans);
	return 0;
}