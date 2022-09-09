#include<iostream>
using namespace std;
const int SIZE = 1 << 18;
int a[SIZE];
long long diff[SIZE];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    long long ans = 0;
    for(int i = 2; i <= n; i++) {
        if(diff[i] > 0) {
            ans += diff[i];
        } else {
            int need = -diff[i];
            ans += need;
            diff[1] -= need;
        }
    }
    ans += abs(diff[1]);
    cout << ans << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}