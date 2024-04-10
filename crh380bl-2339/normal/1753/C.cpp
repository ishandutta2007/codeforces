#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[500005];
long long qpow(long long x,int y){
    long long t=1;
    for(;y;y>>=1){
        if(y&1)t=t*x%mod;
        x=x*x%mod;
    }
    return t;
}
void work(){
    int n,i,s=0,s1=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    for(i=1;i<=n-s;++i)s1+=a[i];
    long long C=1LL*n*(n-1)/2, ans=0;
    for(i=1;i<=s1;++i){
        ans += qpow(1LL*i*i, mod-2);
        ans%=mod;
    }
    ans=ans*C%mod;
    printf("%d\n",ans);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}