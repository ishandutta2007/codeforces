#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int c[8];
    for (int i = 0; i <= 7; ++i) {
        c[i] = 0;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 5 || x == 7) {
            cout << -1 << endl;
            return 0;
        }
        ++c[x];
    }
    
    if (c[4] + c[6] != n / 3) {
        cout << -1 << endl;
        return 0;
    }
    
    if (c[2] + c[3] != n / 3) {
        cout << -1 << endl;
        return 0;
    }
    
    if (c[4] > c[2]) {
        cout << -1 << endl;
        return 0;
    }
    
    if (c[3] > c[6]) {
        cout << -1 << endl;
        return 0;
    }
    
    if (c[1] != n / 3) {
        cout << -1 << endl;
        return 0;
    }
    
    if (c[6] != c[3] + c[2] - c[4]) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 0; i < c[4]; ++i) {
        cout << "1 2 4" << endl;
    }
    
    for (int i = 0; i < c[2] - c[4]; ++i) {
        cout << "1 2 6" << endl;
    }
    
    for (int i = 0; i < c[3]; ++i) {
        cout << "1 3 6" << endl;
    }
    
    return 0;
}