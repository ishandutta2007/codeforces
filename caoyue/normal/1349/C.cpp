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
const int N=1007;
const int INF=1e9+7;
int n,m,hd=0,ti=0,hh=0,t;
char s[N]; 
bool a[N][N],vis[N][N];
int dis[N][N];
struct pir{int x,y;}Qu[N*N];
void dfs(int x,int y,bool v){
	bool fl=v;
	vis[x][y]=1;
	if(x>1&&a[x-1][y]==a[x][y]&&!vis[x-1][y]){
		fl=1;
		dfs(x-1,y,1);
	}
	if(x<n&&a[x+1][y]==a[x][y]&&!vis[x+1][y]){
		fl=1;
		dfs(x+1,y,1);
	}
	if(y>1&&a[x][y-1]==a[x][y]&&!vis[x][y-1]){
		fl=1;
		dfs(x,y-1,1);
	}
	if(y<m&&a[x][y+1]==a[x][y]&&!vis[x][y+1]){
		fl=1;
		dfs(x,y+1,1);
	}
	if(fl){
		dis[x][y]=0;
		Qu[++ti]=(pir){x,y};
		hh=1;
	} 
	else dis[x][y]=INF;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);
	rep(i,n){
		scanf("%s",s+1);
		rep(j,m)a[i][j]=s[j]-'0';
	}
	memset(dis,-1,sizeof(dis));
	rep(i,n)rep(j,m)if(dis[i][j]<0)dfs(i,j,0);
	while(hd!=ti){
		pir gg=Qu[++hd];
		int x=gg.x,y=gg.y;
		if(x>1&&dis[x-1][y]>dis[x][y]+1){
			dis[x-1][y]=dis[x][y]+1;
			Qu[++ti]=(pir){x-1,y};
		}
		if(x<n&&dis[x+1][y]>dis[x][y]+1){
			dis[x+1][y]=dis[x][y]+1;
			Qu[++ti]=(pir){x+1,y};
		}
		if(y>1&&dis[x][y-1]>dis[x][y]+1){
			dis[x][y-1]=dis[x][y]+1;
			Qu[++ti]=(pir){x,y-1};
		}
		if(y<m&&dis[x][y+1]>dis[x][y]+1){
			dis[x][y+1]=dis[x][y]+1;
			Qu[++ti]=(pir){x,y+1};
		}
	}
	while(t--){
		int x,y; ll c; scanf("%d%d%lld",&x,&y,&c);
		if(!hh){
			putchar('0'+a[x][y]);
			puts("");
		}
		else{
			if(c>(ll)dis[x][y]){
				putchar('0'+(a[x][y]^(c&1)^(dis[x][y]&1)));
				puts("");
			}
			else{
				putchar('0'+a[x][y]);
				puts("");
			}
		}
	}
	return 0;
}