#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a < abs(b - c) + c) {
        cout << "1\n";
    } else if(a > abs(b - c) + c) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}