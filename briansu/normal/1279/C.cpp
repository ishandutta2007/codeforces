#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXn = 1e5 + 5;
int a[MAXn], b[MAXn], u[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        ll tt = m;
        for (int i = 1; i <= n; i++)
            cin >> a[i], u[i] = 0;
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        int it = 1;
        for (int i = 1; i <= n; i++) {
            while (it <= m && u[b[it]])
                it++;
            if (it <= m && a[i] == b[it])
                tt += (i - it) * 2;
            u[a[i]] = 1;
        }
        cout << tt << "\n";
    }
}