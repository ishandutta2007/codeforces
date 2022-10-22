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
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=2e5+7;
const ll INF=1e9+7;
ll n,q;
struct Tree{ll l,r,mi,lz,sm;}tr[N*4];
ll realm(ll p){return (~tr[p].lz)?tr[p].lz:tr[p].mi;}
ll reals(ll p){return (~tr[p].lz)?tr[p].lz*(tr[p].r-tr[p].l+1):tr[p].sm;}
void upd(ll p){
	tr[p].mi=min(realm(p*2),realm(p*2+1));
	tr[p].sm=reals(p*2)+reals(p*2+1);
}
void build(ll l,ll r,ll p){
	tr[p]=(Tree){l,r,0,-1,0};
	if(l==r){
		scanf("%lld",&tr[p].sm);
		tr[p].mi=tr[p].sm;
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	upd(p);
}
ll lzd(ll p){
	if(~tr[p].lz){
		tr[p].mi=realm(p);
		tr[p].sm=reals(p);
		tr[p*2].lz=tr[p].lz;
		tr[p*2+1].lz=tr[p].lz;
		tr[p].lz=-1; 
	}
} 
ll query(ll p,ll x){
	if(tr[p].l==tr[p].r)return tr[p].l;
	lzd(p);
	if(realm(p*2)<x)return query(p*2,x);
	else return query(p*2+1,x);
}
void ins(ll p,ll L,ll R,ll v){
	ll l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r){
		tr[p].lz=v;
		return;
	}
	lzd(p);
	ll mid=(l+r)>>1;
	if(L<=mid)ins(p*2,L,R,v);
	if(R>mid)ins(p*2+1,L,R,v);
	upd(p);
}
ll check(ll p,ll L,ll R){
	ll l=tr[p].l,r=tr[p].r;
	if(L<=l&&R>=r)return reals(p);
	ll mid=(l+r)>>1,ans=0;
	lzd(p);
	if(L<=mid)ans+=check(p*2,L,R);
	if(R>mid)ans+=check(p*2+1,L,R);
	return ans;
}
ll query2(ll p,ll &v){
	ll l=tr[p].l,r=tr[p].r;
	if(l==r)return l;
	lzd(p);
	ll q=reals(p*2);
	if(q>v)return query2(p*2,v);
	v-=q;
	return query2(p*2+1,v);
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	build(1,n,1);
	while(q--){
		ll op,x,y; scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1){
			if(realm(1)>=y)continue;
			ll t=query(1,y);
			if(t>x)continue;
			ins(1,t,x,y);
		}
		else{
			ll ans=0;
			while(1){
				if(realm(1)>y)break;
				ll t=query(1,y+1);
				x=max(x,t);
				ll s=(x>1)?check(1,1,x-1):0;
				if(reals(1)-s<=y){
					ans+=n-x+1;
					break;
				}
				y+=s;
				ll u=query2(1,y);
				ans+=u-x;
				x=u;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}