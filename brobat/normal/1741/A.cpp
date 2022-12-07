#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int x = (a.back() == 'S' ? 0 : (a.back() == 'M' ? 1 : 2));
        int y = (b.back() == 'S' ? 0 : (b.back() == 'M' ? 1 : 2));
        if(x == y) {
            int p = a.length();
            int q = b.length();
            if(x > 0) cout << (p < q ? '<' : (p == q ? '=' : '>')) << '\n';
            else cout << (p < q ? '>' : (p == q ? '=' : '<')) << '\n';
        } else cout << (x < y ? '<' : '>') << '\n';
    }
    
    return 0;
}