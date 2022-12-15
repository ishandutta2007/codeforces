#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            mp[b] = max(mp[b], a);
        }
        if (SZ(mp) != 10) {
            cout << "MOREPROBLEMS\n";
            continue;
        }
        ll tt = 0;
        for (auto p : mp)
            tt += p.Y;
        cout << tt << "\n";
    }
}