#include <bits/stdc++.h>
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
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        reverse(ALL(b));
        reverse(ALL(a));
        vector<int> v(26, 0);
        int it = 0;
        bool fg = 0;
        for (char c : a) {
            if (it == SZ(b) || b[it] != c) {
                // rm
                v[c - 'A'] = 1;
            }
            else {
                // keep
                if (v[c - 'A']) {
                    fg = 1;
                    break;
                }
                it++;
            }
        }
        if (it != SZ(b) || fg)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}