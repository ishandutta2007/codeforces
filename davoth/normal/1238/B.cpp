

#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_N = 1e5 + 1, MOD = 1e8;
using namespace std;
int main() {
    ll q;
    cin >> q;
    while(q--){
        ll n,r;
        cin >> n >> r;
        ll mt=0;
        set<ll> v;
        for(ll i=0; i<n; i++){
            ll t;
            cin >> t;
            v.insert(t);
            if(t>mt) mt=t;
        }
        v.erase(mt);
        ll i=1;
        bool c=false;
        for(auto it=v.rbegin(); it!=v.rend(); it++){
            if(*(it)<=i*r){
                cout << i << '\n';
                c=true;
                break;
            }
            i++;
        }
        if(!c) cout << i << '\n';
    }
    return 0;
}