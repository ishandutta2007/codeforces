#include <bits/stdc++.h>
 
using namespace std;
 
void tc() {
    int n ,i, a, b, c;
    cin >> n;
    b = c=  0;
    for (i = 1; i <= n; i++) {
        cin >> a;
        if (a == 0) {
            if (c) b++;
            c = 0;
        }
        else {
            c++;
        }
    }
    if (c) b++;
    cout << min(2, b) << "\n";
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