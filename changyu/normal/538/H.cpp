#include<bits/stdc++.h>
const int N=1e5+3,INF=1e9+7;
struct segment{
	int l,r;
	segment(int x=-1,int y=INF){l=x,r=y;}
	inline segment operator*(const segment&b){return segment(std::max(l,b.l),std::min(r,b.r));}
	inline bool operator==(const segment&b){return l==b.l&&r==b.r;}
	inline bool In(int x){return x>=l&&x<r;}
	inline bool Empty(){return l>=r;}
}a[N],b,t[2],s;
int n,m,f[N],d[N],rt[2],tmp[N+N],k,pr[N+N],ans[N],p[N];
std::vector<int>g[N],pl[N+N];
void Dfs(int u){
	int v;
	t[d[u]]=t[d[u]]*a[u];
	if(!rt[d[u]])rt[d[u]]=u;
	p[u]=rt[d[u]];
	for(int i=0;i<g[u].size();i++){
	  v=g[u][i];
	  if(~d[v]&&d[v]==d[u])exit(0*puts("IMPOSSIBLE"));
	  if(d[v]<0)d[v]=d[u]^1,Dfs(v);
	}
}
inline int P(int a){return std::lower_bound(tmp+1,tmp+1+k,a)-tmp;}
inline void Out(int x,int y,int z,int w){
	--b.r;
	int s=-1,t=-1;
	puts("POSSIBLE");
	if(b.r-z>=x&&b.r-z<=y)s=b.r-z,t=z;
	if(b.r-w>=x&&b.r-w<=y)s=b.r-w,t=w;
	if(b.r-x>=z&&b.r-x<=w)s=x,t=b.r-x;
	if(b.r-y>=z&&b.r-y<=w)s=y,t=b.r-y;
	if(b.l-z>=x&&b.l-z<=y)s=b.l-z,t=z;
	if(b.l-w>=x&&b.l-w<=y)s=b.l-w,t=w;
	if(b.l-x>=z&&b.l-x<=w)s=x,t=b.l-x;
	if(b.l-y>=z&&b.l-y<=w)s=y,t=b.l-y;
	if(s<0&&t<0)s=x,t=z;
	printf("%d %d\n",s,t);
	for(int i=1;i<=n;i++)if(f[i]&&!ans[i]){
	  if(f[i]==i)ans[i]=a[i].In(s)?1:2;
	  if(f[i]!=i){
		if(a[f[i]]==a[i])ans[i]=1,ans[f[i]]=2;
		else if(a[f[i]]*a[i]==a[i]){
		  if(a[i].In(s))ans[i]=1,ans[f[i]]=2;
		  else ans[i]=2,ans[f[i]]=1;
		}
		else if(a[f[i]]*a[i]==a[f[i]]){
		  if(a[f[i]].In(s))ans[i]=2,ans[f[i]]=1;
		  else ans[i]=1,ans[f[i]]=2;
		}
		else if(a[i].l<a[f[i]].l)
		  ans[i]=1,ans[f[i]]=2;
		else
		  ans[i]=2,ans[f[i]]=1;
	  }
	}
	for(int i=1;i<=n;i++)printf("%d",ans[p[i]]);puts("");
} 
int main(){
	int u,v;
	scanf("%d%d%d%d",&b.l,&b.r,&n,&m),++b.r;
	for(int i=1;i<=n;i++){
	  scanf("%d%d",&a[i].l,&a[i].r),++a[i].r;
	  tmp[i]=a[i].l,tmp[i+n]=a[i].r;
	}
	std::sort(tmp+1,tmp+1+n+n);
	tmp[0]=-1;for(int i=1;i<=n+n;i++)if(tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(;m--;){
	  scanf("%d%d",&u,&v);
	  g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)d[i]=-1;
	for(int i=1;i<=n;i++)if(d[i]<0){
	  t[0]=t[1]=segment(-1,INF);
	  d[i]=0,rt[0]=i,rt[1]=0,Dfs(i);
	  a[i]=t[0];
	  pl[P(a[i].l)].push_back(i),pr[P(a[i].r)]=1;
	  if(rt[1]){
		a[rt[1]]=t[1];
		f[rt[0]]=rt[1],f[rt[1]]=rt[0];
	    pl[P(a[rt[1]].l)].push_back(rt[1]),pr[P(a[rt[1]].r)]=1;
	  }
	  else f[i]=i;
	}
	for(int j=1,i;j<=k;j++){
	  if(pr[j]){
		for(int i=1;i<=n;i++)if(f[i]){
		  if(f[i]==i&&a[i].l>=tmp[j])s=s*a[i];
		  if(f[i]!=i){
		  	if(std::min(a[i].l,a[f[i]].l)>=tmp[j])return 0*puts("IMPOSSIBLE");
			if(a[f[i]]==a[i])s=s*a[i];
			else if(a[f[i]]*a[i]==a[i])
			  s=s*(a[i].l<tmp[j]?a[f[i]]:a[i]);
			else if(a[f[i]]*a[i]==a[f[i]])
			  s=s*(a[f[i]].l<tmp[j]?a[i]:a[f[i]]);
			else if(a[i].l<a[f[i]].l)
			  s=s*a[f[i]];
			else
			  s=s*a[i];
		  }
		}
		if(s.Empty())return 0*puts("IMPOSSIBLE");
		if(!(segment(tmp[j-1]+s.l,tmp[j]+s.r-1)*b).Empty()){
		  Out(tmp[j-1],tmp[j]-1,s.l,s.r-1);return 0;
		}
		break;
	  }
	}return 0*puts("IMPOSSIBLE");
}