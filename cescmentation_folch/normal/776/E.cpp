#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll n) {
    vector<ll> V;
    ll k = n;
    for (ll i = 2; i*i <= n; ++i) {
        if (k%i == 0) V.push_back(i);
        while (k%i == 0) k /= i;
    }
    if (k > 1) V.push_back(k);
    for (int i = 0; i < V.size(); ++i) {
        n /= V[i];
        n *= (V[i] - 1);
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    ll k;
    cin >> n >> k;
    while (k > 0 and n > 1) {
        k -= 2;
        n = f(n);
    }
    n %= 1000000007ll;
    cout << n << '\n';
}