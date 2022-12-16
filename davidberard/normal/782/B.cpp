#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;

const int NMAX = 60600;
ll x[NMAX], v[NMAX];

ld calc(ld m) {
    ld t = 0;
    for(int i=1; i<=n; ++i) {
        t = max(abs(x[i]-m)/v[i], t);
    }
    return t;
}

ld ts() {
    ld l = 1, r = 1e9;
    for(int k=0; k<300; ++k) {
        //cerr << " " << l << " " << r << endl;
        ld m1 = l+(r-l)/3;
        ld m2 = r-(r-l)/3;
        if(calc(m1) > calc(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return calc(r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> x[i];
    }
    for(int i=1; i<=n; ++i) {
        cin >> v[i];
    }
    cout << fixed << setprecision(10) << ts() << endl;
    return 0;
}