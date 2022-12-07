#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector <int> tr{1};
    while(tr.back() < (int)1E9) {
        tr.push_back(tr.back() + (int)tr.size() + 1);
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ind = upper_bound(tr.begin(), tr.end(), n) - tr.begin() - 1;
        int rem = n - tr[ind];
        cout << "133";
        for(int i = 0; i < rem; i++) cout << '7';
        for(int i = 0; i < ind; i++) cout << '3';
        cout << '7';
        cout << '\n';
    }
    
    return 0;
}