#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

pll exgcd(ll a, ll b) {
    if (b == 0) return pll(1, 0);
    ll p = a / b;
    pll q = exgcd(b, a % b);
    return pll(q.Y, q.X - q.Y * p);
}

pll abx(ll a, ll b, ll x) {
    pll rt = exgcd(a, b);
    rt.X *= x, rt.Y *= x;
    if (rt.X < 0) {
        ll t = (abs(rt.X) + b - 1) / b;
        rt.X += t * b;
        rt.Y -= t * a;
    }
    if (rt.Y < 0) {
        ll t = rt.X / b;
        rt.X -= t * b;
        rt.Y += t * a;
    }
    assert(rt.Y >= 0);
    return rt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, x;
    cin >> n, x = n;
    vector<ll> p;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            p.pb(i);
        }
    if (x > 1) p.pb(x);
    if (SZ(p) == 1) return cout << "NO\n", 0;
    cout << "YES\n";
    pll rt = abx(p[0], p[1], n - 1);
    vector<pll> ans;
    if (rt.X != 0) ans.pb(pll(rt.X, n / p[0]));
    if (rt.Y != 0) ans.pb(pll(rt.Y, n / p[1]));
    cout << SZ(ans) << "\n";
    for (pll pr : ans)
        cout << pr.X << " " << pr.Y << "\n";
}