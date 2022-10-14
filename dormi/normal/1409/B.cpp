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
    int t;
    cin>>t;
    while(t--){
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll firprod=max(x,a-n)*max(y,b-(n-(a-max(x,a-n))));
        swap(a,b),swap(x,y);
        ll secprod=max(x,a-n)*max(y,b-(n-(a-max(x,a-n))));
        printf("%lli\n",min(firprod,secprod));
    }
    return 0;
}