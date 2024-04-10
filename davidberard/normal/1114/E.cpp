#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n;

ll g;

void inters(ll m) {
    //cerr << " intersect .." << endl;
    if(g == 0) {
        g = m;
        return;
    }
    g = __gcd(g, m);
}

map<ll, ll> fac(ll m) {
    //cerr << " !! factor " << m << endl;
    map<ll, ll> mp;
    for(ll i=2;i*i<=m;++i) {
        if(m%i == 0) {
            ll c = 0;
            while(m%i == 0) { c++; m/=i; }
            mp[i] = c;
            //cerr << " " << i << "^" << c << endl;
        }
    }
    if(m != 1) {
        mp[m] = 1;
        //cerr << " " << m << "^" << 1 << endl;
    }
    return mp;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    //cerr << "!! n = " << n << endl;
    if(n <= 59) {
        ll mn = 1e9+1, mx = -1;
        for(int i=1;i<=n;++i) {
            cout << "? " << i << endl;
            ll a;
            cin >> a;
            mn = min(a, mn);
            mx = max(a, mx);
        }
        ll d = (mx-mn)/(n-1);
        cout << "! " << mn << " " << d << endl;
        return 0;
    }
    ll lo = 0, hi = 1e9;
    int cc = 0;
    while(lo<hi) {
        ll m = (lo+hi)/2;
        ++cc;
        cout << "> " << m << endl;
        int r;
        cin >> r;
        if(r) {
            lo = m+1;
        } else {
            hi = m;
        }
    }
    //cerr << " lo " << lo << " hi " << hi << endl;
    vector<ll> v;
    srand(time(NULL));
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(;cc<59;++cc) {
        ll r = rng();
        cout << "? " << r%n+1 << endl;
        int a;
        cin >> a;
        v.push_back(a);
    }
    v.push_back(hi);
    for(int i=0;i<v.size();++i) {
        for(int j=i+1;j<v.size();++j) {
            if(abs(v[i]-v[j]) != 0) {
                inters(abs(v[i]-v[j]));
            }
        }
    }
    ll d = g;
    cout << "! " << hi-(n-1)*d << " " << d << endl;
    return 0;
}