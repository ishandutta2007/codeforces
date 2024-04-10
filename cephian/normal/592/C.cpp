#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

bool overflow_lcm(ll a, ll b, ll l) {
    return (l % a != 0) || (l % b != 0) || (l <= 0);
}

int main() {
    ll t, w, b;
    cin >> t >> w >> b;
    ll lc = lcm(w, b);
    if(overflow_lcm(w, b, lc)) {
        ll num = min(t, min(w-1, b-1));
        ll g = gcd(num, t);
        num /= g;
        t /= g;
        cout <<  num << "/" << t << "\n";
        return 0;
    }

    ll ans = min(w, b) * (1+t/lc);
    ll highest = (t / lc)*lc;
    ans -= max(0LL, (min(w, b) - (t - highest+1)));
    --ans;
    ll den =t;
    ll g = gcd(den, ans);
    ans /= g;
    den /= g;
    cout << ans << "/" << den << "\n";

    return 0;
}