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
#include<bitset>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
const int M=4e5+7;
int n,m,q,num=0,fl=0;
struct edge{int v,next;}e[N*2];
int pos[N],co[N],son[M][2],fa[M],mn[M],a[M],to[M],fr[M],sz[M],sa[M],U[N],V[N];
bool tn[M],in[M];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;}
void dfs(int cc,int x){
	co[x]=cc;
	repG(i,x){
		if(~co[e[i].v]){
			if(co[e[i].v]==co[x]){
				fl=1;
				break;
			}
		}
		else dfs(cc^1,e[i].v);
	}
}
void upd(int x){
	mn[x]=a[x];
	sz[x]=sa[x];
	if(son[x][0]){
		mn[x]=min(mn[x],mn[son[x][0]]);
		sz[x]+=sz[son[x][0]];
	}
	if(son[x][1]){
		mn[x]=min(mn[x],mn[son[x][1]]);
		sz[x]+=sz[son[x][1]];
	}
}
void lzd(int x){
	if(tn[x]){
		swap(son[x][0],son[x][1]);
		tn[son[x][0]]^=1;
		tn[son[x][1]]^=1;
		tn[x]=0;
	}
}
void rot(int x){
	lzd(fa[x]);
	lzd(x);
	bool u=son[fa[x]][1]==x;
	int x1=fa[x],x2=fa[fa[x]],x3=son[x][u^1];
	fa[x]=x2;
	if(x2)son[x2][son[x2][1]==x1]=x;
	else to[x]=to[x1],to[x1]=0;
	fa[x1]=x;
	son[x][u^1]=x1;
	son[x1][u]=x3;
	if(x3)fa[x3]=x1;
	upd(x1);
	upd(x);
}
void goup(int x){
	while(fa[x]){
		if(fa[fa[x]]){
			if((son[fa[x]][1]==x)==(son[fa[fa[x]]][1]==fa[x]))rot(fa[x]);
			else rot(x);
		}
		rot(x);
	}
	lzd(x);
	upd(x);
}
void acc(int x){
	goup(x);
	if(son[x][1]){
		fa[son[x][1]]=0;
		to[son[x][1]]=x;
		son[x][1]=0;
		upd(x);
	}
	while(to[x]){
		int gg=to[x];
		goup(gg);
		if(son[gg][1]){
			fa[son[gg][1]]=0;
			to[son[gg][1]]=gg;
		}
		son[gg][1]=x;
		fa[x]=gg;
		to[x]=0;
		upd(gg);
		goup(x);
	}
}
void trt(int x){acc(x); goup(x); tn[x]^=1;}
struct pir{int d,mn;};
pir check(int x,int y){
	trt(x);
	acc(y);
	goup(x);
	goup(y);
	if(fa[x]==0)return (pir){-1,-1};
	return (pir){sz[y],mn[y]};
}
void ins(int x){
	trt(V[x]);
	goup(V[x]);
	to[V[x]]=x+n;
	to[x+n]=U[x];
}
void del(int x){
	trt(U[x]);
	acc(x+n);
	goup(V[x]);
	to[V[x]]=0;
	acc(U[x]);
	to[x+n]=0;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	memset(pos,-1,sizeof(pos));
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		U[i]=x;
		V[i]=y;
	}
	memset(co,-1,sizeof(co));
	rep(i,n)if(co[i]<0)dfs(0,i);
	if(!fl){
		rep(i,q){
			int x,y; scanf("%d%d",&x,&y);
			puts("NO");
		}
		return 0;
	}
	rep(i,n)mn[i]=a[i]=INF,sa[i]=sz[i]=0;
	rep(i,m)mn[i+n]=a[i+n]=i,sa[i+n]=sz[i+n]=1;
	int l=1;
	rep(i,m*2){
		while(l<=i-m){
			del(l);
			in[l]=0;
			l++;
		}
		int id=(i-1)%m+1;
		pir t=check(U[id],V[id]);
		if(t.d>=0){
			if(t.d&1){
				del((t.mn-1)%m+1);
				in[(t.mn-1)%m+1]=0;
			}
			else{
				while(l<=t.mn){
					if(in[(l-1)%m+1]){
						del((l-1)%m+1);
						in[(l-1)%m+1]=0;
					}
					l++;
				}
			}
		}
		a[id+n]=mn[n+id]=i;
		ins(id);
		in[id]=1;
		fr[i]=l;
		if(l>m+1){
			REP(j,i+1,m*2)fr[j]=l;
			break;
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		if(fr[x+m-1]>y+1)puts("YES");
		else puts("NO");
	}
	return 0;
}