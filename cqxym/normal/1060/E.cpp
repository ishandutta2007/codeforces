#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 200001
#define M 400000
int Last[N],Next[M],End[M],sz[N],ct1[N],n,ct;
L dis1[N],dis2[N],ans;
I void Link(int&x,int&y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I void PreDFS(int x,int F){
	sz[x]=1;
	for(R i=Last[x];i!=0;i=Next[i]){
		int v=End[i];
		if(v!=F){
			PreDFS(v,x);
			sz[x]+=sz[v];
			dis1[x]+=dis2[v]+sz[v]-ct1[v];
			dis2[x]+=dis1[v]+ct1[v];
			ct1[x]+=sz[v]-ct1[v];
		}
	}
}
I void ReDFS(int x,int F){
	sz[x]=n;
	dis1[x]+=dis2[F]+sz[F]-ct1[F];
	dis2[x]+=dis1[F]+ct1[F];
	ct1[x]+=sz[F]-ct1[F];
	ans+=dis1[x]+ct1[x]+dis2[x]>>1;
	for(R i=Last[x];i!=0;i=Next[i]){
		int v=End[i];
		if(v!=F){
			sz[x]-=sz[v];
			dis1[x]-=dis2[v]+sz[v]-ct1[v];
			dis2[x]-=dis1[v]+ct1[v];
			ct1[x]-=sz[v]-ct1[v];
			ReDFS(v,x);
			sz[x]=n;
			dis1[x]+=dis2[v]+sz[v]-ct1[v];
			dis2[x]+=dis1[v]+ct1[v];
			ct1[x]+=sz[v]-ct1[v];
		}
	}
	sz[x]-=sz[F];
	dis1[x]-=dis2[F]+sz[F]-ct1[F];
	dis2[x]-=dis1[F]+ct1[F];
	ct1[x]-=sz[F]-ct1[F];
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
	ReDFS(1,0);
	printf("%lld",ans>>1);
	return 0;
}