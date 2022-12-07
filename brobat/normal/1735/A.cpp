#include <bits/stdc++.h>
using namespace std;

int diff(int a, int b, int c) {
    if(min({a, b, c}) <= 0) return 0;
    return min({abs(a - b), abs(b - c), abs(a - c)});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int x = n - 4;
        int y = (n - 4)/3;
        cout << max({diff(1, y, x - y), diff(1, y - 1, x - y + 1), diff(1, y + 1, x - y - 1)}) << '\n';
    }
    
    return 0;
}