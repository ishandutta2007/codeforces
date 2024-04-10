#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    if(k % 2) {
        cout << "YES\n";
        for(int i = 1; i < n; i += 2) {
            cout << i << ' ' << i + 1 << '\n';
        }
    } else if(k % 4 == 2){
        cout << "YES\n";
        for(int i = 1; i < n; i += 2) {
            if(i % 4 == 1) {
                cout << i + 1 << ' ' << i << '\n';
            } else {
                cout << i << ' ' << i + 1 << '\n';
            }
        }
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}