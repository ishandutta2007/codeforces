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
const int N=1e5+7;
const int INF=1e9+7;
int T,num,n,A,B;
int pos[N],dep[N],fa[N],ln[N],t[N],Qu[N];
bool is[N],p[N],vis[N];
struct edge{int v,next;}e[N*2];
void add(int x,int y){e[num]=(edge){y,pos[x]}; pos[x]=num++;} 
void dfs1(int x,int f){
	ln[x]=0;
	dep[x]=dep[f]+1;
	fa[x]=f;
	repG(i,x){
		if(e[i].v==f)continue;
		dfs1(e[i].v,x);
		ln[x]=max(ln[x],ln[e[i].v]+1);
	}
}
void dfs2(int x,int l){
	int mx=-1,md=0,nx=-1,s=(l>=(dep[B]-dep[A]));
	repG(i,x){
		if(e[i].v==fa[x])continue;
		s+=((ln[e[i].v]+1)>=(dep[B]-dep[A]));
		if(ln[e[i].v]>mx){
			nx=mx;
			mx=ln[e[i].v];
			md=e[i].v;
		}
		else if(ln[e[i].v]>nx)nx=ln[e[i].v];
	}
	if(s>=3)is[x]=1;
	repG(i,x){
		if(e[i].v==fa[x])continue;
		if(e[i].v==md)dfs2(e[i].v,max(l,nx+1)+1);
		else dfs2(e[i].v,max(l,mx+1)+1);
	}
}
int dfs3(int x,int d,int f){
	int mx=0;
	repG(i,x){
		if(!vis[e[i].v])continue;
		if(e[i].v==f)continue;
		mx=max(dfs3(e[i].v,d,x)+1,mx);
	}
	p[d]|=is[x];
	return mx; 
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&A,&B);
		num=0;
		rep(i,n){
			pos[i]=-1;
			is[i]=0;
			vis[i]=1;
		}
		rep(i,n-1){
			int x,y; scanf("%d%d",&x,&y);
			add(x,y); add(y,x);
		}
		dfs1(A,0);
		dfs2(A,0);
		rep(i,dep[B])p[i]=0;
		for(int i=B;i;i=fa[i])vis[i]=0;
		for(int i=B;i;i=fa[i])t[dep[i]]=dfs3(i,dep[i],0);
		int nl=1,nr=dep[B],hd=0,ti=2;
		bool ans=p[1]|p[dep[B]];
		Qu[1]=1;
		Qu[2]=dep[B];
		while(hd!=ti){
			if(ans)break;
			if(nl>=nr-1)break;
			int q=Qu[++hd];
			if(q>nl){
				while(q-(nl+1)+t[q]>=dep[B]-1){
					nl++;
					ans|=p[nl];
					if(nl>=nr-1)break;
					Qu[++ti]=nl;
				}
			}
			else{
				while((nr-1)-q+t[q]>=dep[B]-1){
					nr--;
					ans|=p[nr];
					if(nr-1<=nl)break;
					Qu[++ti]=nr;
				}
			}
		}
		if(ans)puts("YES");
		else puts("NO");
	}
	return 0;
}