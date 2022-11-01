#include<stdio.h>
#define R register int
#define I inline void
#define N 400001
#define M 800000
int Last[N],Next[M],End[M],sz[N],hsz[N],n,ct;
bool ans[N];
I Max(int&x,int y){
	x=x>y?x:y;
}
I Link(int&x,int&y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I PreDFS(int x,int F){
	sz[x]=1;
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			PreDFS(End[i],x);
			sz[x]+=sz[End[i]];
			Max(hsz[x],hsz[End[i]]);
		}
	}
	if(sz[x]<<1<=n){
		hsz[x]=sz[x];
	}
}
I ReDFS(int x,int F){
	sz[x]=n;
	int maxsize=0,halfsize,max1=0,max2=0,maxid;
	for(R i=Last[x];i!=0;i=Next[i]){
		int v=End[i];
		if(sz[v]>maxsize){
			maxsize=sz[v];
			halfsize=hsz[v];
		}
		if(hsz[v]>max1){
			max2=max1;
			max1=hsz[v];
			maxid=v;
		}else if(hsz[v]>max2){
			max2=hsz[v];
		}
	}
	ans[x]=maxsize-halfsize<<1<=n;
	for(R i=Last[x];i!=0;i=Next[i]){
		int v=End[i];
		if(v!=F){
			sz[x]=n-sz[v];
			if(sz[x]<<1<=n){
				hsz[x]=sz[x];
			}else if(v==maxid){
				hsz[x]=max2;
			}else{
				hsz[x]=max1;
			}
			ReDFS(v,x);
		}
	}
	sz[x]=n-sz[F];
	if(sz[x]<<1<=n){
		hsz[x]=sz[x];
	}else if(maxid==F){
		hsz[x]=max2;
	}else{
		hsz[x]=max1;
	}
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
	for(R i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}