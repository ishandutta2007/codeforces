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
const int INF=1e9+7;
int n,k,cnt=1;
int f[N][N],a[N][N],fr[N][N];
char sv[N];
bool vis[N][N];
struct pir{int x,y;}p[N*5],s[N*5];
void dfs(int i,int j){
	if(fr[i][j]<0){
		if(i+j-1<=k+f[i][j])rep(v,i+j-1)printf("a");
		else printf("%c",a[i][j]+'a');
		return;
	}
	if(fr[i][j]&1)dfs(i-1,j);
	else dfs(i,j-1);
	printf("%c",a[i][j]+'a');
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n){
		scanf("%s",sv+1);
		rep(j,n)a[i][j]=sv[j]-'a';
	}
	rep(i,n)rep(j,n)f[i][j]=max(f[i-1][j],f[i][j-1])+(a[i][j]==0);
	int maxn=1;
	p[1]=(pir){1,1};
	rep(i,n){
		rep(j,n){
			int d=i+j-1;
			if(d<=k+f[i][j]){
				if(d>maxn){
					cnt=1;
					p[1]=(pir){i,j};
					maxn=d;
				}
				else if(d==maxn)p[++cnt]=(pir){i,j};
			}
		}
	}
	rep(i,cnt)vis[p[i].x][p[i].y]=1,fr[p[i].x][p[i].y]=-1;
	int ls=0;
	while(!vis[n][n]){
		int nw=0,minn=INF;
		rep(i,cnt){
			if(!vis[p[i].x+1][p[i].y]&&p[i].x!=n){
				if(a[p[i].x+1][p[i].y]<minn){
					nw=1;
					s[1]=(pir){p[i].x+1,p[i].y};
					minn=a[p[i].x+1][p[i].y];
				}
				else if(a[p[i].x+1][p[i].y]==minn)s[++nw]=(pir){p[i].x+1,p[i].y};
				vis[p[i].x+1][p[i].y]=1;
				fr[p[i].x+1][p[i].y]=1;
			}
			if(!vis[p[i].x][p[i].y+1]&&p[i].y!=n){ 
				if(a[p[i].x][p[i].y+1]<minn){
					nw=1;
					s[1]=(pir){p[i].x,p[i].y+1};
					minn=a[p[i].x][p[i].y+1];
				}
				else if(a[p[i].x][p[i].y+1]==minn)s[++nw]=(pir){p[i].x,p[i].y+1};
				vis[p[i].x][p[i].y+1]=1;
				fr[p[i].x][p[i].y+1]=2; 
			}
		}
		cnt=0;
		rep(i,nw)if(s[i].x<=n&&s[i].y<=n)p[++cnt]=s[i];
	}
	dfs(n,n);
	printf("\n");
	return 0;
}