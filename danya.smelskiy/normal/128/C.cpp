#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m,k;
long long f[2005];
inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
long long cnk(int x,int y){
    if (y==x) return 1;
    if (y>x) return 0;
    long long res=f[x];
    res=(res*p(f[y],md-2))%md;
    res=(res*p(f[x-y],md-2))%md;
    return res;
}
int main(){
    cin>>n>>m>>k;
    f[0]=1;
    for (int i=1;i<=1005;++i)
        f[i]=(f[i-1]*i)%md;
    long long ans=cnk(n-1,k+k);
    ans=(ans*cnk(m-1,k+k))%md;
    cout<<ans;
}