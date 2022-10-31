#include <bits/stdc++.h>
using namespace std;

const long long md=1e9+7;
int n;

long long x;
long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    long long res=2;
    long long odd=1;
    for (int i=1;i<=n;++i) {
        cin>>x;
        res=p(res,x);
        if (!(x&1)) odd=0;
    }
    res=(res*p(2,md-2))%md;
    long long res2=res;
    if (odd) res=(res-1+md)%md;
    else res=(res+1)%md;
    res=(res*p(3,md-2))%md;
    cout<<res<<"/"<<res2;
}