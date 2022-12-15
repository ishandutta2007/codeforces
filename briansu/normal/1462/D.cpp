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

int d[3005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, tt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> d[i], tt += d[i];
        int mx = 1;
        for (int i = 2; i <= n; i++)
            if (tt % i == 0) {
                bool ok = 1;
                int cur = 0, targ = tt / i;
                for (int j = 1; j <= n; j++) {
                    cur += d[j];
                    if (cur == targ) cur = 0;
                    else if (cur > targ) {
                        ok = false;
                        break;
                    }
                }
                if (ok) mx = i;
            }
        cout << n - mx << "\n";
    }
}