#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
typedef long long ll;typedef long double ld;const ll inf=0x3f3f3f3f3f3f3f3f,N=31111;
const ld pi=acos(-1);
ll readll(void){
    ll x=0,w=1;char ch=getchar();for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
    for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());return x*w;
}
inline int readchar(void){
    int ch=getchar();for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());return ch;
}
struct nd{
    ll g,x,t,id;void read(ll id_){g=readll(),x=readll(),t=readll(),id=id_;}
    ll tm()const{return x-t;}int operator<(const nd&b)const{ll t1=tm(),t2=b.tm();
    return t1==t2?g==b.g?g==1?x<b.x:x>b.x:g>b.g:t1<t2;}
}s[1145141];ll ans[1145141];
int main(void){
    ll n=readll(),w=readll(),h=readll(),lst=1;
    rep(i,1,n)s[i].read(i);std::sort(s+1,s+n+1);
    rep(i,1,n){
        if(i==n||s[i].tm()!=s[i+1].tm()){
            ll cnt=0;
            rep(j,lst,i)cnt+=s[j].g==2;
            rep(j,lst,i)ans[s[j].id]=(j+cnt)>i?j+cnt-(i+1-lst):j+cnt;
            lst=i+1;
        }
    }
    rep(i,1,n)printf("%lld %lld\n",s[ans[i]].g==1?s[ans[i]].x:w,s[ans[i]].g==1?h:s[ans[i]].x);
    return 0;
}//,printf("%lld ",(j+cnt)>i?j+cnt-(i+1-lst):j+cnt);puts("");
//            printf("s=%lld %lld %lld %lld %lld\n",lst,i,s[i].tm(),s[i+1].tm(),(ll)(s[i]<s[i+1]));