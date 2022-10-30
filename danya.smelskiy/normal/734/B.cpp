#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,ans,x;
int main(){
    cin>>a>>b>>c>>d;
    x=min(a,min(c,d));
    ans=x*256;
    a-=x;
    c-=x;
    d-=x;
    x=min(a,b);
    ans+=x*32;
    cout<<ans;
}