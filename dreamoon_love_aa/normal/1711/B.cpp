#include<iostream>
using namespace std;
const int SIZE = 1 << 20;
int x[SIZE], y[SIZE], deg[SIZE], a[SIZE];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        deg[x[i]]++;
        deg[y[i]]++;
    }
    if(m % 2 == 0) {
        cout << 0 << '\n';
    } else {
        int an = 2.1e9;
        for(int i = 1; i <= n; i++) {
            if(deg[i] & 1) an = min(an, a[i]);
        }
        for(int i = 0; i < m; i++) {
            if(deg[x[i]] % 2 == 0 && deg[y[i]] % 2 == 0) {
                an = min(an, a[x[i]] + a[y[i]]);
            }
        }
        cout << an << '\n';
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}