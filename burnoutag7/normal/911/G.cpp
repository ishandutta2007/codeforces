#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline",  \
    "-ftree-vectorize", "-ffast-math")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
using namespace std;

int n,q;
char a[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1,t;i<=n;i++)cin>>t,a[i]=t;
    cin>>q;
    while(q--){
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        char X=x,Y=y;
        for(int i=l;i<=r;i++)a[i]=a[i]==X?Y:a[i];
    }
    for(int i=1;i<=n;i++)cout<<(int)a[i]<<' ';

    return 0;
}