#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 1001000;

ll a[NMAX*2];
ll n, l, t;
ll cnt(int i, int j) {
    ll v = (a[i]-a[j]+t*2+l)/l;
    //cerr << " cnt " << i << " " << j << " = " << v << endl;
    return v;
}

ld ans(int i) {
    int lo = i+2, hi = i+n;
    ll tv = cnt(i, i+1);
    while(lo<hi) {
        int m=(lo+hi)/2;
        //cerr << " " << lo << " " << hi << " " << m << endl;
        if(cnt(i, m) < tv) {
            hi = m;
        } else {
            lo = m+1;
        }
    }
    //cerr << " val is " << hi << " vs " << i << endl;
    if(hi == i+n) {
        ld v = (ld) tv*(n-1)/4;
        //cerr << " !- " << v << endl;
        return v;
    }
    ld v = (ld)((tv-1)*(i+n-hi) + tv*(hi-i-1))/4;
    //cerr << " -- " << v << endl;
    return v;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> l >> t;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        a[i+n] = a[i]+l;
    }
    ld out = 0;
    for(int i=0;i<n;++i) {
        out += ans(i);
        //cerr << ": " << out << endl;
    }
    cout << fixed << setprecision(5) << out << endl;
    return 0;
}