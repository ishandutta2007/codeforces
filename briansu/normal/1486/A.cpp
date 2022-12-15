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
        bool fg = true;
        ll lft = 0, t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            t += lft;
            if (t < i) fg = false;
            else lft = t - i;
        }
        if (fg) cout << "YES\n";
        else cout << "NO\n";
    }
}