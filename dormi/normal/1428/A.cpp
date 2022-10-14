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
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        printf("%lli\n",abs(x2-x1)+abs(y1-y2)+(abs(x2-x1)>=1&&abs(y1-y2)>=1?2:0));
    }
    return 0;
}