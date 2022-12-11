#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t;LL a,m;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL phi(LL n){
    LL ans=n;
    for(int i=2;1ll*i*i<=n;i++)if(n%i==0){
        ans=ans/i*(i-1);
        while(n%i==0)n/=i;
    }
    if(n!=1)ans=ans/n*(n-1);
    return ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>a>>m;
        cout<<phi(m/gcd(m,a))<<endl;
    }
    return 0;
}