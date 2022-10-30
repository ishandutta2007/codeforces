#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,ans;
int ans1,ans2;
int main(){
    cin>>x>>y>>z;
    if (y<x) swap(x,y);
    if (z<y) swap(z,y);
    if (y<x) swap(y,x);
    ans=(x+z)/2;
    ans1=ans-x+z-ans+abs(y-ans);
    ans2=y-x+z-y;
    cout<<min(ans1,ans2);
}