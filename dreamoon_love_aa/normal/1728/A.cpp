#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int ma = 0, ma_id = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x > ma) {
            ma = x;
            ma_id = i;
        }
    }
    cout << ma_id << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}