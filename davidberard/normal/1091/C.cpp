#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<ll> fac;
    set<ll> ans;
    for(ll i = 1;i*i <= n;++i) {
        if(n%i == 0) {
            fac.push_back(n/i);
            fac.push_back(i);
        }
    }
    for(auto& i : fac) {
        ll val = ((n/i)*(n/i-1)/2)*i+(n/i);
        ans.insert(val);
    }
    for(auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}