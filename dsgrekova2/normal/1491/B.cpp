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
#define ll long long
using namespace std;
void solve(){
    ll n, u, v;
    cin >> n >> u >> v;
    int allone = true;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    bool zeroans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            allone = false;
        if (abs(a[i] - a[i-1]) > 1)
            zeroans = true;
    }
    if (zeroans){
        cout << "0\n";
        return;
    }
    if (allone){
        cout << min(u + v, v + v) << '\n';
        return;
    }
    cout << min(u, v) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}