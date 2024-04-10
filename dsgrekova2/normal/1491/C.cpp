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
#define int ll
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> prig(n + 1);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = a[i] - 1;
        for (int j = 1; j + i + 1 < n and j <= t; ++j) {
            prig[i + j + 1]++;
        }
        t -= prig[i];
        if (t >= 0){
            res += t;
        } else{
            prig[i + 1] -= t;
        }
    }
    cout << res << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}