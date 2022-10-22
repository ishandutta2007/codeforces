#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
bool p1;
typedef long long ll;typedef long double ld;const ll N=1<<17,Q=2e5+7,K=N,V=42;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct limit{ll hil,hir,lol,lor,v;}lim[Q*3];aN hi,lo,ahi,alo;
int main(){
    const ll k=readll(),q=readll(),mk=(1<<k)-1;ll l,r,v,cnt=0;const limit no={0,0,0,0,0};
    rep(i,1,q)l=readll(),r=readll(),v=readll(),(l>>k)!=(r>>k)?
    (r>>k)-1>(l>>k)?lim[++cnt]=(limit){(l>>k)+1,(r>>k)-1,0,mk,v}:no,
    lim[++cnt]=(limit){l>>k,l>>k,l&mk,mk,v},lim[++cnt]=(limit){r>>k,r>>k,0,r&mk,v}:
    lim[++cnt]=(limit){l>>k,r>>k,l&mk,r&mk,v};
//    rep(i,1,cnt)printf("%lld %lld %lld %lld %lld\n",lim[i].hil,lim[i].hir,lim[i].lol,lim[i].lor,lim[i].v);
    ref(w,0,16){
        memset(hi,0,sizeof(ll)<<k),memset(lo,0,sizeof(ll)<<k);
        rep(i,1,cnt)(lim[i].v>>w&1)&&(hi[lim[i].hil]++,hi[lim[i].hir+1]--,lo[lim[i].lol]++,lo[lim[i].lor+1]--);
        rep(i,1,mk)hi[i]+=hi[i-1],lo[i]+=lo[i-1];rep(i,0,mk)ahi[i]|=!!hi[i]<<w,alo[i]|=!!lo[i]<<w;
        rep(i,1,mk)hi[i]+=hi[i-1],lo[i]+=lo[i-1];
        rep(i,1,cnt)if(!(lim[i].v>>w&1))if((hi[lim[i].hir]-hi[lim[i].hil-1])&&(lo[lim[i].lor]-lo[lim[i].lol-1]))
        return puts("impossible"),0;
    }puts("possible");rep(i,0,mk)printf("%lld\n",alo[i]);rep(i,0,mk)printf("%lld\n",ahi[i]);
    return 0;
}
/*
for every l<=i<=r A[hb(i)]&B[lb(i)]=v
A[hb(i)]&B[lb(i)]=v
A[hb(i)]|=v,B[lb(i)]|=v
for every l<=i,hb(i)<=hb(l),i<=r A[hb(l)]&B[lb(i)]&~v=0
for every hb(r)<=hb(i),i<=r,i>=l A[hb(r)]&B[lb(i)]&~v=0
(A[s]&B[lb(x)]&~v)|...|(A[s]&B[lb(y)]&~v)=0
(A[s]&~v)&(B[lb(x)|...|B[hb(y)])=0
for every hb(l)<hb(i)<hb(r) A[hb(i)]&B[lb(i)]&~v=0
for every hb(l)<h<hb(r),0<=l<=2^k-1 A[h]&B[l]&~v=0
(A[x]|...|A[y])&((B[0]|...|B[2^k-1])&~v)=0
*/