#include<iostream>
using namespace std;
void solve() {
    int n;
    cin >> n;
    if(n % 2 == 0) {
        for(int i = n - 2; i; i--) {
            cout << i << ' ';
        }
    } else {
        cout << n - 3 << ' ' << n - 2 << ' ';
        for(int i = n - 4; i; i--) {
            cout << i << ' ';
        }
    }
    cout << n - 1 << ' ' << n << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}