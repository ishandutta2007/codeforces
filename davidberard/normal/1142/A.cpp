#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n, k;
ll a, b;

ll gmax, gmin;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    cin >> a >> b;
    gmin=n*k;
    gmax=1;
    for(int i=0;i<=n+1;++i) {
        if(i*k-a-b > 0) {
            ll v = i*k-a-b;
            gmin = min(gmin, __gcd(v, n*k));
            gmax = max(gmax, __gcd(v, n*k));
        }
        if(i*k+a+b > 0) {
            ll v = i*k+a+b;
            gmin = min(gmin, __gcd(v, n*k));
            gmax = max(gmax, __gcd(v, n*k));
        }
        if(i*k-a+b > 0) {
            ll v = i*k-a+b;
            gmin = min(gmin, __gcd(v, n*k));
            gmax = max(gmax, __gcd(v, n*k));
        }
        if(i*k+a-b > 0) {
            ll v = i*k+a-b;
            gmin = min(gmin, __gcd(v, n*k));
            gmax = max(gmax, __gcd(v, n*k));
        }
    }
    cout << n*k/gmax << " " << n*k/gmin << "\n";
    return 0;
}