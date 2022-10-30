#include <bits/stdc++.h>
using namespace std;

int n;
long double a[100001];
long double b[100001];
long double minim=1e10;
long double maxim=-1e10;
inline long double chek(long double q){
    long double now=0;
    for (int i=1;i<=n;++i){
        now=max(now,abs(q-a[i])/b[i]);
    }
    return now;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        minim=min(minim,a[i]);
        maxim=max(maxim,a[i]);
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
    }
    long double l=minim;
    long double r=maxim;
    while (l<r-0.0000001) {
        long double mid=(l+r)/2;
            long double m1=l+(r-l)/3;
        long double m2=r-(r-l)/3;
        long double z=chek(m1);
        long double zz=chek(m2);
        if (z>zz) l=m1;
        else r=m2;
    }
    cout<<fixed<<setprecision(7);
    cout<<min(chek(l),chek(r));
}