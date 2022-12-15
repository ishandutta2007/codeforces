#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long st[2005][2005],mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    st[1][1]=1;
    for(int i=2;i<=2000;i++)
        for(int j=1;j<=i;j++)
            st[i][j]=(st[i-1][j]*j+st[i-1][j-1])%mod;
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m,k,a,b;
        long long ans=0,tmp=1;
        cin>>n>>m>>k;
        a=(m+1)/2,b=m/2;
        long long aa=1,bb=qpow(m,n),ivm=qpow(m,mod-2);
        for(int i=1;i<=min(n,k);i++){
            tmp*=n-i+1,tmp%=mod,aa=aa*a%mod,bb=bb*ivm%mod;
            ans+=st[k][i]*tmp%mod*aa%mod*bb%mod;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}