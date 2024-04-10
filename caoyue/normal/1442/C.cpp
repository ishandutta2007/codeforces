#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=3e5+7;
const int INF=1e9+7;
const int mod=998244353;
struct pir{int x,y,v;}Qu[N*100];
int n,m,num=0;
struct edge{int v,next,c;}e[N*2];
int pos[N],dis[N][2][22];
void add(int x,int y,int c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void bfs(){
	memset(dis,120,sizeof(dis));
	dis[1][0][0]=0;
	Qu[1]=(pir){1,0,0};
	int hd=0,ti=1;
	while(hd!=ti){
		pir t=Qu[++hd];
		int u=(t.y<0)?-t.y:t.y,v=(t.y<0);
		if(u>20)continue;
		repG(j,t.x){
			if(dis[e[j].v][e[j].c][u+(v!=e[j].c)]>dis[t.x][v][u]+1){
				dis[e[j].v][e[j].c][u+(v!=e[j].c)]=dis[t.x][v][u]+1;
				if(e[j].c)Qu[++ti]=(pir){e[j].v,-u-(v!=e[j].c),dis[t.x][v][u]+1};
				else Qu[++ti]=(pir){e[j].v,u+(v!=e[j].c),dis[t.x][v][u]+1};
			}
		}
	}
}
struct D{
	int xx,yy,x,v;
	friend bool operator < (D a,D b){
		if(a.x!=b.x)return a.x>b.x;
		return a.v>b.v;
	}
}d[2][N];
bool vis[2][N];
priority_queue<D>Q;
int dij(){
	rep(i,n)d[0][i]=d[1][i]=(D){0,0,INF,0};
	d[0][1]=(D){0,1,0,0};
	Q.push(d[0][1]);
	while(!Q.empty()){
		D t=Q.top();
		Q.pop();
		if(vis[t.xx][t.yy])continue;
		vis[t.xx][t.yy]=1;
		repG(j,t.yy){
			D nw=(D){e[j].c,e[j].v,d[t.xx][t.yy].x+(e[j].c!=t.xx),t.v+1};
			if(d[e[j].c][e[j].v]<nw){
				d[e[j].c][e[j].v]=nw;
				Q.push(nw);
			}
		}
	}
	int s=1;
	D dd=(d[0][n]<d[1][n])?d[1][n]:d[0][n];
	rep(i,dd.x)s=(s+s)%mod;
	s=(s+dd.v-1+mod)%mod;
	return s;
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d",&n,&m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v,0); add(v,u,1);
	}
	bfs();
	int Ans=INF;
	rep0(i,20)Ans=min(Ans,min(dis[n][0][i],dis[n][1][i])+(1<<i)-1);
	if(Ans<INF)printf("%d\n",Ans);
	else printf("%d\n",dij());
	return 0;
}