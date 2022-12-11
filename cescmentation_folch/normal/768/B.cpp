#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll D[60];
ll U[60];

ll calc(int p, ll n) {
    if (n == 1) return D[p] = 1;
    return D[p] = 2ll*calc(p + 1, n/2) + 1; 
}

ll uns(int p, ll n) {
    if (n == 1) return U[p] = 1;
    return U[p] = 2ll*uns(p + 1, n/2) + (n%2);
}

ll f(ll a, ll b, ll x, ll y, int p, ll n) {
    if (a <= x and y <= b) return U[p];
    if (b < x or y < a) return 0;
    
    ll res = 0;
    if (a <= x + D[p + 1] and x + D[p + 1] <= b) res += (n%2);
    return res + f(a, b, x, x + D[p + 1] - 1, p + 1, n/2) + f(a, b, x + D[p + 1] + 1, y, p + 1, n/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;

if (n == 0) {
cout << 0 << endl;
return 0;
}
    
    calc(0, n);
    uns(0, n);
    
    ll l, r;
    cin >> l >> r;
    
    cout << f(l, r, 1, D[0], 0, n) << endl;
}