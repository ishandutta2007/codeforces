#include <bits/stdc++.h>
using namespace std;


long long n,m;
long long c[100][100];
long long f(long long x){
    long long res=0,kol=0;
    for (long long i=60;i>=0;--i) {
        long long z=i;
        z=((1ll)<<z);
        z=(z&x);
        if (z) {
            if (kol<m) res=res+c[i][m-kol];
            ++kol;
        }
    }
    if (kol==m) ++res;
    return res;
}
long long ff(long long x){
    return f(x+x)-f(x);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    c[0][0]=1;
    for (int i=1;i<=60;++i)
    for (int j=0;j<=i;++j) {
        c[i][j]=c[i-1][j];
        if (j) c[i][j]+=c[i-1][j-1];
    }
    long long l=1;
    long long r=1e18;
    while (l<r-1) {
        long long mid=(l+r)/2;
        if (ff(mid)>=n) r=mid;
        else l=mid;
    }
    if (ff(l)==n) cout<<l;
    else cout<<r;
}