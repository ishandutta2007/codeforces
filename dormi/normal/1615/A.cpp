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
        int n;
        cin>>n;
        ll a;
        ll sum=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            sum+=a;
        }
        if(sum%ll(n)==0)printf("0\n");
        else printf("%lli\n",1);
    }
    return 0;
}