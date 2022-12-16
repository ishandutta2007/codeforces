#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n;
vector<ll> s;
int q;

struct line {
    ll m, b, st;
    line() {}
    line(ll a, ll d, ll c) :m(a), b(d), st(c) {}
    ll eval(ll x) const {
        return m*x+b;
    }
    bool operator<(const line& o) const {
        if(st == o.st) return b < o.b;
        return st < o.st;
    }
};

vector<line> lines;

ll solve(ll v) {
    //cerr << " query for " << 0 << " " << (ll) 3e18 << " " << v << endl;
    auto it = --upper_bound(lines.begin(), lines.end(), line(0, 3e18, v));
    //cerr << " looking for " << v << " see " << it->m << " " << it->b << " " << it->st << endl;
    return it->eval(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    s = vector<ll>(n);
    for(int i=0;i<n;++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    vector<ll> t;
    for(int i=0;i<n-1;++i) {
        t.push_back(s[i+1]-s[i]);
    }
    t.push_back(2e18);
    sort(t.begin(), t.end());
    lines.push_back(line(n, 0, -1));
    for(int i=0;i<n;++i) {
        //cerr << " emplace " << n-i-1 << " " << lines.back().eval(t[i]) << " " << t[i] << endl;
        lines.emplace_back(n-i-1, lines.back().eval(t[i])-t[i]*(n-i-1), t[i]);
    }
    cin >> q;
    for(int i=0;i<q;++i) {
        ll l, r;
        cin >> l >> r;
        cout << solve(r+1-l) << " ";
    }
    cout << endl;
    return 0;
}