#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,z;
        cin>>n>>z;
        int a;
        int best=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            best=max(best,a|z);
        }
        printf("%d\n",best);
    }
    return 0;
}