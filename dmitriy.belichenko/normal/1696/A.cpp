#include<bits/stdc++.h>
using namespace std;
unordered_map<char, int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, z;
        cin >> n >> z;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        int mx = 0;
        for (auto x : a) mx = max(mx, x | z);
        cout << mx << "\n";
    }
    return 0;
}