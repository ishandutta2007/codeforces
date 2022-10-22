#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n,qu;
int a[N+1];
struct segtree{
	struct node{int l,r,lz;}nd[N<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=n,int p=1){
		l(p)=l;r(p)=r;lz(p)=0;
		if(l==r){lz(p)=a[l];return;}
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p))lz(p<<1)=max(lz(p<<1),lz(p)),lz(p<<1|1)=max(lz(p<<1|1),lz(p)),lz(p)=0;
	}
	void chg_b(int x,int v,int p=1){
		if(l(p)==r(p)){lz(p)=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		chg_b(x,v,p<<1|(x>mid));
	}
	void chg_m(int v){lz(1)=max(lz(1),v);}
	int ask(int x,int p=1){
		if(l(p)==r(p))return lz(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		return ask(x,p<<1|(x>mid));
	}
}segt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	segt.init();
	scanf("%d",&qu);
	while(qu--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if(tp==1)scanf("%d",&y),segt.chg_b(x,y);
		else segt.chg_m(x);
	}
	for(int i=1;i<=n;i++)printf("%d ",segt.ask(i));
	return 0;
}