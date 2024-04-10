#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 300300;

int n;
ll a[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i=0;i<n;++i) {
        while(i && a[i-1] && a[i] > 1) {
            --a[i-1];
            a[i] -= 2;
            ++ ans;
        }
        ll c = a[i]/3;
        ans += c;
        a[i] -= c*3;
        if(i) {
            a[i] += a[i-1];
            a[i-1] = 0;
        }
    }
    cout << ans << endl;

    return 0;
}