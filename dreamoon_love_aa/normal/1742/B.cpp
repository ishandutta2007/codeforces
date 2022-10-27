#include<iostream>
#include<vector>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}