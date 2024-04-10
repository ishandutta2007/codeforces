#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
#define maxn 4000000
using namespace std;
int n,q,fac[4000005],invfac[4000005],inv3;
int f[3000005][3];
int Qpow(int a,int p){
    if (p==0)return 1;
    int t=Qpow(a,p/2);
    t=t*t%mod;
    if (p&1)t=t*a%mod;
    return t;
}
int inv(int a){
    return Qpow(a,mod-2);
}
int C(int n,int m){
    if (m<0||m>n)return 0;
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
signed main(){
    cin>>n>>q;
    inv3=inv(3);
    fac[0]=1;
    for (int i=1;i<=maxn;i++)fac[i]=fac[i-1]*i%mod;
    invfac[maxn]=inv(fac[maxn]);
    for (int i=maxn-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
    f[0][0]=f[0][1]=f[0][2]=n+1;
    for (int i=1;i<=3*n;i++){
        f[i][0]=(((C(3*n+3,i+1)-2*f[i-1][0]-f[i-1][1])%mod+mod)%mod)*inv3%mod;
        f[i][1]=(f[i][0]+f[i-1][0])%mod;
        f[i][2]=(f[i][1]+f[i-1][1])%mod;
    }
    while(q--){
        int x;
        scanf("%lld",&x);
        printf("%lld\n",f[x][0]);
    }
    return 0;
}