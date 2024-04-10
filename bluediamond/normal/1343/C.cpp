#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll OO = (ll) 1e18;

pair<int, ll> sol[2];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                sol[0].first = sol[1].first = 0;
                sol[0].second = sol[1].second = -OO;
                for (int i = 1; i <= n; i++) {
                        ll x;
                        cin >> x;
                        int t = (x > 0);
                        sol[t] = max(max(sol[t], make_pair(sol[t ^ 1].first + 1, sol[t ^ 1].second + x)), make_pair(1, x));
                }
                cout << max(sol[0], sol[1]).second << "\n";
        }
}