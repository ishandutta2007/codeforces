#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int fac[105],n,a[200005],sum1[105][2],sum2[105],ans;
inline void swp(int &x,int &y){
    int t=x;
    x=y;
    y=t;
    return;
}
inline int getlen(int x){
    int ans=0;
    while(x)ans++,x/=10;
    return ans;
}
inline int work(int x,int a){
    int ans=0;
    while(x)ans+=x%10*a,x/=10,a*=100,a%=mod,ans%=mod;
    return ans;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    fac[0]=1;
    for (int i=1;i<=18;i++)fac[i]=fac[i-1]*10ll;
    sort(a+1,a+1+n);
    for (int i=1;i<=n/2;i++)swp(a[i],a[n-i+1]);
    for (int i=1;i<=n;i++){
        int len=getlen(a[i]);
        for (int j=0;j<len;j++)sum2[j]+=a[i]/fac[j],sum2[j]%=mod;
        for (int j=1;j<=len;j++){
            sum1[j][0]+=work(a[i]%fac[j],10);
            sum1[j][1]+=work(a[i]%fac[j],1);
            sum1[j][0]%=mod,sum1[j][1]%=mod;
        }
        ans+=sum1[len][0]%mod+work(a[i],1)%mod*(i-1)%mod;ans%=mod;
        ans+=sum1[len][1]%mod+work(a[i],10)%mod*(i-1)%mod;ans%=mod;
        ans%=mod;
        ans+=(sum2[len]%mod)*(fac[len*2]%mod)%mod*2%mod;ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}