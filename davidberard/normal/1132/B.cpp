#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n, m;
ll pfx[300300];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<ll> a(n);
    for(auto& x : a) cin >> x;
    cin >> m;
    vector<ll> q(m);
    for(auto& x : q) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    for(int i=1;i<=n;++i) {
        pfx[i] = pfx[i-1]+a[i-1];
    }
    for(auto& x : q) {
        cout << pfx[n]-a[n-x] << "\n";
    }
    return 0;
}