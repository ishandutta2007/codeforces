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
int n,q;
struct Tree{int l,r,lz,mx,mi;}tr[N*4];
void upd(int p){
	tr[p].mi=min(tr[p*2].lz+tr[p*2].mi,tr[p*2+1].lz+tr[p*2+1].mi);
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
}
void build(int l,int r,int p){
	tr[p]=(Tree){l,r,0,0,0};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
}
void ins(int L,int R,int p){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].lz++;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)ins(L,R,p*2);
	if(R>mid)ins(L,R,p*2+1);
	upd(p);
}
void lzd(int p){
	tr[p].mi+=tr[p].lz;
	tr[p*2].lz+=tr[p].lz;
	tr[p*2+1].lz+=tr[p].lz;
	tr[p].lz=0;
}
int ckmi(int L,int R,int p){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return tr[p].mi+tr[p].lz;
	int mid=(l+r)>>1;
	lzd(p);
	if(L<=mid){
		if(R>mid)return min(ckmi(L,R,p*2),ckmi(L,R,p*2+1));
		return ckmi(L,R,p*2);
	}
	return ckmi(L,R,p*2+1);
}
int ckmx(int L,int R,int p){
	int l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return tr[p].mx;
	int mid=(l+r)>>1;
	if(L<=mid){
		if(R>mid)return max(ckmx(L,R,p*2),ckmx(L,R,p*2+1));
		return ckmx(L,R,p*2);
	}
	return ckmx(L,R,p*2+1);
}
void Max(int x,int v,int p){
	int l=tr[p].l,r=tr[p].r;
	if(l==r){
		tr[p].mx=max(tr[p].mx,v);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)Max(x,v,p*2);
	else Max(x,v,p*2+1);
	upd(p);
}
int main(){
	scanf("%d%d",&n,&q);
	build(1,n,1);
	rep(i,q){
		int t,l,r,x; scanf("%d",&t);
		if(t==0){
			scanf("%d%d%d",&l,&r,&x);
			if(x==0)ins(l,r,1);
			else Max(r,l,1);
		}
		else{
			scanf("%d",&x);
			if(ckmi(x,x,1)>0){
				puts("NO");
				continue;
			}
			int dl,dr;
			if(x==1)dl=0;
			else{
				if(ckmi(1,x-1,1)>0)dl=0;
				else{
					int l=1,r=x;
					while(l<r-1){
						int mid=(l+r)>>1;
						if(ckmi(mid,x-1,1)>0)r=mid;
						else l=mid;
					}
					dl=r-1;
				}
			}
			if(x==n)dr=n+1;
			else{
				if(ckmi(x+1,n,1)>0)dr=n+1;
				else{
					int l=x,r=n;
					while(l<r-1){
						int mid=(l+r)>>1;
						if(ckmi(x+1,mid,1)>0)l=mid;
						else r=mid;
					}
					dr=l+1;
				}
			}
			if(ckmx(x,dr-1,1)>dl)puts("YES");
			else puts("N/A");
		}
	}
	return 0;
}