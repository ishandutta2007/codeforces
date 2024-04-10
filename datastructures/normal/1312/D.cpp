#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int n,m;
inline int pw(int a,int p){
    if (p==0)return 1;
    int t=pw(a,p/2);
    if (p%2==0)return t%mod*t%mod;
    return t%mod*t%mod*a%mod;
}
inline int inv(int a){
    return pw(a,mod-2)%mod;
}
inline int c(int a,int b){
    int ans=1;
    for (int i=b+1;i<=a;i++)ans*=i,ans%=mod;
    for (int i=1;i<=a-b;i++)ans*=inv(i),ans%=mod;
    return ans;
}
signed main(){
    cin>>n>>m;
    if (n<3){
        cout<<0<<endl;
        return 0;
    }
    cout<<(n-2)*c(m,n-1)%mod*pw(2,n-3)%mod<<endl;
    return 0;
}