#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,k,q,i,j,dis[400005],par[400005],fa[400005][19],dep[400005];
vector<int> bi[400005];
int fnd(int x)
{
	if(par[x]==x) return x;
	return par[x]=fnd(par[x]);
}
void dfs(int x,int p)
{
	fa[x][0]=p;
	ff(bi[x],it){
		if(*it==p) continue;
		dep[*it]=dep[x]+1;
		dfs(*it,x);
	}
}
int gtf(int x,int t)
{
	int i;
	fd0g(i,18) if((t>>i)&1){
		x=fa[x][i];
	}
	return x;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int i,t=dep[x]-dep[y];
	fd0g(i,18) if((t>>i)&1){
		x=fa[x][i];
	}
	if(x==y) return x;
	fd0g(i,18){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	fz1(i,n-1){
		 int x,y;
		 scanf("%d%d",&x,&y);
		 bi[x].push_back(i+n);
		 bi[i+n].push_back(x);
		 bi[y].push_back(i+n);
		 bi[i+n].push_back(y);
	}
	fz1(i,n+n-1) par[i]=i;
	memset(dis,0x3f,sizeof(dis));
	queue<int> qx;
	fz1(i,m){
		int x;
		scanf("%d",&x);
		dis[x]=0;
		qx.push(x);
	}
	while(!qx.empty()){
		int x=qx.front();qx.pop();
		ff(bi[x],it){
			if(dis[*it]>dis[x]+1){
				dis[*it]=dis[x]+1;
				if(dis[*it]<k){
					qx.push(*it);
				}
			}
			par[fnd(x)]=fnd(*it);
		}
	} 
	fz1(i,n+n-1) fnd(i);
	dfs(1,0);
	fz1(j,18)fz1(i,n+n-1){
		fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int z=lca(x,y),dis=dep[x]+dep[y]-2*dep[z];
		if(dis<=k+k){
			puts("YES");
			continue;
		}
		if(dep[x]-dep[z]>=k){
			x=gtf(x,k);
		}
		else{
			x=gtf(y,dep[y]-dep[z]-(k-(dep[x]-dep[z])));
		}
		if(dep[y]-dep[z]>=k){
			y=gtf(y,k);
		}
		else{
			y=gtf(x,dep[x]-dep[z]-(k-(dep[y]-dep[z])));
		}
		if(fnd(x)==fnd(y)) puts("YES"); else puts("NO");
	}
	return 0;
}