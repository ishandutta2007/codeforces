#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
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
int n,m,q;
int a[N],p[N],nx[N],fa[N][22],ls[N],sw[N];

int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,n)scanf("%d",&p[i]);
	rep(i,n-1)nx[p[i]]=p[i+1];
	nx[p[n]]=p[1];
	rep(i,m)scanf("%d",&a[i]);
	sw[m+1]=m+1;
	for(int i=m;i;i--){
		fa[i][0]=ls[nx[a[i]]];
		for(int j=0;fa[fa[i][j]][j];j++)fa[i][j+1]=fa[fa[i][j]][j];
		int nw=i,hh=n-1;
		rep0(i,22)if(hh&(1<<i))nw=fa[nw][i];
		sw[i]=nw?nw:m+1;
		sw[i]=min(sw[i],sw[i+1]);
		ls[a[i]]=i;
	}
	rep(i,q){
		int l,r; scanf("%d%d",&l,&r);
		putchar('0'+(sw[l]<=r));
	}
	return 0;
}