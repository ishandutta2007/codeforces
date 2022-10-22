#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=3e5+7;
const int INF=1e9+7;
struct Tree{int l,r,sm;}tr[N*4];
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
void update(int p){tr[p].sm=tr[p*2].sm+tr[p*2+1].sm;}
void ins(int x,int p){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		tr[p].sm++;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ins(x,p*2);
	else ins(x,p*2+1);
	update(p);
}
int check(int p,int v){
	int l=tr[p].l,r=tr[p].r;
	if(l==r)return l;
	if(tr[p*2].sm>=v)return check(p*2,v);
	return check(p*2+1,v-tr[p*2].sm);
}
int n,m;
int Ans[N],a[N];
struct pir{int x,v,id;}w[N],q[N];
bool cmp1(pir a,pir b){return (a.v!=b.v)?(a.v>b.v):(a.x<b.x);}
bool cmp2(pir a,pir b){return (a.x!=b.x)?(a.x<b.x):(a.v>b.v);}

int main(){
	scanf("%d",&n);
	build(1,n,1);
	rep(i,n)scanf("%d",&w[i].v),w[i].x=i;
	rep(i,n)a[i]=w[i].v;
	scanf("%d",&m);
	rep(i,m)scanf("%d%d",&q[i].x,&q[i].v),q[i].id=i;
	sort(w+1,w+n+1,cmp1);
	sort(q+1,q+m+1,cmp2);
	int nw=1;
	rep(i,n){
		ins(w[i].x,1);
		while(nw<=m&&q[nw].x<=i){
			Ans[q[nw].id]=check(1,q[nw].v);
			nw++;
		}
	}
	rep(i,m)printf("%d\n",a[Ans[i]]);
	return 0;
}