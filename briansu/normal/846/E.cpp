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
const ll INF = 2e18;
int p[MAXn], k[MAXn];

ll a[MAXn], b[MAXn];

ll mul(ll x, ll y) {
    if (x >= INF || y >= INF)
        return INF;
    if (INF / x <= y)
        return INF;
    else
        return x * y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        cin >> p[i] >> k[i];
    for (int i = n; i > 1; --i) {
        if (a[i] < b[i])
            b[p[i]] += (b[i] - a[i]); 
        else if (a[i] > b[i])
            b[p[i]] -= mul(a[i] - b[i], k[i]), b[p[i]] = max(-INF, b[p[i]]);
    }
    if (a[1] <= b[1])
        cout << "YES\n";
    else
        cout << "NO\n";
}