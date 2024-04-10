#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n;
struct side{
  int y,next;
}e[N*2+9];
int lin[N+9],cs;

void Ins(int x,int y){e[++cs].y=y;e[cs].next=lin[x];lin[x]=cs;}
void Ins2(int x,int y){Ins(x,y);Ins(y,x);}

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i) lin[i]=0;
  cs=0;
  for (int i=1;i<n;++i){
	int x,y;
	scanf("%d%d",&x,&y);++x;++y;
	Ins2(x,y);
  }
}

int bel[N+9];

void Dfs_bel(int k,int fa,int id){
  bel[k]=id;
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fa) Dfs_bel(e[i].y,k,id);
}

void Get_bel(){
  for (int i=lin[1];i;i=e[i].next) Dfs_bel(e[i].y,1,e[i].y);
}

int fa[N+9],son[N+9],dep[N+9],siz[N+9],top[N+9];

void Dfs_ord0(int k,int fat){
  fa[k]=fat;
  dep[k]=dep[fat]+1;
  siz[k]=1;
  son[k]=0;
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fat){
	  Dfs_ord0(e[i].y,k);
	  siz[k]+=siz[e[i].y];
	  if (siz[e[i].y]>siz[son[k]]) son[k]=e[i].y;
	}
}

void Dfs_ord1(int k,int t){
  top[k]=t;
  if (son[k]) Dfs_ord1(son[k],t);
  for (int i=lin[k];i;i=e[i].next)
	if (e[i].y^fa[k]&&e[i].y^son[k]) Dfs_ord1(e[i].y,e[i].y);
}

int Query_lca(int x,int y){
  for (;top[x]^top[y];x=fa[top[x]])
	if (dep[top[x]]<dep[top[y]]) swap(x,y);
  return dep[x]<dep[y]?x:y;
}

int Query_dis(int x,int y){return dep[x]+dep[y]-2*dep[Query_lca(x,y)];}

int Check_chain(int x,int y,int z){
  int dxy=Query_dis(x,y),dxz=Query_dis(x,z),dyz=Query_dis(y,z);
  if (dxy+dxz==dyz) return 1;
  if (dxy+dyz==dxz) return 2;
  if (dxz+dyz==dxy) return 3;
  return 0;
}

LL ans[N+9];

void Get_ans(){
  for (int i=0;i<=n+1;++i) ans[i]=0;
  ans[0]=1LL*n*(n-1)>>1;
  ans[1]=0;
  for (int i=lin[1],now=n;i;i=e[i].next) now-=siz[e[i].y],ans[1]+=1LL*siz[e[i].y]*now;
  int x=1,y=1;
  for (int i=2;i<=n;++i){
	int t=Check_chain(i,x,y);
	if (!t) break;
    if (t==2) x=i;
	if (t==3) y=i;
	ans[i]=1LL*siz[x]*(y==1?n-siz[bel[x]]:siz[y]);
  }
  for (int i=0;i<=n;++i) ans[i]-=ans[i+1];
}

void work(){
  Get_bel();
  Dfs_ord0(1,0);
  Dfs_ord1(1,1);
  Get_ans();
}

void outo(){
  for (int i=0;i<=n;++i)
	printf("%lld ",ans[i]);
  puts("");
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}