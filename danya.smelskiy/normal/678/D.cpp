#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long a,b,n,x;

inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y/=2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>n>>x;
    if (a==1) {
            n%=md;
        cout<<(x+(b*(n))%md)%md;
        return 0;
    }
    long long ans=x*p(a,n);
    ans%=md;
    long long z=((p(a,n)-1)*p(a-1,md-2))%md;
    z=(z*b)%md;
    cout<<(ans+z)%md;
}