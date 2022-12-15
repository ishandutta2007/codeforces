#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
long long mod=1e9+7;
int n;
struct fenwick{
    long long tree[200005],base;
    void add(int x,long long v){
        v%=mod;
        if(!x) base+=v,base%=mod;
        if(!x||x>n) return;
        while(x<=n) tree[x]+=v,tree[x]%=mod,x+=x&-x;
    }
    long long query(int x){
        long long ans=0;
        while(x) ans+=tree[x],ans%=mod,x-=x&-x;
        return (ans+base)%mod;
    }
}num,fac;
long long a[200005],b[200005];
long long suf[200005],pre[200005],p[200005],ans[200005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]),pre[i]=pre[i-1]+b[i];
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+b[i],p[i]=suf[i];
        sort(p+1,p+n+1);
        //for(int i=1;i<=n;i++) cout<<p[i]<<" ";puts("");
        for(int i=1;i<=n;i++){
            if(b[i]>0){
                int p1=upper_bound(p+1,p+n+1,-b[i]+pre[n]-pre[i-1])-p-1,p2=upper_bound(p+1,p+n+1,0+pre[n]-pre[i-1])-p-1;
                //cout<<p1<<" "<<p2<<endl;
                num.add(1,a[i]*b[i]),num.add(p1+1,-a[i]*b[i]);
                num.add(p2+1,-a[i]*b[i]);
                fac.add(p1+1,-2*a[i]),num.add(p1+1,-b[i]*a[i]),num.add(p1+1,2*(pre[n]-pre[i-1])%mod*a[i]);
                fac.add(p2+1,2*a[i]),num.add(p2+1,b[i]*a[i]),num.add(p2+1,2*(pre[i-1]-pre[n])%mod*a[i]);
            }
            else{
                int p1=upper_bound(p+1,p+n+1,0+pre[n]-pre[i-1])-p-1,p2=upper_bound(p+1,p+n+1,-b[i]+pre[n]-pre[i-1])-p-1;
                //cout<<p1<<" "<<p2<<endl;
                num.add(1,a[i]*b[i]),num.add(p1+1,-a[i]*b[i]);
                num.add(p2+1,-a[i]*b[i]);
                fac.add(p1+1,2*a[i]),num.add(p1+1,b[i]*a[i]),num.add(p1+1,-2*(pre[n]-pre[i-1])%mod*a[i]);
                fac.add(p2+1,-2*a[i]),num.add(p2+1,-b[i]*a[i]),num.add(p2+1,2*(pre[n]-pre[i-1])%mod*a[i]);
            }
        }
        //for(int i=1;i<=n;i++) cout<<p[i]<<endl;
        for(int i=1;i<=n;i++){
            int pos=lower_bound(p+1,p+n+1,suf[i])-p;
            ans[i]=((num.query(pos)+fac.query(pos)*(suf[i]%mod)%mod)%mod+mod)%mod;
            //cout<<i<<" "<<pos<<" "<<suf[i]<<endl;
            if(b[i]>0){
                int p1=upper_bound(p+1,p+n+1,-b[i]+pre[n]-pre[i-1])-p-1,p2=upper_bound(p+1,p+n+1,0+pre[n]-pre[i-1])-p-1;
                num.add(1,-a[i]*b[i]),num.add(p1+1,a[i]*b[i]);
                num.add(p2+1,a[i]*b[i]);
                fac.add(p1+1,2*a[i]),num.add(p1+1,b[i]*a[i]),num.add(p1+1,-2*(pre[n]-pre[i-1])%mod*a[i]);
                fac.add(p2+1,-2*a[i]),num.add(p2+1,-b[i]*a[i]),num.add(p2+1,-2*(pre[i-1]-pre[n])%mod*a[i]);
            }
            else{
                int p1=upper_bound(p+1,p+n+1,0+pre[n]-pre[i-1])-p-1,p2=upper_bound(p+1,p+n+1,-b[i]+pre[n]-pre[i-1])-p-1;
                num.add(1,-a[i]*b[i]),num.add(p1+1,a[i]*b[i]);
                num.add(p2+1,a[i]*b[i]);
                fac.add(p1+1,-2*a[i]),num.add(p1+1,-b[i]*a[i]),num.add(p1+1,2*(pre[n]-pre[i-1])%mod*a[i]);
                fac.add(p2+1,2*a[i]),num.add(p2+1,b[i]*a[i]),num.add(p2+1,-2*(pre[n]-pre[i-1])%mod*a[i]);
            }
            //cout<<i<<" "<<ans[i]<<endl;
        }
        for(int i=1,l,r;i<=q;i++){
            scanf("%d%d",&l,&r);
            printf("%lld\n",(ans[l]-ans[r+1]+mod)%mod);
        }
    }
    return 0;
}