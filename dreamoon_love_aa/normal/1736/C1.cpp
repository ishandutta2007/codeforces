#include<iostream>
#include<vector>
using namespace std;
int n;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int ll = 0;
    long long an = 0;
    for(int i = 0; i < n; i++) {
        ll = max(ll, i - a[i] + 1);
        an += i - ll + 1;
    }
    cout << an << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}