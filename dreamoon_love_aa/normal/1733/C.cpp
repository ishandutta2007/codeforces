#include<iostream>
#include<vector>
using namespace std;
const int MAX_N = 100000;
int a[MAX_N + 1];
vector<pair<int, int>> ans;
void op(int l, int r) {
    ans.push_back({l, r});
    if(1 & (a[l] + a[r])) {
        a[r] = a[l];
    } else {
        a[l] = a[r];
    }
}
void solve() {
    ans.clear();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n > 1) {
        op(1, n);
        for(int i = 2; i < n; i++) {
            if((a[i] + a[1]) & 1) {
                op(1, i);
            }
            else {
                op(i, n);
            }
        }
    }
    cout << (int)ans.size() << '\n';
    for(auto &[l, r]: ans) cout << l << ' ' << r << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}