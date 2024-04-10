#include <bits/stdc++.h>
using namespace std;



long long n,m;
long long ans,last;

inline void chek(long long x){
    long long k=((n)*(n+1))/2;
    k*=x;
    if (k<=m && (m-k)%x==0) {
        ans=max(ans,x);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    swap(n,m);
    if (m<((n*(n+1))/2) || ((n*(n+1))/2)<n) {
        cout<<"-1";
        return 0;
    }
    for (long long i=1;i<=sqrt(m)+1;++i) {
        if (m%i==0) {
            chek(i);
            chek(m/i);
        }
    }
    long long kol=0;
    for (int i=1;i<n;++i){
        last+=ans;
        cout<<last<<" ";
        kol+=last;
    }
    cout<<m-kol<<'\n';

}