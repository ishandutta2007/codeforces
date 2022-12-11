#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL x,ans=1e18,a,b;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main(){
    cin>>x;
    for(int i=1;1ll*i*i<=x;i++)
        if(x%i==0&&gcd(i,x/i)==1&&max(1ll*i,x/i)<ans)
            ans=max(1ll*i,x/i),a=i,b=x/i;
    cout<<a<<" "<<b<<endl;
    return 0;
}