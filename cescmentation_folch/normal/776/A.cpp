#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    
    string a, b;
    cin >> a >> b;
    cin >> n;
    
    while (n--) {
        cout << a << ' ' << b << '\n';
        string c, d;
        cin >> c >> d;
        if (a == c) a = d;
        else b = d;
    }
    cout << a << ' ' << b << '\n';
}