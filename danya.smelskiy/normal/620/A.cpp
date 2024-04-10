#include <bits/stdc++.h>
using namespace std;
long long x,y,x2,y2,kolx,koly,ans;
int main(){
    cin>>x>>y;
    cin>>x2>>y2;
    kolx=abs(x-x2);
    koly=abs(y-y2);
    long long z=min(kolx,koly);
    ans+=z;
    kolx-=z;
    koly-=z;
    ans+=kolx+koly;
    cout<<ans;
}