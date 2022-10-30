#include <bits/stdc++.h>
using namespace std;
long long n;

inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%n;
        x=(x*x)%n;
        y>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1) {
        cout<<"YES"<<'\n'<<1;
        return 0;
    }
    if (n==4) {
        cout<<"YES"<<'\n';
        cout<<1<<'\n'<<3<<'\n'<<2<<'\n'<<4;
        return 0;
    }
    for (long long i=2;i<=sqrt(n);++i)
    if (n%i==0) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for (long long i=1;i<=n;++i)
    if (i==1 || i==n) cout<<i<<'\n';
    else cout<<(i*p(i-1,n-2))%n<<'\n';
}