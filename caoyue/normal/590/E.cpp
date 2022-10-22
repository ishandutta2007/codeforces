#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<bitset>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e7+7;
const int M=1007;
const int INF=1e9+7;
struct Trie{
	int to[2];
	int p,d;
}t[N];
int n,cnt=1,S,T,num=0;
char s[N];
int ln[M],Qu[N],hp[M];
vector<bool>p[M];
void Ac(){
	int hd=0,ti=1;
	Qu[1]=1;
	while(hd!=ti){
		int x=Qu[++hd];
		rep0(i,2){
			if(!t[x].to[i])continue;
			int nw=t[x].p;
			while(nw>1&&!t[nw].to[i])nw=t[nw].p;
			if(t[nw].to[i]&&t[nw].to[i]!=t[x].to[i])t[t[x].to[i]].p=t[nw].to[i];
			else t[t[x].to[i]].p=1;
			Qu[++ti]=t[x].to[i];
			if(!t[t[x].to[i]].d)t[t[x].to[i]].d=t[t[t[x].to[i]].p].d;
		}
	}
}
bitset<M>b[M];
bool cmp(int x,int y){return ln[x]<ln[y];}
struct edge{int v,next,c;}e[M*M*2];
int pos[M*2],dis[M*2],cur[M*2];
bool vis[M*2],gg[M*2];
void add(int x,int y,int c){
	e[num]=(edge){y,pos[x],c}; pos[x]=num++;
	e[num]=(edge){x,pos[y],0}; pos[y]=num++;
}
bool bfs(){
	int hd=0,ti=1;
	REP(i,S,T){
		dis[i]=INF;
		cur[i]=pos[i];
	}
	Qu[1]=S;
	dis[S]=0;
	while(hd!=ti){
		int x=Qu[++hd];
		repG(i,x){
			if(e[i].c&&dis[e[i].v]>dis[x]+1){
				dis[e[i].v]=dis[x]+1;
				Qu[++ti]=e[i].v;
			}
		}
	}
	return dis[T]<INF;
}
int dfs(int x,int fl){
	if(x==T)return fl;
	int used=0;
	for(;~cur[x];cur[x]=e[cur[x]].next){
		int i=cur[x];
		if(e[i].c&&dis[e[i].v]==dis[x]+1){
			int k=dfs(e[i].v,min(e[i].c,fl-used));
			used+=k;
			e[i].c-=k;
			e[i^1].c+=k;
		}
		if(used==fl)break;
	}
	if(!used)dis[x]=INF;
	return used;
}
void dfs2(int x,bool u,bool sd){
	if(!vis[x])return;
	vis[x]=0;
	gg[x]=u;
	repG(i,x){
		if(e[i].v==S||e[i].v==T)continue;
		if(e[i].c==(u^sd))dfs2(e[i].v,u^1,sd^1);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",s+1);
		ln[i]=strlen(s+1);
		int nw=1;
		rep(j,ln[i]){
			if(!t[nw].to[s[j]-'a']){
				t[nw].to[s[j]-'a']=++cnt;
				t[cnt].d=0;
			}
			nw=t[nw].to[s[j]-'a'];
			p[i].push_back(s[j]!='a');
		}
		t[nw].d=i;
	}
	Ac();
	rep(i,n){
		b[i]=0;
		int nw=1;
		rep0(j,ln[i]){
			nw=t[nw].to[p[i][j]];
			if(t[nw].d)b[i][t[nw].d]=1;
			if(t[t[nw].p].d)b[i][t[t[nw].p].d]=1;
		}
	}
	rep(i,n)hp[i]=i;
	sort(hp+1,hp+n+1,cmp);
	rep(o,n){
		int i=hp[o];
		rep(j,n)if(b[i][j])b[i]|=b[j];
	}
	S=0; T=2*n+1;
	memset(pos,-1,sizeof(pos));
	rep(i,n){
		add(S,i,1);
		add(i+n,T,1);
		rep(j,n)if(b[i][j]&&i!=j)add(i,j+n,1);
	}
	int ans=0,tot=0,sum=0;
	while(bfs())ans+=dfs(S,INF);
	printf("%d\n",n-ans);
	rep(i,n*2)vis[i]=gg[i]=1;
	rep(i,n){
		bool fl=0;
		repG(j,i)if(e[j].v==S)fl=e[j].c;
		if(!fl)dfs2(i,1,0);
		repG(j,i+n)if(e[j].v==T)fl=e[j].c^1;
		if(!fl)dfs2(i+n,1,1);
	}
	rep(i,n){
		bool fl=0;
		int id;
		repG(j,i){
			if(e[j].v==S)fl=e[j].c;
			else if(!e[j].c)id=e[j].v;
		}
		if(fl)if(gg[i]&&gg[id])gg[id]=0;
	}
	rep(i,n)if(gg[i]&&gg[i+n])printf("%d ",i);
	puts("");
	return 0;
}