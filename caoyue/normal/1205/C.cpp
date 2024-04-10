#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=57;
const int INF=1e9+7;
bool ask(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}
int n;
bool vis[N][N],a[N][N];
void dfs(int x,int y,bool c){
	vis[x][y]=1;
	a[x][y]=c;
	if(x>1&&y>1&&!vis[x-1][y-1])dfs(x-1,y-1,c^ask(x-1,y-1,x,y)^1);
	if(x<n&&y<n&&!vis[x+1][y+1])dfs(x+1,y+1,c^ask(x,y,x+1,y+1)^1);
	if(x>2&&!vis[x-2][y])dfs(x-2,y,c^ask(x-2,y,x,y)^1);
	if(x<n-1&&!vis[x+2][y])dfs(x+2,y,c^ask(x,y,x+2,y)^1);
	if(y>2&&!vis[x][y-2])dfs(x,y-2,c^ask(x,y-2,x,y)^1);
	if(y<n-1&&!vis[x][y+2])dfs(x,y+2,c^ask(x,y,x,y+2)^1);
}

int main(){
	scanf("%d",&n);
	vis[n][n]=1;
	a[n][n]=0;
	dfs(1,1,1);
	for(int i=1;i<n;i+=2){
		if(a[i][i]==1&&a[i+2][i+2]==0){
			if(a[i+1][i+1]==a[i][i+2]&&a[i][i+2]==a[i+2][i]){
				if(ask(i,i,i+1,i+2))dfs(i+1,i+2,a[i][i]);
				else if(ask(i,i,i+2,i+1))dfs(i+2,i+1,a[i][i]);
				else if(ask(i,i+1,i+2,i+2)){dfs(i,i+1,a[i+2][i+2]);}
				else if(ask(i+1,i,i+2,i+2)){
					vis[i][i+1]=1;
					a[i][i+1]=a[i+2][i+2]^1;
					dfs(i+1,i,a[i+2][i+2]);
					dfs(i,i+1,a[i+2][i+2]^1);
				}
				else{
					vis[i][i+1]=vis[i+1][i]=vis[i+2][i+1]=vis[i+1][i+2]=1;
					if(!ask(i,i+1,i+2,i+1))a[i][i+1]=a[i][i],a[i+2][i+1]=a[i+2][i+2];
					else a[i][i+1]=a[i+2][i+1]=a[i+1][i+1]^1;
					if(!ask(i+1,i,i+1,i+2))a[i+1][i]=a[i][i],a[i+2][i+1]=a[i+2][i+2];
					else a[i+1][i]=a[i+1][i+2]=a[i+1][i+1]^1;
					dfs(i+1,i,a[i+1][i]);
					dfs(i,i+1,a[i][i+1]);
					dfs(i+1,i+2,a[i+1][i+2]);
					dfs(i+2,i+1,a[i+2][i+1]);
				}
			}
			else{
				if(a[i+1][i+1]!=a[i][i+2])dfs(i+1,i+2,a[i][i]^ask(i,i,i+1,i+2)^1);
				else dfs(i+2,i+1,a[i][i]^ask(i,i,i+2,i+1)^1);
			}
			break;
		}
	}
	puts("!");
	rep(i,n){
		rep(j,n)putchar('0'+a[i][j]);
		puts("");
	}
	fflush(stdout);
	return 0;
}