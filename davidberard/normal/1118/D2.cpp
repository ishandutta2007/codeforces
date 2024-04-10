#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n, m;
vector<ll> a;

ll calc(int d, int c) {
    for(int i=0;i*d<n;++i) {
        
    }
}

bool poss(int d) {
    ll lo = 0, hi = n;
    ll gain1, gain2;
    while(lo < hi) {
        ll m1 = (lo+hi)/2;
        ll m2 = m1+1;
        gain1 = 0, gain2 = 0;
        for(int i=0;i*d<n;i++) {
            for(int j=n-m1+i*d;j<n && j <n-m1+i*d+d;++j) {
                gain1 += max(0LL, a[j]-i);
            }
        }
        for(int i=0;i*d<n;i++) {
            for(int j=n-m2+i*d;j<n && j <n-m2+i*d+d;++j) {
                gain2 += max(0LL, a[j]-i);
            }
        }
        if(gain1 < gain2) {
            lo = m2;
        } else {
            hi = m1;
        }
    }
    return gain2 >= m;
}

ll bs() {
    ll lo = 1, hi = 2e9;
    while(lo < hi) {
        ll m = (lo+hi)/2;
        if(poss(m)) {
            hi = m;
        } else {
            lo = m+1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for(auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll ans = bs();
    cout << (ans > 1e9 ? -1 : ans) << endl;
    return 0;
}