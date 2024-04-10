#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7,mod=998244353,mod2=mod*mod;typedef ll aN[N];ll n;char s[N];aN res,t;
inline ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
inline int end(ll i,int ch){return s[i]==ch&&s[i+1]!=ch;}
inline int calc(ll t){
    ll lst=-1,top=0,l=0,x;rep(i,0,n+1)if(end(i,'#'))res[++top]=(lst=i)-l+t;else if(end(i,'_'))x=(l=i)-lst-t,
    top+=x/2-(~x&1)*2,~x&1&&(res[++top]=2);printf("%lld\n",top);rep(i,1,top)printf("%lld ",res[i]?:1);return 0;
}int main(){
    scanf("%s",s+1),n=strlen(s+1);ll lst=-1,f0=1,f1=1,x;s[n+1]=s[0]='_',s[n+2]='#';
    rep(i,0,n+1)if(end(i,'#'))lst=i;else if(end(i,'_'))t[x=i-lst]++,x!=1&&(f0=0),x&1&&(f1=0);
    if(f0)return calc(0);if(f1)return calc(1);rep(i,2,n+3)if(t[i])return puts("-1"),0;else if(!t[i+2])return calc(i);
}