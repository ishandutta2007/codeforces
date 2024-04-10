#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a;
    ll sum=0;
    for(int i=0;i<n;i++)cin>>a,sum+=a;
    sum-=(n*(n-1)/2);
    ll add=sum/n,mod=sum%n;
    for(ll i=1;i<=n;i++){
        if(i<=mod)printf("%lli ",i-1+add+1);
        else printf("%lli ",i-1+add);
    }
    return 0;
}