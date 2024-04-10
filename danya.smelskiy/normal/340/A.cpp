#include <bits/stdc++.h>
using namespace std;
long long ans,x,y,a,b;
int main(){
    cin>>x>>y>>a>>b;
    long long k=(x*y)/(__gcd(x,y));
    ans=b/k;
    --a;
    ans-=a/k;
    cout<<ans;
}