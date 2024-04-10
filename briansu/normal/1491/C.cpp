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

ll d[5005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            d[i] = 0;
        ll tt = 0;
        for (int i = 1; i <= n; i++) {
            ll s;
            cin >> s;
            if (d[i] < s - 1)
                tt += (s - 1 - d[i]), d[i] = s - 1;
            for (int j = min(i + s, (ll)n); j > i; j--)
                if (j != i + 1) d[j]++;
                else d[j] += d[i] - (s - 1);
        }
        cout << tt << "\n";
    }
}