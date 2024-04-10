#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x==y){
            printf("%lli\n",x);
        }
        else if(x>y){
            printf("%lli\n",x+y);
        }
        else{
            ll div=y/x;
            ll num=x*div;
            printf("%lli\n",(num+y)/2);
        }
    }
    return 0;
}