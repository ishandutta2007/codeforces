#include<stdio.h>
#include<cmath>
#define R register int
#define D double
#define I inline
#define N 200001
#define M 400000
int Last[N],End[M],Next[M],Len[M],w[N],sz[N],ct;
I void Max(int&x,int y){
	x=x>y?x:y;
}
I void Link(int&x,int&y,int&z){
	ct++;
	End[ct]=y;
	Len[ct]=z;
	Next[ct]=Last[x];
	Last[x]=ct;
}
bool vis[N];
D sumdis=1e20,f[M];
int ansid;
I void GetCen(int x,int F,int&cen,int&totsize){
	sz[x]=1;
	int mx=0;
	for(R i=Last[x];i!=0;i=Next[i]){
		int v=End[i];
		if(vis[v]==false&&v!=F){
			GetCen(v,x,cen,totsize);
			sz[x]+=sz[v];
			Max(mx,sz[v]);
		}
	}
	Max(mx,totsize-sz[x]);
	if(mx<<1<=totsize){
		cen=x;
	}
}
I void AddDis(int x,int F,D&sumdis,D&ddis,int Dis,int e){
	D tem=sqrt(Dis)*w[x];
	sumdis+=tem;
	f[e]+=tem;
	ddis+=tem*Dis;
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			AddDis(End[i],x,sumdis,ddis,Dis+Len[i],e);
		}
	}
}
I void GetAns(int x,int totsize){
	int cen;
	GetCen(x,0,cen,totsize);
	vis[cen]=true;
	D tot=0,dtot=0;
	for(R i=Last[cen];i!=0;i=Next[i]){
		int v=End[i];
		D maxdis=0,ddis=0;
		AddDis(v,cen,maxdis,ddis,Len[i],i);
		tot+=maxdis;
		dtot+=ddis;
	}
	if(dtot<sumdis){
		sumdis=dtot;
		ansid=cen;
	}
	for(R i=Last[cen];i!=0;i=Next[i]){
		if(vis[End[i]]==false&&tot-f[i]*2<1e-9){
			return GetAns(End[i],sz[End[i]]<sz[cen]?sz[End[i]]:totsize-sz[cen]);
		}
	}
}
int main(){
	int n,x,y,z;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",w+i);
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		Link(x,y,z);
		Link(y,x,z);
	}
	GetAns(1,n);
	printf("%d ",ansid);
	printf("%.8lf",sumdis);
	return 0;
}