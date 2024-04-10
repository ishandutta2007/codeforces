#include<bits/stdc++.h>
using namespace std;
const int $=20000;
int n,a,b,fir[$],l[$],to[$],w[$],q[$],al[$],ec=1;double p1[$],p2[$],c[$],d[$],ans;
void link(int a,int b,int v,double C){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;w[ec]=v;c[ec]=C;}
void con(int a,int b,int v,double C){link(a,b,v,C);link(b,a,0,-C);}
bool bfs(){
	for(int i=1;i<=n+4;++i)d[i]=1e9,al[i]=0; d[n+1]=0; q[1]=n+1;
	for(int h=1,t=1,p;p=q[h],h<=t;++h)for(int i=fir[p],y;y=to[i];i=l[i])if(d[y]>d[p]+c[i]+1e-5&&w[i])
		d[q[++t]=y]=d[p]+c[i];
	return d[n+2]<0;
}
int dfs(int p,int f){
	if(p==n+2)return f; int r=f; al[p]=1;
	for(int i=fir[p],y;(y=to[i])&&r;i=l[i])if(fabs(d[y]-d[p]-c[i])<1e-5&&w[i]&&!al[y]){
		int x=dfs(y,min(r,w[i]));
		if(!x)d[x]=1e9;
		w[i]-=x;w[i^1]+=x;ans+=c[i]*x;r-=x;
	}return f-r;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)scanf("%lf",&p1[i]),con(n+3,i,1,-p1[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&p2[i]),con(n+4,i,1,-p2[i]);
	con(n+1,n+3,a,0); con(n+1,n+4,b,0);
	for(int i=1;i<=n;++i)con(i,n+2,1,0),con(i,n+2,1,p1[i]*p2[i]);
	while(bfs())dfs(n+1,1e9);
	printf("%.5lf",-ans);
}