#include <bits/stdc++.h>
using namespace std;


long long n,a,b,p,q;

int main(){
    cin>>n>>a>>b>>p>>q;
    long long ans=(n/a)*p;
    ans+=(n/b)*q;
    long long x=__gcd(a,b);
    x=(a*b)/x;
    ans-=(n/x)*p+(n/x)*q;
    if (p>q) ans+=(n/x)*p;
    else ans+=(n/x)*q;
    cout<<ans;
}