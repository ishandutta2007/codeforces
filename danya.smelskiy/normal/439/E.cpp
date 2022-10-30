#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


int k;
int n,m;
long long f[200005],r[200005];
int a[200005];

inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
inline long long cnk(long long x,long long y){
    if (x<y) return 0;
    if (x==y) return 1;
    long long res=f[x];
    res=(res*r[y])%md;
    res=(res*r[x-y])%md;
    return res;
}
inline long long ff(long long x){
    x=(n/x);
    return (x<m ? 0ll : cnk(x-1,x-m));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k;
    f[0]=1;
    r[0]=p(f[0],md-2);
    for (int i=1;i<=1e5;++i) {
        f[i]=(f[i-1]*(long long)i)%md;
        r[i]=p(f[i],md-2);
    }
    for (int ii=1;ii<=k;++ii) {
        cin>>n>>m;
        int xx=n;
        int kol=0;
        for (int j=2;j<=sqrt(xx);++j)
        if (xx%j==0) {
            a[++kol]=j;
            while (xx%j==0) xx/=j;
        }
        long long ans=0;
        if (xx>1) a[++kol]=xx;
        for (int i=0;i<(1<<kol);++i) {
            int q=1;
            int qq=1;
            for (int j=0;j<kol;++j) if (i&(1<<j)){
                q^=1;
                qq=(qq*a[j+1]);
            }
            if (q) ans=(ans+ff(qq))%md;
            else ans=(ans+md-ff(qq))%md;
        }
        cout<<ans<<'\n';
    }
}