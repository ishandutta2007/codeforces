#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll m;

void insert(vector<pll> &X, ll a) {
    ll b = 1;
    for (; a % m == 0; a /= m) {
        b *= m;
    }
    if (X.empty() || X.back().first != a) X.emplace_back(a, b);
    else {
        X.back().second += b;
    }
}

vector<pll> read(ll k) {
    vector<pll> X;
    ll i, a;
    for (i = 1; i <= k; i++) {
        cin >> a;
        insert(X, a);
    }
    return X;
}

void tc() {
    ll n;
    cin >> n >> m;
    auto X = read(n);
    cin >> n;
    auto Y = read(n);
    cout << (X == Y ? "Yes" : "No") << "\n";
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    for (cin >> t; t--; ) {
        tc();
    }
    
    return 0;
}