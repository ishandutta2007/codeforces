#pragma GCC optimize(3)
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
#include <bitset>
using namespace std;
int a[200005],b[200005],c[200005],p[200005];
long long mod=998244353,fac[200005],inv[200005];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long C(int a,int b){
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int aa[200005],bb[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=-1;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),c[a[i]]=b[i];
        fac[0]=inv[0]=1;
        for(int i=1;i<=n;i++){
            if(c[i]!=-1) p[c[i]]=i;
            fac[i]=fac[i-1]*i%mod,inv[i]=qpow(fac[i],mod-2);
        }
        long long ans=1,x=0,y=0;
        for(int i=1;i<=n;i++){
            if(p[i]==-1) aa[++x]=i;
            if(c[i]==-1) bb[++y]=i;
            if(p[i]!=-1&&p[i]-i>k) ans=0;
        }
        if(ans==0){
            puts("0");
            continue;
        }
        //for(int i=1;i<=x;i++) cout<<aa[i]<<" ";puts("");
        //for(int i=1;i<=x;i++) cout<<bb[i]<<" ";puts("");
        int cnt=0;
        for(int i=1;i<=x;i++){
            while(cnt<x&&bb[cnt+1]<=aa[i]+k) cnt++;
            ans*=cnt-i+1,ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//cf