#include <bits/stdc++.h>
using namespace std;


int n;
long long k;
long long a[100005];
long long b[100005];


inline bool f(long long x){
    long long y=k;
    for (int i=1;i<=n;++i) {
        long long z=a[i]*x;
        long long zz=z-b[i];
        if (zz>=0) y-=zz;
    }
    return y>=0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    int l=0;
    int r=1e9;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (f(mid)) l=mid;
        else r=mid;
    }
    if (f(r)) l=r;
    cout<<l;
}