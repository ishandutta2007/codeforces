#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll a, b, kk; cin >> a >> b >> kk;
    if(a+b-2<kk) cout << "-1" << endl;
    else {
        ll ans = 0;
        for(int i = 0; i < 2; ++i) {
            swap(a, b); ll t = 0; ll k = kk;
            if(a-1 >= k) {
                t = b * (a / (k+1));
            }
            else {
                k -= (a-1);
                t = b / (k+1);
            }
            ans = max(ans, t);
        }
        cout << ans << endl;
    }
    return 0;
}