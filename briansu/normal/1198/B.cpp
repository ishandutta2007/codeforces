#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXn = 2e5 + 5;

int d[MAXn], t[MAXn], dt[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i], t[i] = 0;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            d[p] = x;
            t[p] = i;
        }
        else
            cin >> dt[i];
    }
    for (int i = q - 1; i >= 0; i--)
        dt[i] = max(dt[i], dt[i + 1]);
    for (int i = 1; i <= n; i++)
        d[i] = max(d[i], dt[t[i]]);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " \n"[i == n];
}