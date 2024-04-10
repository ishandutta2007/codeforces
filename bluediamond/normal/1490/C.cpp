#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        set<ll> sCubes;
        vector<ll> vCubes;
        for (ll i = 1; i * i * i <= (ll) 1e12; i++) {
                ll j = i * i * i;
                sCubes.insert(j);
                vCubes.push_back(j);
        }

        int t;
        cin >> t;
        while (t--) {
                ll n;
                bool ok = 0;
                cin >> n;
                for (auto &x : vCubes) {
                        if (x >= n)
                                break;
                        if (sCubes.count(n - x)) {
                                ok = 1;
                                break;
                        }
                }
                if (ok)
                        cout << "YES\n";
                else
                        cout << "NO\n";
        }

}