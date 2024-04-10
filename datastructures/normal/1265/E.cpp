#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
inline int pw(int a,int p){
    if (p==0)return 1;
    int t=pw(a,p/2);
    t=t*t%mod;
    if (p%2==1)t=t*a%mod;
    return t;
}
inline int inv(int a){
    return pw(a,mod-2);
}
int n,p[200005],f[200005];
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%lld",&p[i]);
        f[i]=(f[i-1]+1)*100%mod*inv(p[i])%mod;
    }
    cout<<f[n]<<endl;
    return 0;
}