#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

vector<pii> facs;
int k;
int n = 2000;

/*
void dfs(int pos, int cur, set<int>& di) {
    if(pos == facs.size()) {
        di.insert(cur);
        return;
    }
    for(int i=0;i<=facs[i].second;++i) {
        dfs(pos+1, cur, di);
        cur = cur*facs[i].first;
    }
} */

/*
 * Solves ax+by=gcd(a, b)
 * Note that the diophantine equation is only solvable when ax+by=gcd(a, b)
 * Give a, b and it will fill x, y.
 * Returns gcd(a, b)
 */
ll dioph(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = dioph(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

bool print(ll a, ll c, ll x, ll y) {
    if(a+c > n) return false;
    ll b = x;
    ll s = y-x;
    for(int i=0;i<c;++i) {
        int t = min(-b, 1000000LL);
        b += t;
    }
    if(b != 0) return false;
    if(s < 0) return false;
    for(int i=0;i<a;++i) {
        int t = min(s, 1000000LL);
        s -= t;
    }
    if(s != 0) return false;

    cout << a+c << endl;
    b = x;
    s = y-x;
    vector<int> r;
    for(int i=0;i<c;++i) {
        int t = min(-b, 1000000LL);
        b += t;
        r.push_back(-t);
    }
    reverse(r.begin(), r.end());
    for(int i=0;i<c;++i) {
        cout << r[i] << " ";
    }
    assert(b == 0);
    assert(s > 0);
    for(int i=0;i<a;++i) {
        int t = min(s, 1000000LL);
        s -= t;
        cout << t << " ";
    }
    assert(s == 0);
    cout << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >>k;
    //factorize();
    for(int a = 1;a<n;++a) {
        for(int c = 1;c+a<=n;++c) {
            ll x, y;
            ll g = dioph(a, c, x, y);
            if(k%g != 0) continue;
            // x = b, y = s+b. b should be negative.
            x *= k/g;
            y *= k/g;
            ll dx = -c/g;
            ll dy = a/g;
            if(dx == 0 || dy == 0) {
                cerr << "!! " << a << " " << c << " " << g << endl;
                assert(false);
            }
            ll nxmin = (-c-x)/dx;
            ll nxmax = (-500000-x)/dx;
            ll nymin = (500000-y)/dy;
            ll nymax = (a*1000000-y)/dy;
            if(nxmin < nymax && nxmax > nymax) {
                y += nymax*dy;
                x += nymax*dx;
                if(print(a, c, x, y)) return 0;
            }
            if(nymin < nxmax && nymax > nxmax) {
                y += nxmax*dy;
                x += nxmax*dx;
                if(print(a, c, x, y)) return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}