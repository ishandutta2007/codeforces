#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2007;
const int M=4e6+7;
const int INF=1e9+7;
int a[N][N],f[N][N];
int dis[M],pos[M];
int n,m,cnt=0,num=0,rr,cc,X,Y;
char c[N];
struct edge{int v,next;}e[M*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void bfs(int x){
	memset(dis,120,sizeof(dis));
	queue<int>q0,q1;
	q0.push(x);
	dis[x]=0;
	while(!q0.empty()||!q1.empty()){
		int t;
		if(!q0.empty()){
			if(!q1.empty()){
				if(dis[q0.front()]<dis[q1.front()]){
					t=q0.front();
					q0.pop();
				}
				else t=q1.front(),q1.pop();
			}
			else t=q0.front(),q0.pop();
		}
		else t=q1.front(),q1.pop();
		repG(i,t){
			if(dis[e[i].v]>dis[t]+(e[i].v<t)){
				dis[e[i].v]=dis[t]+(e[i].v<t);
				if(e[i].v<t)q0.push(e[i].v);
				else q1.push(e[i].v);
			}
		}
	}
}
int main(){
	memset(pos,-1,sizeof(pos));
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&rr,&cc,&X,&Y);
	rep(i,n){
		scanf("%s",c+1);
		rep(j,m){
			if(c[j]=='*')a[i][j]=0;
			else a[i][j]=1;
		}
	}
	rep(i,m){
		rep(j,n){
			if(!a[j][i])continue;
			if(!a[j-1][i])cnt++;
			f[j][i]=cnt;
			if(f[j][i-1]){
				add(cnt,f[j][i-1]);
				add(f[j][i-1],cnt);
			}
		}
	}
	bfs(f[rr][cc]);
	int ans=0;
	rep(i,n){
		rep(j,m){
			int q=dis[f[i][j]];
			int p=j-cc+q;
			if(q<=X&&p<=Y)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}