#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,ans;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main(){
    cin>>n;ans=n;
    for(int i=2;1ll*i*i<=n;i++)if(n%i==0){
        ans=gcd(ans,i);
        ans=gcd(ans,n/i);
    }
    cout<<ans;
    return 0;
}