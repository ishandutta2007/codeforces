#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve(){
    int l, r;
    cin >> l >> r;
    int k = l;
    l -= k;
    r -= k;
    r += 1;
    int n = 2;
    while (1 << (n - 1) <= r){
        n++;
    }
    n += 3;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = 0; j < i; ++j) {
            // new i = n - 1 - i
            if (j == 0){
                g[n - 1 - i].push_back({n - 1, k});
            } else{
                g[n - 1 - i].push_back({n - 1 - j, 1 << (j - 1)});
            }
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (r > (1 << i)){
            g[0].push_back({n - 1 - i - 1, r - (1 << i)});
            r -= (1 << i);
        }
    }
    g[0].push_back({n-1,k});
    cout << "YES\n";
    cout << n << ' ';
    int m = 0;
    for (auto i : g)
        m += i.size();
    cout << m << endl;
    for (int i = 0; i < n; ++i) {
        for (auto [j, p] : g[i]) {
            cout << i + 1 << ' ' << j + 1 << ' ' << min(p, (int)1e6) << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}