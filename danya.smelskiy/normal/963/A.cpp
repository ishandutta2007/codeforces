#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+9;


long long X;
long long n,a,b,k;
long long q[100005];
string s;
long long cur;

inline long long pw(long long x,long long y) {
    long long res=1;
    while (y) {
        if (y%2ll==1ll) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b>>k;
    cin>>s;

    long long last=1;
    for (int i=0;i<k;++i) {
        cur=last;
        last=(last*b)%md;
        cur=(cur*pw(a,n-i))%md;
        if (s[i]=='-') cur*=-1;
        X+=cur;
        if (X<0) X+=md;
        else if (X>=md) X-=md;
    }
    long long m=((n+1)/k);
    long long D=pw(b,k);
    long long B=pw(a,k);
    B=pw(B,md-2);
    D=(D*B)%md;
    long long ans=0;
    if (D==1) ans=m;
    else {
        long long z=pw(D,m);
        z=(long long)1-z;
        if (z<0) z+=md;
        long long zz=1;
        zz-=D;
        if (zz<0) zz+=md;
        zz=pw(zz,md-2);
        z*=zz;
        z%=md;
        ans=z;
    }
    ans=(ans*X)%md;
    cout<<ans;
}