#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[200005];
long long S[200005];
long long T[200005];
long long qpow(int x,int y){
    long long t=1;
    for(;y;y>>=1){
        if(y&1)t=1LL*t*x%mod;
        x=1LL*x*x%mod;
    }
    return t;
}
int fac[200005],ifac[200005];
int C(int x,int y){
    if(x<y||y<0)return 0;
    return 1LL*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void work(){
    int n,m=0,k;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    for(i=1;i<=n;++i){
        S[i]=S[i-1]+a[i];
    }
    T[n+1]=0;
    for(i=n;i>=1;--i){
        T[i]=T[i+1]+a[i];
    }
    int j=n,j1;
    int mid;
    int ans=1;
    for(i=1;i<=n;){
        if(i>j)break;
        while(j>=1&&T[j]<S[i])--j;
        if(j>=1 && T[j]==S[i]){
            for(k=i+1;a[k]==0&&k<=n;++k);
            --k;
            for(j1=j-1;a[j1]==0&&j1>0;--j1);
            ++j1;
            if(j1<=k){
                mid = max(0,j-i);
                ans=1LL*ans*qpow(2,mid)%mod;
                break;
            }
            else{
                int A=k-i+1;
                int B=j-j1+1;
                assert(A>=0&&B>=0);
                i=k+1;
                j=j1-1;
                ans=1LL*ans*C(A+B,A)%mod;
            }
        }
        else ++i;
    }
    printf("%d\n",ans);
}
void init(){
    int i;
    fac[0]=1;
    for(i=1;i<=200000;++i)fac[i]=1LL*fac[i-1]*i%mod;
    ifac[200000]=qpow(fac[200000],mod-2);
    for(i=200000-1;i>=0;--i)ifac[i]=1LL*(i+1)*ifac[i+1]%mod;
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}