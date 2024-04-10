#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
const int o=1e5;const long long inf=1e18;
int n,m,h[o],cur[o],cnt=1,S,T,d[o];long long ans;queue<int> q;
struct Edge{int v,p;long long c;}e[o];
inline void ad(int U,int V,long long C){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].c=C;}
inline void add(int ST,int ED,long long CA){ad(ST,ED,CA);ad(ED,ST,0);}
inline bool bfs(){
	for(int i=S;i<=T;++i) d[i]=0,cur[i]=h[i];
	for(q.push(S),d[S]=1;!q.empty();q.pop())
		for(int i=h[q.front()];i;i=e[i].p) if(e[i].c&&!d[e[i].v])
			d[e[i].v]=d[q.front()]+1,q.push(e[i].v);
	return d[T];
}
long long dfs(int A,long long B){
	if(A==T||!B) return B;
	long long res=0,x;
	for(int&i=cur[A];i;i=e[i].p) if(e[i].c&&d[A]+1==d[e[i].v])
		x=dfs(e[i].v,min(B-res,e[i].c)),e[i].c-=x,e[i^1].c+=x,res+=x;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);S=0;T=n+m+1; 
	for(int i=1,j;i<=n;++i) scanf("%d",&j),add(S,i,j);
	for(int i=1,u,v,j;i<=m;++i)
		scanf("%d%d%d",&u,&v,&j),add(u,i+n,inf),add(v,i+n,inf),add(i+n,T,j),ans+=j;
	for(;bfs();ans-=dfs(S,inf));
	printf("%lld",ans);
	return 0;
}