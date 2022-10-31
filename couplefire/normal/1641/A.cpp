#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        multiset<ll> mse;
        for(int i = 0; i<n; ++i){
            ll a; cin >> a;
            mse.insert(a);
        }
        int ans = 0;
        while(!mse.empty()){
            ll val = (*mse.begin());
            if(mse.count(val*x))
                mse.erase(mse.find(val*x));
            else ++ans;
            mse.erase(mse.find(val));
        }
        cout << ans << '\n';
    }
}