#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll m, a, b;

ll dioph(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = dioph(b, b%a, y, x);
    y -= a/b*x;
    return d;
}

const int NMAX = 100100;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll s[NMAX*2];

ll f(ll m, ll i, ll a) {
    if(m < 0) return 0;
    ll n = (m+a-i)/a;
    return n*(m+1)-n*(n-1)*a/2-i*n;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> a >> b;
    memset(s, INF, sizeof s);
    int t = 0;
    int v = 0;
    for(int qq=0; qq==0 || t != 0; ++qq) {
        int amt = max((b-t+a-1)/a, 0LL);
        t += amt*a;
        v = max(v, t);
        while(t > 0) {
            assert(s[t] == INF);
            s[t] = v;
            //cerr << " s" << t << " = " << s[t] << endl;
            t -= b;
        }
        if(t < 0) t += b;
    }
    s[0] = 0;
    ll ans = 0;
    for(int i=0;i<a;++i) {
        //ll n = max((m+a-s[i])/a, 0LL);
        //ll x = s[i];
        //ll fn = ((s[i]-1-i+a)/a-1)*a+i;
        //cerr << "   fn " << i << " is " << f(m, i) << " - " << f(s[i]-1, i) << endl;
        ans += f(m, i, a) - f(min(s[i]-1, m), i, a);
    }
    cout << ans << endl;
    return 0;
}