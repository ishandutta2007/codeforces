#include<cstdio>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
const int o=3e5,E=2e9;
int Tc,n,m,d1[o],d2[o],S,T,h[o],cur[o],cnt,d[o],flow,H[o],p1,g[o],Val[o];map<int,int> mp;queue<int> q;
struct Edge{int v,p,c;}e[o];
inline void ad(int U,int V,int C){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].c=C;}
inline void add(int ST,int ED,int CA){ad(ST,ED,CA);ad(ED,ST,0);}
inline bool bfs(){
	for(int i=S;i<=T;++i) d[i]=0,cur[i]=h[i];
	for(q.push(S),d[S]=1;!q.empty();q.pop())
		for(int i=h[q.front()];i;i=e[i].p) if(e[i].c&&!d[e[i].v]) d[e[i].v]=d[q.front()]+1,q.push(e[i].v);
	return d[T];
}
int dfs(int A,int B){
	if(A==T||!B) return B;
	int res=0,x;
	for(int&i=cur[A];i;i=e[i].p) if(e[i].c&&d[A]+1==d[e[i].v])
		{x=dfs(e[i].v,min(B-res,e[i].c));e[i].c-=x;e[i^1].c+=x;if((res+=x)==B) return B;}
	return res;
}
inline void link(int u,long long val){if(val>=0&&val<=E&&mp.find(val)!=mp.end()) add(u,mp[val]+n,1);}
inline bool calc(long long dis){
	S=0;T=n+m+1;cnt=1;flow=p1=0;
	for(int i=S;i<=T;++i) h[i]=0;
	for(int i=1;i<=n;++i) add(S,i,1),link(i,dis-d1[i]),link(i,d1[i]-dis),link(i,dis+d1[i]);
	for(int i=1;i<=m;++i) add(i+n,T,g[i]);
	for(;bfs();flow+=dfs(S,T));
	if(flow<n) return false;
	printf("YES\n");
	for(int i=1;i<=n;++i) for(int j=h[i];j;j=e[j].p) if(e[j].v&&!e[j].c)
		if(d1[i]+dis==Val[e[j].v-n]) H[i]=-d1[i];else H[i]=d1[i];
	for(int i=1;i<=n;++i) p1=max(p1,-H[i]);
	for(int i=1;i<=n;++i) printf("%d ",H[i]+p1);
	printf("\n%d %lld\n",p1,p1+dis);
	return true;
}
inline void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&d1[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&d2[i]);
		if(mp.find(d2[i])==mp.end()) g[mp[d2[i]]=++m]=0,Val[m]=d2[i];
		++g[mp[d2[i]]];
	}
	for(int i=1;i<=n;++i){
		if(calc(d1[1]+d2[i])) return;
		if(calc(abs(d1[1]-d2[i]))) return;
	}
	printf("NO\n");
}
int main(){
	for(scanf("%d",&Tc);Tc--;mp.clear(),m=0) slv();
	return 0;
}