#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
const int o=3e5;
int n,m,s[o],a[o],deg[o],U[o],V[o],S,T,S_,T_,h[o],cnt=1,cur[o],d[o],z[o];queue<int> q;
struct Edge{int v,p,c;}e[o];
inline void ad(int U,int V,int C){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].c=C;}
inline void add(int ST,int ED,int CA){ad(ST,ED,CA);ad(ED,ST,0);}
inline void addd(int U,int V,int L,int R){add(U,V,R-L);z[U]-=L;z[V]+=L;}
inline bool bfs(){
	for(int i=S;i<=T;d[i++]=0) cur[i]=h[i];
	for(q.push(S),d[S]=1;!q.empty();q.pop()) for(int i=h[q.front()];i;i=e[i].p)
		if(e[i].c&&!d[e[i].v]) d[e[i].v]=d[q.front()]+1,q.push(e[i].v);
	return d[T];
}
int dfs(int A,int B){
	if(A==T||!B) return B;
	int res=0,x;
	for(int&i=cur[A];i;i=e[i].p) if(e[i].c&&d[e[i].v]==d[A]+1)
		{x=dfs(e[i].v,min(e[i].c,B-res));e[i].c-=x;e[i^1].c+=x;if((res+=x)==B) return B;}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);S=0;S_=n+m+1;T_=S_+1;T=T_+1;
	for(int i=1;i<=n;++i) scanf("%d",&s[i]);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d%d",&U[i],&V[i]),++deg[U[i]],++deg[V[i]],addd(S_,i,1,1);
	for(int i=1;i<=n;++i)
		if(s[i]){
			if(a[i]>deg[i]||a[i]<-deg[i]||(deg[i]-a[i])%2){printf("NO\n");return 0;}
			a[i]=(a[i]+deg[i])/2;addd(i+m,T_,a[i],a[i]);
		}
		else addd(i+m,T_,0,o);
	for(int i=1;i<=m;++i) addd(i,U[i]+m,0,1),addd(i,V[i]+m,0,1);
	addd(T_,S_,0,o);
	for(int i=1;i<T;++i) if(z[i]>0) add(S,i,z[i]);else if(z[i]<0) add(i,T,-z[i]);
	for(;bfs();dfs(S,o));
	for(int i=h[S];i;i=e[i].p) if(e[i].c){printf("NO\n");return 0;}
	printf("YES\n");
	for(int i=1;i<=m;++i) for(int j=h[i];j;j=e[j].p)
		if(e[j].v-m&&e[j].v-m<=n&&!e[j].c) e[j].v-=m,printf("%d %d\n",U[i]+V[i]-e[j].v,e[j].v);
	return 0;
}