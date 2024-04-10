#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll arr[2];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i%2]+=(a)/2;
        arr[!(i%2)]+=a-(a/2);
    }
    printf("%lli\n",min(arr[0],arr[1]));
    return 0;
}