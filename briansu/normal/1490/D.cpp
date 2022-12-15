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

const int MAXn = 105;

int d[MAXn], ans[MAXn];

void go(int l, int r, int b) {
    if (l > r) return;
    int mx = max_element(d + l, d + r + 1) - d;
    ans[mx] = b;
    go(l, mx - 1, b + 1);
    go(mx + 1, r, b + 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> d[i];
        go(1, n, 0);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    
}