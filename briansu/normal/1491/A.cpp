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

const int MAXn = 1e5 + 5;

bool d[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, t = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> d[i], t += d[i];
    for (int i = 1; i <= q; i++) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 1)
            t += (d[x] == 1 ? -1 : 1), d[x] = !d[x];
        else
            cout << (t >= x ? 1 : 0) << "\n";
    }
        
}