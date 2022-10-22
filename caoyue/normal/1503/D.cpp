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
const int N=2e5+7;
const int INF=1e9+7;
int n;
struct seg{int L,R,ii;}p[N];
bool cmp(seg x,seg y){return (x.R!=y.R)?x.R<y.R:x.L>y.L;}
int f[N],g[N],wf[N],wg[N];
bool is[N];
struct Tree{int l,r,mf,mg,lz;}tr[N*8];
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,0,0,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
int realf(int x){return (tr[x].lz)?INF:tr[x].mf;}
int realg(int x){return (tr[x].lz)?INF:tr[x].mg;}
void upd(int p){
	tr[p].mf=min(realf(p*2),realf(p*2+1));
	tr[p].mg=min(realg(p*2),realg(p*2+1));
}
void lzd(int p){
	if(!tr[p].lz)return;
	tr[p].mf=INF;
	tr[p].mg=INF;
	tr[p*2].lz=1;
	tr[p*2+1].lz=1;
	tr[p].lz=0;
}
void ins(int p,int x,int v1,int v2){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		if(tr[p].lz){
			tr[p].lz=0;
			tr[p].mg=tr[p].mf=INF;
		}
		tr[p].mf=min(tr[p].mf,v1);
		tr[p].mg=min(tr[p].mg,v2);
		return;
	}
	lzd(p);
	int mid=(l+r)>>1;
	ins(p*2+(x>mid),x,v1,v2);
	upd(p);
}
void check(int p,int L,int R,int &v1,int &v2){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		v1=min(v1,realf(p));
		v2=min(v2,realg(p));
		return;
	}
	lzd(p);
	int mid=(l+r)>>1;
	if(L<=mid)check(p*2,L,R,v1,v2);
	if(R>mid)check(p*2+1,L,R,v1,v2);
	return;
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&p[i].L,&p[i].R);
	rep(i,n){
		if(p[i].L>p[i].R){
			p[i].ii=1;
			swap(p[i].L,p[i].R);
		}
	}
	sort(p+1,p+n+1,cmp);
	int mr=n+1,ml=0;
	rep(i,n){
		ml=max(ml,p[i].L);
		mr=min(mr,p[i].R);
	}
	if(ml>mr){
		puts("-1");
		return 0;
	}
	rep(i,n)is[i]=p[i].ii;
	rep(i,n)wf[i]=wf[i-1]+(!is[i]);
	rep(i,n)wg[i]=wg[i-1]+(is[i]);
	build(1,2*n,1);
	rep(i,n){
		if(i>1){
			int v1=INF,v2=INF;
			check(1,p[i].L,p[i].R,v1,v2);
			f[i-1]=v2+wf[i-1];
			g[i-1]=v1+wg[i-1];
			if(p[i].L>p[i-1].L||p[i].R<p[i-1].R)tr[1].lz=1;
			ins(1,p[i-1].L,f[i-1]-wg[i-1],g[i-1]-wf[i-1]);
		}
	}
	int v1=INF,v2=INF;
	check(1,1,n,v1,v2);
	int ans=min(v1+wg[n],v2+wf[n]);
	if(ans<INF/2)printf("%d\n",ans);
	else puts("-1");
	return 0;
}