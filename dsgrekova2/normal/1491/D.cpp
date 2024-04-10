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
vector<int> bitprefs(int a){
    vector<int> bt(32);
    for (int i = 0; i < 32; ++i) {
        bt[i] = a % 2;
        a /= 2;
    }
    for (int i = 1; i < 32; ++i) {
        bt[i] += bt[i - 1];
    }
    return bt;
}
void solve(){
    int a, b;
    cin >> a >> b;
    vector<int> a1 = bitprefs(a), b1 = bitprefs(b);
    bool res = 1;
    for (int i = 0; i < 32; ++i) {
        if (a1[i] < b1[i])
            res = 0;
    }
    if (res and a <= b){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}