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
    ll T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> used(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            used[b] = 1;
        }
        for (int i = 1; i <= n; i++)
            if (!used[i]) {
                for (int j = 1; j <= n; j++)
                    if (i != j)
                        cout << j << " " << i << "\n";
                break;
            }
    }
    
}