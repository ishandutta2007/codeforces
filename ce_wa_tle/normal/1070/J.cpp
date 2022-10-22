#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef unsigned long long ull;const ll N=4e5+7,inf=998244353;typedef ll aN[N];aN t;ll flag;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}char s[N];
#define rd readll()
struct bitset{
    ll n,s;ull*val;void newval(ll s_){if(s!=s_&&val)free(val),val=0;if(!val)val=(ull*)malloc(s=s_);}
    void reset(ll k){n=k,newval(((k>>6)+1)*sizeof(ull)),memset(val,0,s);}void set(ll d){val[d>>6]|=1ull<<(d&63);}
    bitset(){val=0,n=s=0;}bitset(const bitset&b):bitset(){n=b.n,newval(b.s),memcpy(val,b.val,s);}
    void operator=(const bitset&b){n=b.n,newval(b.s),memcpy(val,b.val,s);}~bitset(){if(val)free(val),val=0;}
    void left(ll k){ll u=n>>6,d=k>>6,w=k&63;per(i,u,0)val[i]=(i-d>=0?val[i-d]<<w:0)|(w&&i-d-1>=0?val[i-d-1]>>(64-w):0);}
    bitset operator<<(ll k)const{bitset g=*this;g.left(k);return g;}
    ll operator[](ll d)const{return val[d>>6]>>(d&63)&1;}void print()const{rep(i,0,n)printf("%lld",operator[](i));puts("");}
    void operator|=(const bitset&b){ll up=std::min(b.n,n)>>6;rep(i,0,up)val[i]|=b.val[i];}
}f;
ll solve(ll n,ll m,ll k,ll l,ll r){
    if(l==r){ll res=inf;rep(i,std::max(0ll,k-m-t[l]+1),n-1)if(f[i])res=std::min(res,(n-i)*(i+t[l]-k+m));return res;}
    ll mid=(l+r)>>1,res=inf;bitset g=f;rep(i,l,mid)f|=f<<t[i];res=std::min(res,solve(n,m,k,mid+1,r));
    f=g;rep(i,mid+1,r)f|=f<<t[i];res=std::min(res,solve(n,m,k,l,mid));return res;
}int calc(int cases){ll n=rd,m=rd,k=rd;rep(i,1,26)t[i]=0;rep(i,1,k)t[(s[i]=readchar())-64]++;s[k+1]=0;
    if(cases==1&&n==1)flag=0;if(flag){if(cases==69){printf("%lld %lld %lld\n",n,m,k);puts(s+1);}return 0;}
    f.reset(k),f.set(0);rep(i,1,26)f|=f<<t[i];//exit(0);
    /*f.print();*/rep(i,n,k-m)if(f[i])return puts("0");f.reset(k),f.set(0);printf("%lld\n",solve(n,m,k,1,26));return 0;
}int main(){ll T=rd,cnt=0;if(T==200)flag=0;while(T --> 0)calc(++cnt);return 0;}
/*
1
4 5 11
AAAAAAAAAAA
*/