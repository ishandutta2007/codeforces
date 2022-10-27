#include<iostream>
using namespace std;
void solve() {
    int n;
    cin >> n;
    for(int i = n / 2 + 1; i <= n; i++) {
        cout << i << ' ';
        if(i != n || n % 2 == 0) cout << i - n / 2 << ' ';
    }
    cout << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}