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

const int C = 20000 + 5;

int can[C], a[105];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= C; i++) {
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
                can[i] = 1;
    }
    ll T;
    cin >> T;
    while (T--) {
        ll s = 0, n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], s += a[i];
        if (can[s]) {
            cout << n << endl;
            for (int i = 1; i <= n; i++)
                cout << i << " \n"[i == n];
        }
        else {
            bool ok = 0;
            cout << n - 1 << endl;
            for (int i = 1; i <= n; i++)
                if (can[s - a[i]]) {
                    for (int j = 1; j <= n; j++)
                        if (i != j)
                            cout << j << " ";
                    cout << endl;
                    ok = 1;
                    break;
                }
            assert(ok);
        }
    }
    
}