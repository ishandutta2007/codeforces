#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int have[101];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int mn = 100;
    int n;
    cin >> n;
    ll sm = 0;
    for(int i=1;i<=n;++i) {
        int a;
        cin >> a;
        sm += a;
        have[a] = 1;
        mn = min(mn, a);
    }
    ll ans = 0;
    for(int i=1;i<=100;++i) {
        for(int j=1;j<=100;++j) {
            if(have[j] && j%i == 0) {
                ans = max(ans, (ll) j-j/i+mn-mn*i);
                //cerr << " . " << j-j/i << " " << mn-mn*i << " " << i << " " << j << endl;
            }
        }
    }
    cout << sm-ans << endl;
    return 0;
}