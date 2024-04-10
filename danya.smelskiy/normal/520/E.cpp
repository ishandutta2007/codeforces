#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n,k;
string s;
long long f[200005],p[200005],d[200005];

inline long long pp(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
inline long long cnk(long long x,long long y){
    if (y<0 || y>x) return 0;
    long long res=f[x];
    res=(res*pp(f[y],md-2))%md;
    res=(res*pp(f[x-y],md-2))%md;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    cin>>s;
    f[0]=1;
    p[0]=1;
    for (int i=1;i<=100005;++i){
        f[i]=(f[i-1]*i)%md;
        p[i]=(p[i-1]*10)%md;
        d[i]=(d[i-1]+(i<=n ? s[i-1]-'0' : 0));
    }
    long long ans=0;
    for (int i=1;i<=n;++i) {
        long long res=(d[n-i]*p[i-1])%md;
        ans=(ans+(res*cnk(n-i-1,k-1))%md)%md;
        res=((d[n-i+1]-d[n-i])*p[i-1])%md;
        ans=(ans+(res*cnk(n-i,k))%md)%md;
    }
    cout<<ans;
}