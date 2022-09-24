#include <bits/stdc++.h>
 
using namespace std;
 
void tc() {
    int n, z, i, a, b = 0;
    cin >> n >> z;
    for (i = 1; i <= n; i++) {
        cin >> a;
        b = max(b, a | z);
    }
    cout << b << "\n";
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    for (cin >> t; t--; ) {
        tc();
    }
    
    return 0;
}