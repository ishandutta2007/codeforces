#include <bits/stdc++.h>
using namespace std;
#define maxn 200000 + 10

int n, x[maxn], c[maxn], d[maxn];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];

    int sml = 0, big = 0;

    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++ i) c[x[i]] ++;

    for (int i = 1; i <= n; ++ i) {
        if (c[i] != 0) c[i] = c[i + 1] = c[i + 2] = 0, sml ++;
    }
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++ i) c[x[i]] ++;
    for (int i = 0; i <= n + 1; ++ i) {
        if (d[i] != 0) d[i + 1] += c[i], c[i] = 0;
        else if (c[i] != 0) {
            d[i + 1] += c[i] - 1, c[i] = 1;
        }
        else if (c[i + 1] != 0) c[i + 1] --, d[i] ++;
        if (c[i] != 0 || d[i] != 0) big ++;
    }

    cout << sml << " " << big << endl;
    return 0;
}