#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, s;
    cin >> n >> s;
    vector<ll> v(n);
    ll mn = 1e9;
    ll sm = 0;
    for(auto& x : v) {
        cin >> x;
        sm += x;
        mn = min(mn, x);
    }
    if(sm < s) {
        cout << -1 << endl; return 0;
    }
    ll xtra = 0;
    for(auto& x : v) {
        xtra += x-mn;
    }
    s -= xtra;
    if(s <= 0) {
        cout << mn << endl; return 0;
    }
    cout << (n*mn-s)/n << endl;
    return 0;
}