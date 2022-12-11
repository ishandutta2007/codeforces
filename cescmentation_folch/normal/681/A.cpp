#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> a >> x >> y;
        if (x >= 2400 and y > x) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}