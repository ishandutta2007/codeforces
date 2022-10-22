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
const int N=1e6+7;
const int INF=1e9+7;
int n,d,cnt;
int s[N],a[N],c[N],vl[N],da[N];
struct pp{int x,v;}pq[N];
bool cmp(pp a,pp b){return a.v<b.v;}
struct pir{int x,s,a;};
vector<pir>p1[N],p2[N],p3[N],p4[N];
bool t[N];
int low(int x){return x&(-x);}
void ins(int x){
	for(int i=x;i<=cnt;i+=(i&(-i)))c[i]++;
}
int check(int L,int R){
	int ans=0;
	for(int i=R;i;i-=(i&(-i)))ans+=c[i];
	for(int i=L-1;i;i-=(i&(-i)))ans-=c[i];
	return ans;
}
struct Tree{int l,r,lz1,lz2;}tr[N*4];
void build(int l,int r,int p,int w){
	tr[p]=(Tree){l,r,0,0};
	if(l==r){
		tr[p].lz2=w;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p*2,w);
	build(mid+1,r,p*2+1,w);
}
void dw(int p){
	tr[p*2].lz1=max(tr[p*2].lz1,tr[p].lz1-tr[p*2].lz2);
	tr[p*2].lz2+=tr[p].lz2;
	tr[p*2+1].lz1=max(tr[p*2+1].lz1,tr[p].lz1-tr[p*2+1].lz2);
	tr[p*2+1].lz2+=tr[p].lz2;
	tr[p].lz1=tr[p].lz2=0;
}
void ins(int L,int R,int p,int w){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].lz2+=w;
		return;
	}
	dw(p);
	int mid=(l+r)>>1;
	if(L<=mid)ins(L,R,p*2,w);
	if(R>mid)ins(L,R,p*2+1,w);
}
void Max(int L,int R,int p,int w){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].lz1=max(tr[p].lz1,w-tr[p].lz2);
		return;
	}
	dw(p);
	int mid=(l+r)>>1;
	if(L<=mid)Max(L,R,p*2,w);
	if(R>mid)Max(L,R,p*2+1,w);
}
int query(int x,int p){
	if(tr[p].l==tr[p].r)return tr[p].lz1+tr[p].lz2;
	int mid=(tr[p].l+tr[p].r)>>1;
	dw(p);
	return query(x,p*2+(x>mid));
}
int main(){
	scanf("%d%d",&n,&d);
	rep(i,n)scanf("%d%d",&s[i],&a[i]);
	rep(i,n){
		pq[i]=(pp){i,s[i]};
		pq[i+n]=(pp){-i,a[i]};
	}
	pq[n+n+1]=(pp){0,d};
	sort(pq+1,pq+n+n+2,cmp);
	pq[0].v=-INF;
	cnt=0;
	int w,pd;
	rep(i,n+n+1){
		if(pq[i].v!=pq[i-1].v)cnt++;
		if(pq[i].x>0)s[pq[i].x]=cnt;
		else if(pq[i].x<0)a[-pq[i].x]=cnt;
		else pd=cnt;
	}
	rep(i,n){
		if(s[i]<a[i]){
			p1[s[i]].push_back((pir){i,s[i],a[i]});
			p2[a[i]].push_back((pir){i,s[i],a[i]});
		}
		else{
			p4[a[i]].push_back((pir){i,s[i],a[i]});
			t[a[i]]=1;
		}
		p3[s[i]].push_back((pir){i,s[i],a[i]});
	}
	for(int i=cnt;i;i--){
		for(int j=0;j<p3[i].size();j++)ins(p3[i][j].a);
		for(int j=0;j<p2[i].size();j++)vl[p2[i][j].x]=check(p2[i][j].s+1,p2[i][j].a);
		if(i==pd)w=check(1,pd);
	}
	build(1,cnt,1,w);
	REP(i,pd+1,cnt){
		for(int j=0;j<p1[i-1].size();j++)da[p1[i-1][j].a]=max(da[p1[i-1][j].a],query(p1[i-1][j].a,1)+vl[p1[i-1][j].x]+1);
		for(int j=0;j<p4[i].size();j++)ins(1,p4[i][j].s,1,1);
		if(p4[i].size())da[i]=max(da[i],query(i,1));
		Max(i,cnt,1,da[i]);
		w=max(w,da[i]);
	}
	printf("%d\n",w);
	return 0;
}