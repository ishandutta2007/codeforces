#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=4e5+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct ds1{ll val[N<<2],n;void set(ll n_){n=n_;}
	void update(ll u,ll l,ll r,ll q,ll x){
		if(l==r){val[u]=x;return;}ll mid=(l+r)>>1;if(q<=mid)update(u<<1,l,mid,q,x);
		if(q>mid)update(u<<1|1,mid+1,r,q,x);val[u]=std::min(val[u<<1],val[u<<1|1]);
	}void update(ll x,ll q){update(1,0,n,q,x);}
	ll query(ll u,ll l,ll r,ll ql,ll qr)const{if(ql<=l&&r<=qr)return val[u];ll mid=(l+r)>>1;
		return std::min(ql<=mid?query(u<<1,l,mid,ql,qr):inf,qr>=mid+1?query(u<<1|1,mid+1,r,ql,qr):inf); 
	}ll query(ll q)const{return q?query(1,0,n,0,q-1):inf;}
	ll mex(ll u,ll l,ll r,ll q)const{
		ll mid=(l+r)>>1;if(l==r)return l;return val[u<<1]>=q?mex(u<<1|1,mid+1,r,q):mex(u<<1,l,mid,q);
	}ll mex(ll q)const{return q?mex(1,0,n,q):inf;}void print(ll s)const{rep(i,1,s)printf("%lld ",mex(i));puts("");}
}t1;
struct ds2{ll n,cnt;
	struct ts{ll t,r;operator ll(){return t;}};std::vector<ts>se[N<<2];
	void set(ll n_){n=n_,cnt=0;rep(i,0,n)se[i].push_back((ts){0,0});}
	struct ifm{ll v1,v2;friend ifm operator+(const ifm&a,const ifm&b){return(ifm){a.v1+b.v1,a.v2+b.v2};}};
	struct node{ifm val;ll t1,t2,ls,rs;void add(ll s,ll c1,ll c2){t1+=c1,val.v1+=c1*s,t2+=c2,val.v2+=c2*s;}}sgm[N<<5];
	void update(ll&u,ll v,ll l,ll r,ll ql,ll qr,ll c1,ll c2){
		sgm[u=++cnt]=sgm[v];ll mid=(l+r)>>1;if(ql<=l&&r<=qr){sgm[u].add(r-l+1,c1,c2);return;}
		if(ql<=mid)update(sgm[u].ls,sgm[v].ls,l,mid,ql,qr,c1,c2);
		if(qr>=mid+1)update(sgm[u].rs,sgm[v].rs,mid+1,r,ql,qr,c1,c2);
		sgm[u].val=sgm[sgm[u].ls].val+sgm[sgm[u].rs].val;
	}void update(ll u,ll t,ll l,ll r,ll c){//printf(">%lld %lld %lld %lld %lld\n",u,t,l,r,c);
		ll lst=(se[u].end()-1)->r,root;update(root,lst,1,n,l,r,c,-c*t),se[u].push_back((ts){t,root});
	}ifm query(ll u,ll l,ll r,ll ql,ll qr)const{
		ll mid=(l+r)>>1,t=std::min(qr,r)-std::max(ql,l)+1;if(!u||t<0)return(ifm){0,0};if(ql<=l&&r<=qr)return sgm[u].val;
		return(ifm){sgm[u].t1*t,sgm[u].t2*t}+query(sgm[u].ls,l,mid,ql,qr)+query(sgm[u].rs,mid+1,r,ql,qr);
	}ll query(ll u,ll l,ll r){
		ifm res=query((std::upper_bound(se[u].begin(),se[u].end(),r)-1)->r,1,n,l,r);return res.v1*(r+1)+res.v2;
	}
}t2;void insert(ll w,ll x){
	ll l=t1.query(x+1)+1,r=std::min(t1.query(x),w-1),tr,lst;t1.update(w,x),lst=t1.mex(r);if(l<=r)t2.update(x,w,l,r,-1);
	while(l<=r){tr=t1.query(lst+1),t2.update(lst,w,std::max(tr+1,l),r,1),lst=t1.mex(r=tr);}t2.update(!x,w,w,w,1);
}ll calc(ll w,ll a,ll l,ll r,ll k){insert(w,a);return t2.query(k,l,r);}
int main(){
	ll n=readll(),a,l,r,x,ans=0;t1.set(n+3),t2.set(n+3);
	rep(i,1,n)a=(readll()+ans)%(n+1),l=(readll()+ans)%i+1,r=(readll()+ans)%i+1,
	x=(readll()+ans)%(n+1),(l>r)&&(std::swap(l,r),0),printf("%lld\n",ans=calc(i,a,l,r,x));return 0;
}