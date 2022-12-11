#include<bits/stdc++.h>
using namespace std;
const int $=2e5;
int fir[$],l[$],to[$],w[$],c[$],ec=1,Ans[$],n1,n2,R,B,m,pc,S,T,s,t,ds,dt,ans;
int q[$],d[$],al[$],fl,ord[$]; char _[555];
void link(int a,int b,int v,int C){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;w[ec]=v;c[ec]=C;}
void con(int a,int b,int v,int C){link(a,b,v,C);link(b,a,0,-C);}
bool bfs(){
	for(int i=1;i<=pc;++i)al[i]=0,d[i]=$; d[S]=0; q[1]=S;
	for(int h=1,t=1,p;p=q[h];++h)for(int i=fir[p],y;y=to[i];i=l[i])if(d[y]>d[p]+c[i]&&w[i])
		d[q[++t]=y]=d[p]+c[i];
	return d[T]<$;
}
int dfs(int p,int f){
	if(p==T)return f; int r=f; al[p]=1;
	for(int i=fir[p],y;(y=to[i])&&r;i=l[i])if(!al[y]&&d[y]==d[p]+c[i]&&w[i]){
		int x=dfs(y,min(w[i],r));
		if(!x)d[y]=$;
		w[i]-=x;w[i^1]+=x;ans+=c[i]*x;r-=x;
	}return f-r;
}
int main(){
	scanf("%d%d%d%d%d%s",&n1,&n2,&m,&R,&B,_+1); pc=n1+n2; s=++pc; t=++pc; S=++pc; T=++pc;
	for(int i=1;i<=n1;++i)
		if(_[i]=='R')con(i,t,$,0),con(i,T,1,0),dt++;
		else if(_[i]=='B')con(S,i,1,0),con(s,i,$,0),ds++,fl++;
		else con(s,i,$,0),con(i,t,$,0);
	scanf("%s",_+n1+1);
	for(int i=n1+1;i<=n1+n2;++i)
		if(_[i]=='R')con(S,i,1,0),con(s,i,$,0),ds++,fl++;
		else if(_[i]=='B')con(i,T,1,0),con(i,t,$,0),dt++;
		else con(s,i,$,0),con(i,t,$,0);
	con(s,T,ds,0); con(S,t,dt,0); fl+=dt; con(t,s,$,0);
	for(int i=1,a,b;i<=m;++i)scanf("%d%d",&a,&b),b+=n1,
		ord[ec+1]=ord[ec+3]=i,con(a,b,1,B),con(b,a,1,R);
	while(bfs())fl-=dfs(S,$); if(fl)return puts("-1"),0;
	printf("%d\n",ans);
	for(int i=1;i<=n1;++i)for(int j=fir[i],x;x=to[j];j=l[j])if(!w[j]&&c[j]==B)Ans[ord[j]]=1;
	for(int i=n1;i<=n1+n2;++i)for(int j=fir[i],x;x=to[j];j=l[j])if(!w[j]&&c[j]==R)Ans[ord[j]]=-1;
	for(int i=1;i<=m;++i)putchar(Ans[i]?(Ans[i]>0?'B':'R'):'U');
}