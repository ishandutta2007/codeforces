#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
long long mul[800005];
long long p[200005],ip[200005];
long long multi[800005],sum[800005],add[800005],a[800005];
void pushup(ll rt)
{
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%mod;
}
void build(ll l,ll r,ll rt)
{
    mul[rt]=1;
    if(l==r)
    {
        sum[rt]=a[l];
        sum[rt]%=mod;
        return;
    }
    ll m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(ll l,ll r,ll rt)
{
    ll m=(l+r)>>1;
    sum[rt<<1]=(sum[rt<<1]*mul[rt]+add[rt]*(m-l+1))%mod;
    sum[rt<<1|1]=(sum[rt<<1|1]*mul[rt]+add[rt]*(r-m))%mod;
    //lazy
    mul[rt<<1]=(mul[rt<<1]*mul[rt])%mod;
    mul[rt<<1|1]=(mul[rt<<1|1]*mul[rt])%mod;
    add[rt<<1]=(add[rt<<1]*mul[rt]+add[rt])%mod;
    add[rt<<1|1]=(add[rt<<1|1]*mul[rt]+add[rt])%mod;
    //lazy
    mul[rt]=1;
    add[rt]=0;
}
void update1(ll L,ll R,ll k,ll l,ll r,ll rt)//
{
    if (L <= l && r <= R) {
        sum[rt] = (sum[rt] * k) % mod;
        mul[rt] = (mul[rt] * k) % mod;
        add[rt] = (add[rt] * k) % mod;
        return;
    }
    pushdown(l, r, rt);
    ll m = (l + r) >> 1;
    if (L <= m) update1(L, R, k, lson);
    if (R > m) update1(L, R, k, rson);
    pushup(rt);
    return;
}
ll query(ll L,ll R,ll l,ll r,ll rt) {
    if (L <= l && r <= R)
        return sum[rt];
    ll m = (l + r) >> 1;
    pushdown(l, r, rt);
    ll ans = 0;
    if (L <= m) ans = (ans + query(L, R, lson)) % mod;
    if (R > m) ans = (ans + query(L, R, rson)) % mod;
    return ans;
}
set <int> s;
int f[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]),ip[i]=qpow(p[i],mod-2)*100%mod;
        multi[0]=1;
        for(int i=1;i<=n;i++) multi[i]=multi[i-1]*ip[i]%mod;
        for(int i=n;i>=1;i--) a[i]=multi[n]*qpow(multi[i-1],mod-2)%mod;
        build(1,n,1);
        s.insert(1);
        s.insert(n+1);
        for(int i=1;i<=q;i++){
            int x;
            scanf("%d",&x);
            if(!f[x]) s.insert(x);
            set<int>::iterator it=s.lower_bound(x);
            int pre=*(--it);
            ++it;
            int suf=*(++it);
            if(!f[x]){
                update1(pre,x-1,qpow(multi[suf-1]*qpow(multi[x-1],mod-2)%mod,mod-2),1,n,1);
                //cout<<mul[suf-1]<<" "<<mul[x-1]<<" "<<suf-1<<endl;
            }
            else update1(pre,x-1,multi[suf-1]*qpow(multi[x-1],mod-2)%mod,1,n,1);
            f[x]^=1;
            if(!f[x]) s.erase(x);
            printf("%lld\n",query(1,n,1,n,1));
        }
    }
    return 0;
}