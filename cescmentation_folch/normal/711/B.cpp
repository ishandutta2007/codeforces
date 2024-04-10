#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll k[n][n];
    int x,y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> k[i][j];
            if (k[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    ll s = -1;
    bool yes = true;
    for (int i = 0; i < n; ++i) {
        ll ss = 0;
        if (i == x) goto altre;
        for (int j = 0; j < n; ++j) {
            ss += k[i][j];
        }
        if (s == -1) s = ss;
        if (s != ss) yes = false;
        altre:
        if (i == y) continue;
        ss = 0;
        for (int j = 0; j < n; ++j) {
            ss += k[j][i];
        }
        if (s == -1) s = ss;
        if (s != ss) yes = false;
    }
    ll t1 = 0, t2 = 0;
    for (int i = 0; i < n; ++i) {
        t1 += k[x][i];
        t2 += k[i][y];
    }
    if (t1 != t2 or t1 >= s) yes = false;
    ll d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i) {
        d1 += k[i][i];
        d2 += k[i][n - i - 1];
    }
    if (x == y and d1 != t1) yes = false;
    if (x != y and d1 != s) yes = false;
    if (x == n - y - 1 and d2 != t1) yes = false;
    if (x != n - y - 1 and d2 != s) yes = false;
    if (yes) {
        cout << s - t1 << endl;
    }
    else cout << -1 << endl;
}