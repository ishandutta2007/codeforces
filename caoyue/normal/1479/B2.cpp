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
int n;
int a[N];
struct Tree{int l,r,lz,mi;}tr[N*4];
int real(int p){return tr[p].mi+tr[p].lz;}
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,0,2};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
void upd(int p){tr[p].mi=min(real(p*2),real(p*2+1));}
void lzd(int p){
	if(!tr[p].lz)return;
	tr[p].mi=real(p);
	tr[p*2].lz+=tr[p].lz;
	tr[p*2+1].lz+=tr[p].lz;
	tr[p].lz=0;
}
int query(int p,int x){
	int l=tr[p].l,r=tr[p].r;
	if(tr[p].l==tr[p].r)return real(p);
	int mid=(l+r)>>1;
	lzd(p);
	return query(p*2+(x>mid),x);
}
void ins(int p,int x,int v){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		tr[p].mi=real(p);
		tr[p].lz=0;
		tr[p].mi=min(tr[p].mi,v);
		return;
	}
	int mid=(l+r)>>1;
	lzd(p);
	ins(p*2+(x>mid),x,v);
	upd(p);
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int Ans=1;
	rep(i,n-1)Ans+=(a[i]!=a[i+1]);
	build(1,n,1);
	REP(i,2,n){
		int u=query(1,a[i]);
		int h=min(real(1)+1,u);
		tr[1].lz+=(a[i]!=a[i-1]);
		ins(1,a[i],u);
		ins(1,a[i-1],h);
	}
	printf("%d\n",min(real(1),Ans));
	return 0;
}