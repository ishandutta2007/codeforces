/**
 *  created: 21/12/2020, 17:27:17
**/

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    if (n % 2 == 0) {
        cout << (n / 2 + 1) * (n / 2 + 1) << endl;
    } else {
        cout << 2 * (n / 2 + 1) * (n / 2 + 2) << endl;
    }
    return 0;
}