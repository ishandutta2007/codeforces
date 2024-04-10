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
const int N=37;
const int M=1507;
const int INF=1e9+7;
int n,m,cnt,tot,num,ooo=0;
char s[N],ss[N*2][N*2];
bool a[N][N],u[M],ed[M];
int to[N][N][4],X[M],Y[M],id[N][N],pos[M],f[M],fa[M],fc[M],fr[M],dis[M],Qu[M],dep[M],ys[M];
struct edge{int v,next,c;}e[M*5];
void add(int x,int y,int c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
void dfs(int x,int ft,int c,int d,int yy){
	ys[x]=yy;
	fa[x]=ft;
	fc[x]=c;
	dep[x]=d;
	repG(i,x){
		if(e[i].v==ft)continue;
		dfs(e[i].v,x,e[i].c,d+1,yy);
	}
}
vector<int>E[M];
bool sec(){
	memset(pos,-1,sizeof(pos));
	memset(ed,0,sizeof(ed));
	num=0;
	int hd=0,ti=0;
	rep(i,tot)f[i]=i;
	rep(i,cnt){
		if(u[i]){
			int x=ff(X[i]),y=ff(Y[i]);
			if(x!=y)f[x]=y;
			add(X[i],Y[i],i); add(Y[i],X[i],i);
		}
	}
	memset(dis,120,sizeof(dis));
	rep(i,cnt)E[i].clear();
	rep(i,tot)if(ff(i)==i)dfs(i,0,0,1,i);
	rep(i,cnt){
		if(!u[i]){
			int x=ff(X[i]),y=ff(Y[i]);
			if(x!=y)Qu[++ti]=i,dis[i]=0;
			else{
				x=X[i];
				y=Y[i];
				while(x!=y){
					if(dep[x]<dep[y])swap(x,y);
					E[fc[x]].push_back(i);
					x=fa[x];
				}
			}
		}
	}
	rep(i,n){
		rep(j,m){
			if(!a[i][j])continue;
			if(i+j>2&&(i+j)%2==0){
				int o=0;
				rep0(k,4)o+=u[to[i][j][k]];
				if(o==2){
					rep0(k,4){
						if(!to[i][j][k]||!u[to[i][j][k]])continue;
						rep0(l,4){
							if(!to[i][j][l]||u[to[i][j][l]])continue;
							E[to[i][j][l]].push_back(to[i][j][k]);
						}
					}
				}
				else rep0(k,4)if(to[i][j][k]&&!u[to[i][j][k]])ed[to[i][j][k]]=1;
			}
		}
	}
	while(hd!=ti){
		int t=Qu[++hd];
		if(ed[t]){
			int nw=t;
			while(dis[nw]){
				u[nw]^=1;
				nw=fr[nw];
			}
			u[nw]^=1;
			return 1;
		}
		for(int i=0;i<E[t].size();i++){
			int v=E[t][i];
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1;
				fr[v]=t;
				Qu[++ti]=v;
			}
		}
	}
	return 0;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		cnt=tot=0;
		rep(i,n){
			scanf("%s",s+1);
			rep(j,m)a[i][j]=(s[j]=='O');
		}
		memset(id,0,sizeof(id));
		memset(to,0,sizeof(to));
		rep(i,n)rep(j,m)if(a[i][j])id[i][j]=++tot;
		rep(i,n){
			rep(j,m){
				if(!id[i][j])continue;
				if(id[i+1][j]){
					to[i][j][0]=++cnt;
					to[i+1][j][1]=cnt;
					X[cnt]=id[i+1][j];
					Y[cnt]=id[i][j];
				}
				if(id[i][j+1]){
					to[i][j][2]=++cnt;
					to[i][j+1][3]=cnt;
					X[cnt]=id[i][j+1];
					Y[cnt]=id[i][j];
				}
			}
		}
		memset(u,0,sizeof(u));
		while(sec());
		rep(i,tot)f[i]=i;
		rep(i,cnt){
			if(u[i]){
				int x=ff(X[i]),y=ff(Y[i]);
				f[x]=y;
			}
		}
		rep(i,cnt){
			if(!u[i]){
				int x=ff(X[i]),y=ff(Y[i]);
				if(x!=y){
					u[i]=1;
					f[x]=y;
				}
			}
		}
		int fl=1;
		rep(i,n){
			rep(j,m){
				if(!a[i][j])continue;
				if(i+j>2&&(i+j)%2==0){
					int o=0;
					rep0(k,4)if(to[i][j][k])o+=u[to[i][j][k]];
					if(o<2)fl=0;
				}
			}
		}
		if(!fl)puts("NO");
		else{
			puts("YES");
			rep(i,n-1)rep(j,m-1)ss[i*2][j*2]=' ';
			rep(i,n)rep(j,m)ss[i*2-1][j*2-1]=a[i][j]?'O':'X';
			rep(i,n){
				rep(j,m){
					if(to[i][j][0]&&u[to[i][j][0]])ss[i*2][j*2-1]='O';
					else ss[i*2][j*2-1]=' ';
					if(to[i][j][2]&&u[to[i][j][2]])ss[i*2-1][j*2]='O';
					else ss[i*2-1][j*2]=' ';
				}
			}
			rep(i,2*n-1){
				rep(j,2*m-1)putchar(ss[i][j]);
				puts("");
			}
		}
	}
	return 0;
}