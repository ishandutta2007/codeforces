#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<iostream>
using namespace std;
void solve() {
    int n;
    int k;
    int t;
    cin >> n >> k >> t;
    int an = 0;
    for(int i = 1; i <= t; i++) {
        an += (i <= n) - (i > k);
    }
    cout << an << '\n';
}
int main() {
    solve();
    return 0;
}