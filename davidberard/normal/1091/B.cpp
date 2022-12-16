#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;

map<pii, int> mp;

const int NMAX = 1010;

int x[NMAX], y[NMAX], a[NMAX], b[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> x[i] >> y[i];
    }
    for(int i=1;i<=n;++i) {
        cin >> a[i] >> b[i];
        for(int j=1;j<=n;++j) {
            //cerr << 
            ++ mp[pii(x[j]+a[i], y[j]+b[i])];
        }
    }
    for(auto& x : mp) {
        if(x.second == n) {
            cout << x.first.first << " " << x.first.second << "\n";
            return 0;
        }
    }
    return 0;
}