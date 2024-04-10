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
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e4+7;
const int M=107;
const int INF=1e9+7;
map<int,int>mh,ml;
int n,m,c1=0,c2=0,S,T,num=0;
int L[N],R[N],U[N],D[N],wh[N],wl[N],pos[N],dis[N],Qu[N],cur[N];
bool g[M][M];
struct edge{int v,next,c;}e[N];
void add(int x,int y,int c){
	e[num]=(edge){y,pos[x],c}; pos[x]=num++;
	e[num]=(edge){x,pos[y],0}; pos[y]=num++;
}
bool bfs(){
	rep(i,T){
		dis[i]=(i==S)?0:INF;
		cur[i]=pos[i];
	}
	int hd=0,ti=1;
	Qu[1]=S;
	while(hd!=ti){
		int t=Qu[++hd];
		repG(i,t){
			if(e[i].c&&dis[e[i].v]>dis[t]+1){
				dis[e[i].v]=dis[t]+1;
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
		if(e[cur[x]].c&&dis[e[cur[x]].v]==dis[x]+1){
			int k=dfs(e[cur[x]].v,min(e[cur[x]].c,fl-used));
			e[cur[x]].c-=k;
			e[cur[x]^1].c+=k;
			used+=k;
			if(used==fl)break;
		}
	}
	if(!used)dis[x]=INF;
	return used;
}
int main(){
	scanf("%d%d",&n,&m);
	if(!m){puts("0"); return 0;}
	rep(i,m){
		scanf("%d%d%d%d",&L[i],&U[i],&R[i],&D[i]);
		mh[L[i]]=mh[R[i]+1]=ml[U[i]]=ml[D[i]+1]=0;
	}
	for(map<int,int>::iterator i=mh.begin();i!=mh.end();i++){
		wh[++c1]=i->first;
		mh[i->first]=c1;
	}
	for(map<int,int>::iterator i=ml.begin();i!=ml.end();i++){
		wl[++c2]=i->first;
		ml[i->first]=c2;
	}
	c1--;
	c2--;
	rep(i,m){
		L[i]=mh[L[i]];
		R[i]=mh[R[i]+1]-1;
		U[i]=ml[U[i]];
		D[i]=ml[D[i]+1]-1;
	}
	S=c1+c2+1;
	T=S+1;
	memset(pos,-1,sizeof(pos));
	rep(i,c1)add(S,i,wh[i+1]-wh[i]);
	rep(i,c2)add(i+c1,T,wl[i+1]-wl[i]);
	rep(i,m)REP(j,L[i],R[i])REP(k,U[i],D[i])g[j][k]=1;
	rep(i,c1)rep(j,c2)if(g[i][j])add(i,j+c1,INF);
	int ans=0;
	while(bfs())ans+=dfs(S,INF);
	printf("%d\n",ans);
	return 0;
}