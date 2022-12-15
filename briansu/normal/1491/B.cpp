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
    int T;
    cin >> T;
    while (T--) {
        int n, u, v;
        cin >> n >> u >> v;
        int lst;
        cin >> lst;
        int stat = 0;
        for (int i = 2, t; i <= n; i++) {
            cin >> t;
            if (abs(t - lst) >= 2) stat = 2;
            else if (abs(t - lst) == 1) stat = max(stat, 1);
            lst = t;
        }
        if (stat == 2) cout << 0 << "\n";
        else if (stat == 1) cout << min(u, v) << "\n";
        else cout << v + min(u, v) << "\n";
    }
    
}