#include <bits/stdc++.h>

using namespace std;

int y, b, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> y >> b >> r;
    cout << 3 * min({y, b - 1, r - 2}) + 3 << endl;
    return 0;
}