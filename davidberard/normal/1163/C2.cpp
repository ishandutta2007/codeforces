#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
typedef pair<pii, pii> piii;

pair<pii, pii> get(int x1, int y1, int x2, int y2) {
    assert(x1 != x2 || y1 != y2);
    if(x1==x2) {
        return piii(pii(0, 1), pii(x1, 1));
    }
    if(y1 == y2) {
        return piii(pii(1, 0), pii(y1, 1));
    }
    ll num = x1-x2;
    ll den = y1-y2;
    if(num < 0) {
        num *= -1;
        den *= -1;
    }
    ll g = __gcd(num, abs(den));
    num /= g;
    den /= g;
    //cerr << " " << y1 << " - " << num << "*" << x1 << "/" << den << endl;
    ll n = (ll) y1*num-(ll) den*x1;
    ll d = num;
    ll gg = __gcd(abs(n), abs(d));
    if(n < 0 || (n==0 && d < 0)) {
        n *= -1;
        d *= -1;
    }
    if(n == 0) {
        d = 1;
    } else {
        n /= gg;
        d /= gg;
    }
    //cerr << " from " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << num <<"/" << den << " :: " << n << "/" << d << endl;
    return piii(pii(num, den), pii(n, d));
}

map<pii, set<pii>> mp;
const int NMAX = 1010;
int n;
int x[NMAX], y[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> x[i] >> y[i];
        for(int j=1; j<i; ++j) {
            piii res = get(x[j], y[j], x[i], y[i]);
            mp[res.first].insert(res.second);
        }
    }
    ll ans = 0;
    int m = 0;
    for(auto& s : mp) {
        m += s.second.size();
        //cerr; for(auto& x : s.second) {
            //cerr << " " << s.first.first << "/" << s.first.second << " : " << x.first << "/" << x.second << endl;
        //cerr; }
    }
    //cerr << "! m = " << m << endl;
    for(auto& s : mp) {
        ans += (ll) s.second.size() * (m-s.second.size());
    }
    cout << ans/2 << endl;
    return 0;
}