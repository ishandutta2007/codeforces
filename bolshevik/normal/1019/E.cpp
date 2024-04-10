#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
const int o=2e5+10;
int n,m,h[o],cnt,H[o],Cnt,tot,mxs,edg,s[o],c1,c2;bool vis[o];pair<long long,long long> p1[o],p2[o],z[o],conv[o*40];
struct Edge{int v,p,a,b;}e[o*2],E[o];
inline void ad(int U,int V,int A,int B){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].a=A;e[cnt].b=B;}
inline void Ad(int U,int V,int A,int B){E[++Cnt].v=V;E[Cnt].p=H[U];E[H[U]=Cnt].a=A;E[Cnt].b=B;}
void Dfs(int nw,int fa){
	for(int i=H[nw],j=nw;i;i=E[i].p) if(E[i].v^fa)
		ad(j,++tot,0,0),ad(tot,j,0,0),ad(j=tot,E[i].v,E[i].a,E[i].b),ad(E[i].v,j,E[i].a,E[i].b),Dfs(E[i].v,nw);
}
void dfs(int nw,int fa,int sz){
	s[nw]=1;
	for(int i=h[nw],j;i;i=e[i].p) if(e[i].v-fa&&!vis[(i+1)/2]){
		dfs(e[i].v,nw,sz);s[nw]+=s[e[i].v];
		if((j=max(s[e[i].v],sz-s[e[i].v]))<mxs) mxs=j,edg=(i+1)/2;
	}
}
void ddfs(int nw,int fa,long long sa,long long sb){
	++mxs;
	bool flg=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa&&!vis[(i+1)/2]) flg=0,ddfs(e[i].v,nw,sa+e[i].a,sb+e[i].b);
	if(flg) p1[++c1]=make_pair(sa,sb);
}
inline void Convex(pair<long long,long long>*pr,int&len){
	int nlen=1;
	sort(pr+1,pr+len+1);z[1]=pr[1];
	for(int i=2;i<=len;++i){
		for(;nlen>1&&(pr[i].second-z[nlen].second)*(__int128)(z[nlen].first-z[nlen-1].first)>=
		(z[nlen].second-z[nlen-1].second)*(__int128)(pr[i].first-z[nlen].first);--nlen);
		if(nlen>1) z[++nlen]=pr[i];
		else if(z[1].first==pr[i].first) z[1]=pr[i];else z[++nlen]=pr[i];
	}
	len=nlen;
	for(int i=1;i<=len;++i) pr[i]=z[i];
}
void dvd(int nw,int sz){
	if(sz==1) return;
	dfs(nw,0,mxs=sz);vis[edg]=1;ddfs(e[edg*2-1].v,c1=0,0,0);
	for(int i=1;i<=c1;++i) p2[i]=p1[i];
	c2=c1;ddfs(e[edg*2].v,c1=mxs=0,e[edg*2].a,e[edg*2].b);
	Convex(p1,c1);Convex(p2,c2);
	conv[++cnt]=make_pair(p1[1].first+p2[1].first,p1[1].second+p2[1].second);
	for(int i=1,j=1;i<c1||j<c2;conv[++cnt]=make_pair(p1[i].first+p2[j].first,p1[i].second+p2[j].second))
		if(j==c2||(i<c1&&(p1[i].second-p1[i+1].second)*(__int128)(p2[j+1].first-p2[j].first)<
		(p2[j].second-p2[j+1].second)*(__int128)(p1[i+1].first-p1[i].first))) ++i;else ++j;
	int t=mxs,U=e[edg*2-1].v;
	dvd(e[edg*2].v,mxs);dvd(U,sz-t);
}
int main(){
	scanf("%d%d",&n,&m);tot=n;
	for(int i=1,u,v,a,b;i<n;++i) scanf("%d%d%d%d",&u,&v,&a,&b),Ad(u,v,a,b),Ad(v,u,a,b);
	Dfs(1,0);cnt=0;dvd(1,tot);Convex(conv,cnt);
	for(int t=0,i=1;t<m;printf("%lld ",conv[i].first*(t++)+conv[i].second))
		for(;i<cnt&&conv[i].first*t+conv[i].second<conv[i+1].first*t+conv[i+1].second;++i);
	return 0;
}