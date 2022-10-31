#include <bits/stdc++.h>
using namespace std;
long long n,k;

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    long long x=0,y=0;
    long long m=n;
    while (m%(long long)2==0) {
        m/=(long long )2;
        ++x;
    }
    while (m%(long long)5==0) {
        m/=(long long)5;
        ++y;
    }
    long long kol=min(x,y);
    x-=kol; y-=kol;
    while (kol<k) {
        if (x<y) {
            ++x;
            n*=(long long)2;
        } else {
            ++y;
            n*=(long long)5;
        }
        long long z=min(x,y);
        kol+=z;
        x-=z;
        y-=z;
    }
    cout<<n;
}