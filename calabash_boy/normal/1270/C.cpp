#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    ll xsum = 0;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum += x;
        xsum ^= x;
    }
    vector<ll> ans(0);
    if (sum & 1){
        ans.push_back((1ll<<50) + 1);
    }else{
        ans.push_back((1ll << 50));
    }
    xsum ^= (ans.front());
    xsum *= 2;
    sum += ans.front();
    ll val = (xsum - sum)/2;
    ans.push_back(val);
    ans.push_back(val);
    cout<<3<<endl;
    for (ll x : ans){
        cout<<x<<" ";
    }
    cout<<endl;

}
int main(){
    int T;
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}