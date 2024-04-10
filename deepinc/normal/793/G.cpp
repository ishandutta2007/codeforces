#include<bits/stdc++.h>
using namespace std;
const int $=2e6;
int n,m,fir[$],la[$],to[$],ec=1,w[$],ans,pc,S,T,lst[$],r1,r0,lc[$],rc[$];
vector<int>l[$],r[$],o[$];
#define md (L+R>>1)
void link(int a,int b,int v){la[++ec]=fir[a];fir[a]=ec;to[ec]=b;w[ec]=v;}
void con(int a,int b,int v=$){link(a,b,v);link(b,a,0);}
void build(int&p0=r0,int&p1=r1,int L=1,int R=n){
	p0=++pc; p1=++pc; if(L==R)return con(L,p0),con(p1,L+n);
	build(lc[p0],lc[p1],L,md); build(rc[p0],rc[p1],md+1,R);
	con(lc[p0],p0); con(rc[p0],p0); con(p1,lc[p1]); con(p1,rc[p1]);
}
void ask(int l,int r,int P,int o,int p0=r0,int p1=r1,int L=1,int R=n){//cerr<<l<<' '<<r<<' '<<P<<' '<<o<<endl;
	if(l>r)return;
	if(l<=L&&R<=r)return o?con(P,p1):con(p0,P);
	if(l<=md)ask(l,r,P,o,lc[p0],lc[p1],L,md);
	if(r>md)ask(l,r,P,o,rc[p0],rc[p1],md+1,R);
}
int d[$],q[$];
bool bfs(){
	for(int i=1;i<=pc;++i)d[i]=$; d[S]=0; q[1]=S;
	for(int h=1,t=1,p;p=q[h],h<=t;++h)for(int i=fir[p],y;y=to[i];i=la[i])if(d[y]>d[p]+1&&w[i])d[q[++t]=y]=d[p]+1;
	return d[T]<$;
}
int dfs(int p,int f){
	if(p==T)return f; int r=f;
	for(int i=fir[p],y;(y=to[i])&&r;i=la[i])if(d[y]==d[p]+1&&w[i]){
		int x=dfs(y,min(r,w[i]));
		if(!x)d[y]=$;
		w[i]-=x;w[i^1]+=x;r-=x;
	}return f-r;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)lst[i]=1;
	#define pb push_back
	for(int i=1,u,d,L,R;i<=m;++i)scanf("%d%d%d%d",&u,&L,&d,&R),
		l[u].pb(L),r[u].pb(R),o[u].pb(1),
		l[d].pb(L),r[d].pb(R),o[d].pb(0);
	l[n+1].pb(1);r[n+1].pb(n);o[n+1].pb(1);
	pc=n+n; S=++pc; T=++pc; build();
	for(int i=1;i<=n;++i)con(S,i,1),con(i+n,T,1);
	for(int i=1;i<=n+1;++i)for(int j=0;j<l[i].size();++j){
		int O=o[i][j],L=l[i][j],R=r[i][j];
		if(O){
			int lp=L;
			for(int k=L;k<=R;++k)if(lst[k]!=lst[lp])pc++,ask(lp,k-1,pc,0),ask(lst[lp],i-1,pc,1),lp=k;
			pc++,ask(lp,R,pc,0),ask(lst[R],i-1,pc,1);
		}else for(int k=L;k<=R;++k)lst[k]=i+1;
	}
	while(bfs())ans+=dfs(S,$);
	printf("%d",ans);
}