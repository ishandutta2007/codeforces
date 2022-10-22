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
const int N=207;
const int INF=1e9+7;
int n,m,s1=0,s2=0,S,T,num=0;
struct edge{int v,next,c;}e[N*N*30];
int to[N][N][4],pos[N*N*5],dis[N*N*5],Qu[N*N*5],cur[N*N*5];
char g[N][N];
void add(int x,int y,int c){
	e[num]=(edge){y,pos[x],c}; pos[x]=num++;
	e[num]=(edge){x,pos[y],0}; pos[y]=num++;
}
bool bfs(){
	rep(i,T){
		cur[i]=pos[i];
		dis[i]=INF;
	}
	dis[S]=0;
	int hd=0,ti=0;
	Qu[++ti]=S;
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
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%s",g[i]+1);
	int ans=0;
	rep(i,n){
		rep(j,m){
			if(g[i][j]!='#')continue;
			if(i!=n){
				if(g[i+1][j]=='#'){
					if(!to[i][j][2]){
						to[i][j][2]=++s1;
						to[i+1][j][0]=s1;
					}
				}
			}
			if(j!=m){
				if(g[i][j+1]=='#'){
					if(!to[i][j][3]){
						to[i][j][3]=++s2;
						to[i][j+1][1]=s2;
					}
				}
			}
			ans++;
		}
	}
	memset(pos,-1,sizeof(pos));
	rep(i,n){
		rep(j,m){
			if(g[i][j]!='#')continue;
			if(to[i][j][0]&&to[i][j][1])add(to[i][j][0],to[i][j][1]+s1,1);
			if(to[i][j][1]&&to[i][j][2])add(to[i][j][2],to[i][j][1]+s1,1);
			if(to[i][j][0]&&to[i][j][3])add(to[i][j][0],to[i][j][3]+s1,1);
			if(to[i][j][2]&&to[i][j][3])add(to[i][j][2],to[i][j][3]+s1,1);
		}
	}
	S=s1+s2+1;
	T=S+1;
	rep(i,s1)add(S,i,1);
	rep(i,s2)add(i+s1,T,1);
	ans-=(s1+s2);
	while(bfs())ans+=dfs(S,INF);
	printf("%d\n",ans);
	return 0;
}