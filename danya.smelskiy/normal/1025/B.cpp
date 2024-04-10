#include <bits/stdc++.h>
using namespace std;




int n;
long long res,x,y,xx,yy;
pair<long long,long long> a[150005];

inline long long gcd(long long x,long long y) {
    while (x>0 && y>0) {
        if (x>y) x%=y;
        else y%=x;
    }
    return x+y;
}

inline bool prime(long long x) {
    for (long long i=2;i*i<=x;++i)
        if (x%i==0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    res=0;
    for (int i=1;i<=n;++i) {
        cin>>x>>y;
        a[i]=make_pair(x,y);
        yy=gcd(x,y);
        x/=yy;
        x*=y;
        res=gcd(res,x);
    }
    for (long long i=1;i*i<=a[1].first;++i)
        if (a[1].first%i==0) {
            if (res%i==0 && i>1 && prime(i)) {
                cout<<i;
                return 0;
            }
            x=a[1].first/i;
            if (res%x==0 && x>1 && prime(x)) {
                cout<<x;
                return 0;
            }
        }

    for (long long i=1;i*i<=a[1].second;++i)
        if (a[1].second%i==0) {
            if (res%i==0 && i>1 && prime(i)) {
                cout<<i;
                return 0;
            }
            x=a[1].second/i;
            if (res%x==0 && x>1 && prime(x)) {
                cout<<x;
                return 0;
            }
        }

    cout<<"-1";
}