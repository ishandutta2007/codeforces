#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e6+7;
const int INF=1e9+7;
int n,cnt=1,num=0,ts=0;
char s[N];
int to[N][26],fa[N][22],fp[N],le[N],Qu[N],pos[N],dfn[N],ed[N],fdn[N],dep[N],S[N],nr[N],lo[N],lm[N],od[N],dis[N];
bool te[N];
void bfs(){
	int hd=0,ti=1;
	Qu[1]=1;
	fp[1]=1;
	while(hd!=ti){
		int o=Qu[++hd];
		rep0(j,26){
			if(!to[o][j])continue;
			int ls=fp[o];
			while(ls>1&&!to[ls][j])ls=fp[ls];
			if(to[ls][j]&&to[ls][j]!=to[o][j])fp[to[o][j]]=to[ls][j];
			else fp[to[o][j]]=1;
			Qu[++ti]=to[o][j];
		}
	}
}
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int x,int f,int d,int o){
	if(te[x])o=x;
	nr[x]=o;
	dep[x]=d;
	fa[x][0]=f;
	dfn[x]=ed[x]=++ts;
	fdn[ts]=x;
	dis[x]=dis[f]+te[x];
	for(int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
	repG(i,x){
		if(e[i].v==f)continue;
		dfs(e[i].v,x,d+1,o);
		ed[x]=ed[e[i].v];
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=dep[x]-dep[y],j=0;i;i>>=1,j++)if(i&1)x=fa[x][j];
	if(x==y)return x;
	for(int i=19;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
bool isfa(int x,int y){return (dfn[y]>=dfn[x])&(dfn[y]<=ed[x]);}
vector<int>cd[N],wd[N],sd[N],E[N];
int dfs0(int x){
	int ans=0;
	for(int j=0;j<E[x].size();j++){
		ans+=dfs0(E[x][j]);
		int L=lm[od[E[x][j]]],id=od[E[x][j]];
		lm[od[x]]=max(lm[od[x]],L);
		if(le[od[x]]>=L){
			ans+=dis[id]-dis[od[x]];
			continue;
		}
		if(le[id]<=L)continue;
		int nd=id;
		for(int k=20;~k;k--)if(le[fa[nd][k]]>L)nd=fa[nd][k];
		ans+=(dis[id]-dis[fa[nd][0]]);
	}
	return ans;
}
int calc(vector<int>ID){
	int tot=ID.size();
	rep(j,tot)od[j]=ID[j-1];
	int nw=tot,tp=2;
	S[1]=tot+1;
	S[2]=1;
	od[++tot]=1;
	rep(j,tot)E[j].clear();
	REP(i,2,nw){
		int ls=-1;
		while(!isfa(od[S[tp]],od[i])){
			if(~ls)E[S[tp]].push_back(ls);
			ls=S[tp];
			tp--;
		}
		if(ls>0){
			int t=lca(od[ls],od[i]);
			if(t==od[S[tp]])E[S[tp]].push_back(ls);
			else{
				od[++tot]=t;
				S[++tp]=tot;
				E[tot].clear();
				E[tot].push_back(ls);
			}
		}
		S[++tp]=i;
	}
	rep(i,tp-1)E[S[i]].push_back(S[i+1]);
	REP(i,nw+1,tot)lm[od[i]]=0;
	int w=dfs0(nw+1);
	return w-1;
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",s+1);
		int nw=1,mn=strlen(s+1);
		rep(j,mn){
			if(!to[nw][s[j]-'a'])to[nw][s[j]-'a']=++cnt;
			nw=to[nw][s[j]-'a'];
			le[nw]=j;
			cd[nw].push_back(i);
			sd[i].push_back(nw);
		}
		te[nw]=1;
	}
	bfs();
	memset(pos,-1,sizeof(pos));
	REP(i,2,cnt)add(fp[i],i);
	dfs(1,0,1,-1);
	rep(i,cnt)for(int j=0;j<cd[fdn[i]].size();j++)wd[cd[fdn[i]][j]].push_back(fdn[i]);
	ll ans=0;
	rep(i,n){
		int mn=sd[i].size();
		rep(j,mn){
			if(j==mn)lo[j]=(nr[fa[sd[i][j-1]][0]]>0)?le[nr[fa[sd[i][j-1]][0]]]:0;
			else lo[j]=(nr[sd[i][j-1]]>0)?le[nr[sd[i][j-1]]]:0;
		}
		lo[mn+1]=mn+1;
		for(int j=mn;j;j--){
			lo[j]=j-lo[j]+1;
			lo[j]=min(lo[j],lo[j+1]);
		}
		rep(j,mn)lo[j]=max(max(j-lo[j+1]+1,j-lo[j]),0);
		rep(j,mn)lm[sd[i][j-1]]=lo[j];
		ans+=(ll)calc(wd[i]);
	}
	printf("%lld\n",ans);
	return 0;
}