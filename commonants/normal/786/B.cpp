#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const LL MX=100011,inf=0x3f3f3f3f3f3f3f3fLL;
struct P{LL f,tg;LL p,d;};
P mn[MX<<2];
struct E{LL t,w;E(LL _t=0,LL _w=0):t(_t),w(_w){}}e[MX];int cnt;
struct E2{LL l,r,w;E2(LL _l=0,LL _r=0,LL _w=0):l(_l),r(_r),w(_w){}};
vector<E>t[MX];
vector<E2>t2[MX];
vector<int>tg[MX<<2];
int vis[MX];
LL n,q,s;

void ins(LL no,LL l,LL r,LL ll,LL rr,int x){
	if(ll<=l&&rr>=r)tg[no].push_back(x);
	else{
		LL mid=(l+r)>>1;
		if(ll<=mid)ins(no<<1,l,mid,ll,rr,x);
		if(rr>mid)ins(no<<1|1,mid+1,r,ll,rr,x);
	}
}
void build(LL no,LL l,LL r){
	mn[no].f=mn[no].tg=inf;
	if(l==r)mn[no].p=l;
	else{
		LL mid=(l+r)>>1;
		build(no<<1,l,mid);
		build(no<<1|1,mid+1,r);
		if(mn[no<<1|1].d||(!mn[no<<1].d&&mn[no<<1].f<mn[no<<1|1].f))
		mn[no].f=mn[no<<1].f,mn[no].p=mn[no<<1].p,mn[no].d=mn[no<<1].d;
		else mn[no].f=mn[no<<1|1].f,mn[no].p=mn[no<<1|1].p,mn[no].d=mn[no<<1|1].d;
	}
}
void psdw(LL no){
	if(mn[no].tg!=inf){
		mn[no<<1].tg=min(mn[no<<1].tg,mn[no].tg);
		mn[no<<1|1].tg=min(mn[no<<1|1].tg,mn[no].tg);
		mn[no<<1].f=min(mn[no<<1].f,mn[no].tg);
		mn[no<<1|1].f=min(mn[no<<1|1].f,mn[no].tg);
		mn[no].tg=inf;
	}
}
void upd(LL no,LL l,LL r,LL x,LL v){
	if(mn[no].d)return;
	if(l==r)mn[no].f=min(mn[no].f,v);
	else{
		psdw(no);
		LL mid=(l+r)>>1;
		if(x<=mid)upd(no<<1,l,mid,x,v);
		else upd(no<<1|1,mid+1,r,x,v);
		if(mn[no<<1|1].d||(!mn[no<<1].d&&mn[no<<1].f<mn[no<<1|1].f))
		mn[no].f=mn[no<<1].f,mn[no].p=mn[no<<1].p,mn[no].d=mn[no<<1].d;
		else mn[no].f=mn[no<<1|1].f,mn[no].p=mn[no<<1|1].p,mn[no].d=mn[no<<1|1].d;
	}
}
void upd(LL no,LL l,LL r,LL ll,LL rr,LL v){
	if(mn[no].d)return;
	if(ll<=l&&rr>=r)mn[no].f=min(mn[no].f,v),mn[no].tg=min(mn[no].tg,v);
	else{
		psdw(no);
		LL mid=(l+r)>>1;
		if(ll<=mid)upd(no<<1,l,mid,ll,rr,v);
		if(rr>mid)upd(no<<1|1,mid+1,r,ll,rr,v);
		if(mn[no<<1|1].d||(!mn[no<<1].d&&mn[no<<1].f<mn[no<<1|1].f))
		mn[no].f=mn[no<<1].f,mn[no].p=mn[no<<1].p,mn[no].d=mn[no<<1].d;
		else mn[no].f=mn[no<<1|1].f,mn[no].p=mn[no<<1|1].p,mn[no].d=mn[no<<1|1].d;
	}
}
void del(LL no,LL l,LL r,LL x){
	if(l==r)mn[no].d=1;
	else{
		psdw(no);
		LL mid=(l+r)>>1;
		if(x<=mid)del(no<<1,l,mid,x);
		else del(no<<1|1,mid+1,r,x);
		if(mn[no<<1|1].d||(!mn[no<<1].d&&mn[no<<1].f<mn[no<<1|1].f))
		mn[no].f=mn[no<<1].f,mn[no].p=mn[no<<1].p,mn[no].d=mn[no<<1].d;
		else mn[no].f=mn[no<<1|1].f,mn[no].p=mn[no<<1|1].p,mn[no].d=mn[no<<1|1].d;
	}
}
void upd2(LL no,LL l,LL r,LL x,LL f){
	for(vector<int>::iterator it=tg[no].begin();it!=tg[no].end();it++){
		if(!vis[*it]){vis[*it]=1,upd(1,1,n,e[*it].t,f+e[*it].w);}
	}
	tg[no].clear();
	if(l==r)return;
	LL mid=(l+r)>>1;
	if(x<=mid)upd2(no<<1,l,mid,x,f);
	else upd2(no<<1|1,mid+1,r,x,f);
}
void dij(LL S){
	build(1,1,n);
	upd(1,1,n,S,0);
	for(LL i=1;i<n;i++){
		LL k=mn[1].p;LL f=mn[1].f;
		del(1,1,n,k);
		for(vector<E>::iterator it=t[k].begin();it!=t[k].end();it++){
			upd(1,1,n,it->t,f+it->w);
		}
		for(vector<E2>::iterator it=t2[k].begin();it!=t2[k].end();it++){
			upd(1,1,n,it->l,it->r,f+it->w);
		}
		upd2(1,1,n,k,f);
	}
}
void outp(LL no,LL l,LL r){
	if(l==r)printf("%lld ",mn[no].f==inf?-1:mn[no].f);
	else{
		psdw(no);
		LL mid=(l+r)>>1;
		outp(no<<1,l,mid);
		outp(no<<1|1,mid+1,r);
	}
}
int main(){
	scanf("%lld%lld%lld",&n,&q,&s);
	for(LL i=1;i<=q;i++){
		LL typ;scanf("%lld",&typ);
		if(typ==1){
			LL v,u,w;scanf("%lld%lld%lld",&v,&u,&w);
			t[v].push_back(E(u,w));
		}else if(typ==2){
			LL v,l,r,w;scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			t2[v].push_back(E2(l,r,w));
		}else {
			LL v,l,r,w;scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			int no=++cnt;e[no]=E(v,w);
			ins(1,1,n,l,r,no);
		}
	}
	dij(s);outp(1,1,n);
	return 0;
}