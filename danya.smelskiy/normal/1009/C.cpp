#include <bits/stdc++.h>
using namespace std;



long long s;
int n,m;


inline long long f(long long x,long long y) {
    long long res=x;
    res*=x+1;
    res/=2ll;
    res*=y;
    return res;
}

inline long long f2(int x,long long y) {
    return f(x-1,y)+f(n-x,y);
}

inline long long solve(long long x) {
    int l=1;
    int r=n;
    while (l<r-2) {
        int m1=l+(r-l+1)/3;
        int m2=r-(r-l+1)/3;
        if (f2(m1,x)>=f2(m2,x)) r=m2;
        else l=m1;
    }
    long long res=-1e18;
    for (int i=l-2;i<=r+2;++i) {
        if (i>=1 && i<=n) res=max(res,f2(i,x));
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    long long x,y;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        s+=x*1ll*n;
        s+=solve(y);
    }
    long double ss=s;
    ss/=n;
    cout<<fixed<<setprecision(6)<<ss;
}