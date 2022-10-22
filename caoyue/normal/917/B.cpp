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
const int N=207;
const int M=60;
const int INF=1e9+7;
int f[N][N][M],d[N][N],pos[N];
bool t[M];
struct pir{int x,y,v;}p[N*N];
struct edge{int v,next,c;}e[N*N];
int n,m,num=0;
void add(int x,int y,int c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void dfs(int x,int y){
	if(d[x][y]<INF)return;
	d[x][y]=N*N;
	repG(i,x){
		dfs(y,e[i].v);
		d[x][y]=min(d[x][y],d[y][e[i].v]-1);
	}
}
bool cmp(pir a,pir b){return a.v>b.v;}

int main(){
	memset(pos,-1,sizeof(pos)); 
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b; char s[4]; scanf("%d%d%s",&a,&b,s);
		add(a,b,s[0]-'a'+1);
	}
	memset(d,120,sizeof(d));
	rep(i,n)rep(j,n)if(d[i][j]>INF)dfs(i,j);
	rep(i,n)rep(j,n)p[(i-1)*n+j]=(pir){i,j,d[i][j]};
	sort(p+1,p+n*n+1,cmp);
	rep(v1,n*n){
		int i=p[v1].x,j=p[v1].y;
		memset(t,0,sizeof(t));
		repG(k,i)if(!f[j][e[k].v][e[k].c])t[e[k].c]=1;
		for(int k=26;k;k--)t[k]|=t[k+1];
		rep(k,26)f[i][j][k]=t[k];
	}
	rep(i,n){
		rep(j,n){
			if(f[i][j][1])printf("A");
			else printf("B");
		}
		printf("\n");
	}
	return 0;
}