#include <bits/stdc++.h>
using namespace std;
long long n,x,y,minleft=100000000000,maxright=-100000000000,mindown=100000000000,maxtop=-100000000000;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        minleft=min(minleft,x);
        maxright=max(maxright,x);
        mindown=min(mindown,y);
        maxtop=max(maxtop,y);
    }
    long long l=maxright-minleft;
    long long r=maxtop-mindown;
    cout<<max(l,r)*max(l,r);
}