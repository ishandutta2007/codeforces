#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i: a) cin >> i;
        
        ll need = 0;
        ll ans = 0;
        
        for (int i = 1; i < n; ++i) {
            int diff = a[i] - a[i - 1];
            if (diff < 0) need += -diff;
            ans += abs(diff);
        }
        ans += abs(a[0] - need);
        cout << ans << '\n';
    }
}