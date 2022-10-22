#include<cstdio>
using namespace std;
const int o=3010;
int n,h[o],cnt,rt[o],d[o],anc[o][12],st[o],tp,cir[o],id[o];bool vis[o];double ans; 
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw,int fa){
	vis[st[++tp]=nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		if(vis[e[i].v]){if(!cnt) for(int j=tp;st[j+1]^e[i].v;cir[++cnt]=st[j--]);}
		else Dfs(e[i].v,nw);
	--tp;
}
void dfs(int nw){
	for(int i=h[nw];i;i=e[i].p) if(!rt[e[i].v])
		rt[e[i].v]=rt[nw],d[e[i].v]=d[anc[e[i].v][0]=nw]+1,dfs(e[i].v);
}
inline int dis(int x,int y){
	int res=0;
	for(int i=11;i+1;--i) if(d[anc[x][i]]>=d[y]) x=anc[x][i],res+=(1<<i);
	for(int i=11;i+1;--i) if(d[anc[y][i]]>=d[x]) y=anc[y][i],res+=(1<<i);
	if(x==y) return res;
	for(int i=11;i+1;--i) if(anc[x][i]^anc[y][i]) x=anc[x][i],y=anc[y][i],res+=(1<<i+1);
	return res+2;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;++i) scanf("%d%d",&u,&v),ad(++u,++v),ad(v,u);
	Dfs(1,cnt=0);
	for(int i=1;i<=cnt;++i) rt[cir[i]]=cir[i];
	for(int i=1;i<=cnt;++i) id[cir[i]]=i,dfs(cir[i]);
	for(int i=1;i<12;++i) for(int j=1;j<=n;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
	d[0]=-1;
	for(int i=1;i<=n;++i) for(int j=1,k;j<=n;++j)
		if(rt[i]^rt[j])
			k=id[rt[j]]-id[rt[i]],k=(k<0)?-k:k,ans-=1.0/(d[i]+d[j]+cnt),
			ans+=1.0/(d[i]+d[j]+k+1),ans+=1.0/(d[i]+d[j]+cnt-k+1);
		else ans+=1.0/(dis(i,j)+1);
	printf("%.9lf",ans);
	return 0;
}