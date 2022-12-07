#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector <int> v = {1200, 1400, 1600, 1900, 2100, 2200, 2400, 2700, 3000};
    cout << (*upper_bound(v.begin(), v.end(), n));
    
    return 0;
}