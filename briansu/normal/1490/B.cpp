#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll c[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            c[t % 3]++;
        }
        ll targ = n / 3, tt = 0;
        for (int i = 0; i < 6; i++) {
            if (c[i % 3] > targ) {
                ll t = c[i % 3] - targ;
                c[i % 3] -= t;
                c[(i + 1) % 3] += t;
                tt += t;
            }
        }
        cout << tt << endl;
    }
    
}