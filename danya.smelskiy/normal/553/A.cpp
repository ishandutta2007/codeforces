#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long n;
long long f[100005];
long long r[100005];
long long ans,x,last;
inline long long p(long long l,long long r){
    long long res=1;
    while (r) {
        if (r&1) res=(res*l)%md;
        l=(l*l)%md;
        r/=2;
    }
    return res;
}
inline long long get(long long x,long long y){
    long long q=f[x];
    q=(q*r[x-y])%md;
    q=(q*r[y])%md;
    return q;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    f[0]=1;
    for (int i=1;i<=1e3;++i){
        f[i]=(f[i-1]*i)%md;
    }
    r[0]=1;
    for (int i=1;i<=1e3;++i)
        r[i]=p(f[i],md-2);
    ans=1;
    for (int i=1;i<=n;++i){
        cin>>x;
        ans=(ans*get(last+x-1,x-1))%md;
        last+=x;
    }
    cout<<ans;
}