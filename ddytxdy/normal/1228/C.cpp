#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=1e9+7;
int x,ans=1;LL n;
int power(int x,LL y){
    int ret=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)ret=1ll*ret*x%mod;
    return ret;
}
int main(){
    cin>>x>>n;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i)continue;
        for(LL j=i;j<=n;j*=i){
            ans=1ll*ans*power(i,n/j)%mod;
            if(1.0L*j*i>n)break;
        }
        while(x%i==0)x/=i;
    }
    if(x!=1)for(LL j=x;j<=n;j*=x){
        ans=1ll*ans*power(x,n/j)%mod;
        if(1.0L*j*x>n)break;
    }
    cout<<ans;
    return 0;
}