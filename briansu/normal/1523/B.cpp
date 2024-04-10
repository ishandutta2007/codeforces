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

const int MAXn = 1e3 + 5;

ll a[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << 6 * n / 2 << "\n";
        for (int i = 1; i <= n; i += 2)
            for (int j = 1; j <= 2; j++) {
                cout << 1 << " " << i << " " << i + 1 << "\n";
                cout << 2 << " " << i << " " << i + 1 << "\n";
                cout << 1 << " " << i << " " << i + 1 << "\n";
                a[i] += a[i + 1];
                a[i + 1] -= a[i];
                a[i] += a[i + 1];
            }
    }
    
}