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
const int N=5e5+7;
const int INF=1e9+7;
int n;
int a[N],g[N],h[N];
struct pir{int x,v;}p[N];
bool cmp(pir x,pir y){return x.v<y.v;}
bool t[N];
struct dat{int vl,vr,vm,gg,l;};
dat mer(dat a,dat b){
	dat c=(dat){0,0,0,0,a.l+b.l};
	if(a.gg){
		if(b.gg)return (dat){a.l+b.l,a.l+b.l,a.l+b.l,1,a.l+b.l};
		c.vl=a.l+b.vl;
		c.vr=b.vr;
		c.vm=max(b.vm,c.vl);
		c.gg=0;
		return c;
	}
	if(b.gg){
		c.vr=a.vr+b.l;
		c.vl=a.vl;
		c.vm=max(a.vm,c.vr);
		c.gg=0;
		return c;
	}
	c.gg=0;
	c.vl=a.vl;
	c.vr=b.vr;
	c.vm=max(max(a.vm,b.vm),a.vr+b.vl);
	return c;
}
struct Tree{int l,r,mx,mi; dat q;}tr[N*4];
void upd(int p){
	tr[p].q=mer(tr[p*2].q,tr[p*2+1].q);
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
	tr[p].mi=min(tr[p*2].mi,tr[p*2+1].mi);
}
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,r,l,(dat){0,0,0,0,r-l+1}};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
void ins(int x,int p){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		if(tr[p].mx){
			tr[p].q=(dat){1,1,1,1,1};
			tr[p].mx=0;
			tr[p].mi=INF;
		}
		else{
			tr[p].q=(dat){0,0,0,0,1};
			tr[p].mx=tr[p].mi=x;
		}
		return;
	}
	int mid=(l+r)>>1;
	ins(x,p*2+(x>mid));
	upd(p);
}
int ch1(int p,int L){
	if(L<=tr[p].l)return tr[p].mi;
	int mid=(tr[p].l+tr[p].r)>>1;
	if(L<=mid)return min(ch1(p*2,L),tr[p*2+1].mi);
	return ch1(p*2+1,L);
}
int ch2(int p,int R){
	if(R>=tr[p].r)return tr[p].mx;
	int mid=(tr[p].l+tr[p].r)>>1;
	if(R>mid)return max(ch2(p*2+1,R),tr[p*2].mx);
	return ch2(p*2,R);
}
bool ck(int x){
	if(x<=1||x>=n)return 0;
	return (t[x-1]^t[x])&(t[x]^t[x+1]);
}
set<int>S;
void calc(int l,int r,int k){
	int cnt=0;
	for(set<int>::iterator ss=S.lower_bound(l);ss!=S.end();ss++){
		if((*ss)>r)break;
		g[(*ss)]=k;
		h[++cnt]=(*ss);
	}
	rep(i,cnt)S.erase(h[i]);
} 
void modify(int x,int nw){
	if(!ck(x)){
		int pl=ch2(1,x-1),pr=ch1(1,x+1);
		calc((x+pl+1)/2,x,nw);
		calc(x,(x+pr)/2,nw);
	}
	else{
		int pl=ch2(1,x-1),pr=ch1(1,x+1);
		if(t[pl])calc(pl,(pl+pr)/2,nw);
		if(t[pr])calc((pl+pr+1)/2,pr,nw);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)p[i]=(pir){i,a[i]};
	rep(i,n)S.insert(i);
	sort(p+1,p+n+1,cmp);
	memset(t,0,sizeof(t));
	build(1,n,1);
	int ans=0;
	p[n+1].v=-INF;
	rep(i,n){
		int e0=ck(p[i].x-1),e1=ck(p[i].x),e2=ck(p[i].x+1);
		t[p[i].x]^=1;
		if(ck(p[i].x-1)!=e0)ins(p[i].x-1,1);
		if(ck(p[i].x)!=e1)ins(p[i].x,1);
		if(ck(p[i].x+1)!=e2)ins(p[i].x+1,1);
		if(ck(p[i].x-1)!=e0)modify(p[i].x-1,p[i].v);
		if(ck(p[i].x)!=e1)modify(p[i].x,p[i].v);
		if(ck(p[i].x+1)!=e2)modify(p[i].x+1,p[i].v);
		if(ck(p[i].x)==e1){
			g[p[i].x]=a[p[i].x];
			S.erase(p[i].x);
		}
		if(p[i+1].v!=p[i].v)ans=max(ans,tr[1].q.vm);
	}
	printf("%d\n",(ans+1)/2);
	g[1]=a[1];
	g[n]=a[n];
	rep(i,n)printf("%d ",g[i]);
	puts("");
	return 0;
}