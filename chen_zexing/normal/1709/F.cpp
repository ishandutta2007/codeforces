#pragma GCC optimize("Ofast,unroll-loops")
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
const int G=3,mod=998244353;
int rev[1000005];
int qpow(int a,int b,int mod){
    int ans=1%mod;a%=mod;
    while(b){
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
void ntt(int a[],int len,int on){
    for(int i=0;i<len;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int i=1;i<len;i<<=1){
        int wn=qpow(G,(mod-1)/(i<<1),mod);
        if(on==-1)wn=qpow(wn,mod-2,mod);
        for(int j=0;j<len;j+=(i<<1)){
            int w=1;
            for(int k=0;k<i;k++){
                int x=a[j+k],y=1ll*w*a[i+j+k]%mod;
                a[j+k]=((1ll*x+y)%mod+mod)%mod;
                a[i+j+k]=(1ll*x-y+mod)%mod;
                w=1ll*w*wn%mod;
            }
        }
    }
    if(on==-1){
        int inv=qpow(len,mod-2,mod);
        for(int i=0;i<len;i++)a[i]=1ll*a[i]*inv%mod;
    }
}
int a[1000005],b[1000005],pre[1000005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,k,f;
        cin>>n>>k>>f;
        if(k*2<f){
            puts("0");
            continue;
        }
        int len=1,l=0;
        while(len<=k*2) len<<=1,l++;
        for(int i=0;i<len;i++){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
        }
        for(int i=1;i<=n;i++){
            if(i==1){
                for(int j=0;j<=k;j++) a[j]=pre[j]=1;
            }
            else{
                for(int j=0;j<=k;j++) a[j]=b[j]=pre[j];
                for(int j=k+1;j<len;j++) a[j]=b[j]=0;
                ntt(a,len,1);
                ntt(b,len,1);
                for(int j=0;j<len;j++) a[j]=1LL*a[j]*b[j]%mod;
                ntt(a,len,-1);
                for(int j=0;j<=k;j++) pre[j]=1LL*a[j]*(k-j)%mod;
                long long suf=0;
                for(int j=len-1;j>k;j--) suf+=a[j],suf%=mod;
                for(int j=k;j>=0;j--) suf+=a[j],suf%=mod,pre[j]+=suf,pre[j]%=mod;
            }
        }
        long long ans=0;
        for(int i=0;i<=f;i++) ans+=1LL*pre[i]*pre[f-i]%mod,ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map
//cf