#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri int
#define ll long long
#define ui unsigned int
const ll MOD=1e9+7;
const ll mod=1e9+7;
il ll read(){
    bool f=true;ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=false;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    if(f) return x;
    return ~(--x);
}
il void write(const ll &x){if(x>9) write(x/10);putchar(x%10+'0');}
il void print(const ll &x) {x<0?putchar('-'),write(~(x-1)):write(x);putchar('\n');}
il ll max(const ll &a,const ll &b){return a>b?a:b;}
il ll min(const ll &a,const ll &b){return a<b?a:b;}
const int MAXN=2e5+7;
int n,q;
ll s1[MAXN],s2[MAXN];
il ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
il ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t){ll res=1;for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}
int main(){
    n=read(),q=read();
    for(ri i=1;i<=n;++i){
        ll x=read();
        s1[i]=(s1[i-1]+x)%MOD;
        s2[i]=(s2[i-1]+x*x)%MOD;
    }
    for(ri i=1;i<=q;++i){
        ll l=read(),r=read(),d=read(),sum1=dec(s1[r],s1[l-1]),sum2=dec(s2[r],s2[l-1]),sz=(r-l+1);
        ll mi=dec(2*sum1*ksm(sz,mod-2)%mod,d*(sz-1)%mod)*ksm(2,mod-2)%mod;
        ll tmp2=sz*mi%mod*mi%mod;
        tmp2=add(tmp2,d*d%mod*(sz-1)%mod*sz%mod*(2*sz-1)%mod*ksm(6,mod-2)%mod)%mod;
        tmp2=add(tmp2,mi*d%mod*sz%mod*(sz-1)%mod)%mod;
        if(tmp2==sum2){
            puts("Yes");
            continue;
        }
        mi=mod-mi;
        tmp2=sz*mi%mod*mi%mod;
        tmp2=add(tmp2,d*d%mod*(sz-1)%mod*sz%mod*(2*sz-1)%mod*ksm(6,mod-2)%mod)%mod;
        tmp2=add(tmp2,mi*d%mod*sz%mod*(sz-1)%mod)%mod;
        if(tmp2==sum2){
            puts("Yes");
            continue;
        }
        puts("No");
    }
}
/*
9 1
17 0 12 6 10 8 2 4 5
2 3 6
2 4 6
4 6 2
2 8 2
1 2 17
1 8 2
9 9 14

*/