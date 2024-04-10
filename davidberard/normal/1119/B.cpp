#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n, h;

vector<ll> a;

bool poss(ll m) {
    vector<ll> b = a;
    b.resize(m);
    sort(b.begin(), b.end());
    ll H = h;
    for(ll i=0;i<b.size();++i) {
        if(i+1<b.size()) {
            H -= b[++i];
        } else {
            H -= b[i];
        }
    }
    if(H >= 0) return true;
    H = h;
    H -= b[0];
    for(ll i=1;i<b.size();++i) {
        if(i+1<b.size()) {
            H -= b[++i];
        } else {
            H -= b[i];
        }
    }
    return H >= 0;
}

ll bs() {
    ll lo = 0, hi = n;
    while(lo < hi) {
        ll m = (lo+hi+1)/2;
        if(poss(m)) {
            lo = m;
        } else {
            hi = m-1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> h;
    a = vector<ll>(n);
    for(auto& x : a) {
        cin >> x;
    }
    cout << bs() << endl;
    return 0;
}