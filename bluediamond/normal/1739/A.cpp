#include<iostream>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n + 1) / 2 << ' ' << (m + 1) / 2 << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}