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

const int MAXn = 5e5 + 5;
int a[MAXn], b[MAXn], pb[2 * MAXn];
int mnk[MAXn];
ll G, H, M;

ll calculate(int n, int m, int x, int y, ll h) {
    ll t = (y - x) % m;
    if (t < 0)
        t += m;
    ll tt = H + (M >= x);
    if (mnk[t] == -1)
        return tt;
    ll first = x + (ll)mnk[t] * n;
    if (first > h)
        return tt;
    else
        return tt - (1 + (h - first) / G);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j], pb[b[j]] = j;

    for (int i = 0; i < m; i++)
        mnk[i] = -1;

    for (int i = 0; i < m; i++) {
        int t = (ll)i * n % m;
        if (mnk[t] == -1)
            mnk[t] = i;
    }

    G = lcm(n, m);

    ll l = 0, r = max(n, m) * k + 5;
    while (l != r - 1) {
        ll h = (l + r) / 2;
        ll tt = 0;
        H = h / n, M = h % n;
        for (int i = 1; i <= n; i++) {
            if (pb[a[i]] == 0)
                tt += H + (M >= i);
            else {
                tt += calculate(n, m, i, pb[a[i]], h);
            }
        }
        if (tt >= k)
            r = h;
        else
            l = h;
    }
    cout << l + 1 << endl;
}