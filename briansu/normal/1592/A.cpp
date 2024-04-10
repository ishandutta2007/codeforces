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
        int n, h;
        cin >> n >> h;
        vector<ll> v;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }
        sort(ALL(v), greater<ll>());
        int x = v[0], y = v[1];
        int p = h / (x + y) * 2, q = h % (x + y);
        if (q == 0)
            cout << p << "\n";
        else if (q <= x)
            cout << p + 1 << "\n";
        else
            cout << p + 2 << "\n";
    }
        
}