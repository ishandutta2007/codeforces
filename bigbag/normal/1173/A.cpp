#include <bits/stdc++.h>

using namespace std;

int x, y, z;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y >> z;
    x -= y;
    if (x + z < 0) {
        cout << "-" << endl;
    } else if (x - z == 0 && x + z == 0) {
        cout << 0 << endl;
    } else if (x - z > 0) {
        cout << "+" << endl;
    } else {
        cout << "?" << endl;
    }
    return 0;
}