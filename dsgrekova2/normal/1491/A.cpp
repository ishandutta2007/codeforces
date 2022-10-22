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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int sum = 0;
    for (auto & i : a) {
        cin >> i;
        sum += i;
    }
    for (int j = 0; j < q; ++j) {
        int t, b;
        cin >> t >> b;
        if (t == 1){
            b--;
            sum -= a[b];
            a[b] = 1 - a[b];
            sum += a[b];
        }else{
            if (sum >= b){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
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