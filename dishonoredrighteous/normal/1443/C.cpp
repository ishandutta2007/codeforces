#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }    

    int l = 0, r = 1e9;
    while (r - l > 1) {
        int mid = (l+r) / 2;
        ll sm = 0;
        for(int i = 0; i < n; i++) {
            if (mid < a[i]) sm += b[i];
        }
        
        if (sm > mid) l = mid;
        else r = mid;
    }

    cout << r << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}