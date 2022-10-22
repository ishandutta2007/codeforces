#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=216333,m=(1<<20)-1;typedef ll aN[m<<3];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct sgt{
	aN ls,rs,sumor,sumand,sum,tag;ll cnt,rt;sgt(){sumand[0]=m;rt=cnt=1;}
	void pushup(ll u){if(u)sum[u]=sum[ls[u]]+sum[rs[u]],sum[u]=sum[ls[u]]+sum[rs[u]],
	sumor[u]=sumor[ls[u]]|sumor[rs[u]],sumand[u]=sumand[ls[u]]&sumand[rs[u]];}
	void pushdown(ll u,ll l,ll r){//printf("down %lld %lld %lld %lld\n",u,l,r,tag[u]&(r-l));
		if(u&&tag[u]){ll so=sumor[u],sa=sumand[u],tg=tag[u]/*&(r-l)*/;tg&(r-l+1)>>1&&(std::swap(ls[u],rs[u]),0),
		sumor[u]=(so&~tg)|(~sa&tg),sumand[u]=(sa&~tg)|(~so&tg),tag[ls[u]]^=tg,tag[rs[u]]^=tg,tag[u]=0;}
	}void update(ll&u,ll l,ll r,ll q){if(!u)u=++cnt;ll mid=(l+r)>>1;if(l==r){sumand[u]=sumor[u]=q,sum[u]=1;return;}
	if(q<=mid)update(ls[u],l,mid,q);else update(rs[u],mid+1,r,q);pushup(u);}void update(ll q){update(rt,0,m,q);}
	ll split(ll&u,ll l,ll r,ll ql,ll qr){pushdown(u,l,r);if(!u||r<ql||qr<l)return 0;//printf("%lld %lld %lld %lld %lld %lld\n",u,l,r,ql,qr,sum[u]); 
		if(ql<=l&&r<=qr){ll k=u;u=0;return k;}ll mid=(l+r)>>1;ll w=++cnt;
		ls[w]=split(ls[u],l,mid,ql,qr),rs[w]=split(rs[u],mid+1,r,ql,qr),pushup(w),pushup(u);return w;
	}ll split(ll l,ll r){return split(rt,0,m,l,r);}
	void merge(ll&u,ll v,ll l,ll r){pushdown(u,l,r),pushdown(v,l,r);if(!u||!v){u=v^u;return;}
		if(l==r){sumor[u]|=sumor[v],sumand[u]&=sumand[v],sum[u]|=sum[v];return;}//printf("%lld %lld %lld %lld %lld %lld\n",u,v,l,r,sum[u],sum[v]);
		ll mid=(l+r)>>1;merge(ls[u],ls[v],l,mid),merge(rs[u],rs[v],mid+1,r);pushup(u);//printf("=%lld %lld %lld %lld\n",u,l,r,sum[u]);
	}void merge(ll u){merge(rt,u,0,m);}void update_xor(ll u,ll l,ll r,ll x){tag[u]^=x,pushdown(u,l,r);}
	void update_or(ll u,ll l,ll r,ll x){if(!u)return;
		pushdown(u,l,r);if(!(x&(sumor[u]^sumand[u]))){update_xor(u,l,r,x&~sumand[u]);return;}ll mid=(l+r)>>1;
		if(x&(r-l+1)>>1)update_xor(ls[u],l,mid,(r-l+1)>>1),merge(rs[u],ls[u],mid+1,r),ls[u]=0;
		if(l!=r)update_or(ls[u],l,mid,x),update_or(rs[u],mid+1,r,x),pushup(u);
	}void update_and(ll u,ll l,ll r,ll x){if(!u)return;//printf("--%lld %lld %lld %lld %lld %lld\n",u,l,r,x,sumor[u],sumand[u]);
		pushdown(u,l,r);if(!(~x&(sumor[u]^sumand[u]))){update_xor(u,l,r,~x&sumand[u]);return;}ll mid=(l+r)>>1;
		if(~x&(r-l+1)>>1)update_xor(rs[u],mid+1,r,(r-l+1)>>1),merge(ls[u],rs[u],l,mid),rs[u]=0;//printf("====%lld %lld %lld %lld %lld\n",u,l,r,x,sum[u]);
		if(l!=r)update_and(ls[u],l,mid,x),update_and(rs[u],mid+1,r,x),pushup(u);
	}
	#define ss(f) void update_##f(ll u,ll x){update_##f(u,0,m,x);}
	ss(xor)ss(or)ss(and)
}t;
int main(){//IO(no/1515H);
	ll n=rd,q=rd;rep(i,1,n)t.update(rd);rep(i,1,q){ll x=rd,l=rd,r=rd,f=t.split(l,r),s;if(x==4)printf("%lld\n",t.sum[f]);
	else s=rd;if(x==1)t.update_and(f,s);if(x==2)t.update_or(f,s);if(x==3)t.update_xor(f,s);t.merge(f);}return 0;
}
/*
5 7
5 4 3 2 1
4 2 5
1 2 3 2
4 2 5
3 2 5 3
4 1 6
2 1 1 8
4 8 10
*/