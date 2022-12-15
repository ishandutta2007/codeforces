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
        int n;
        cin >> n;
        ll res = 1, c1 = 0;
        for (int i = 1, a; i <= n; i++) {
            cin >> a;
            if (a == 0)
                res *= 2;
            else if (a == 1)
                c1++;
        }
        cout << res * c1 << "\n";
    }
}