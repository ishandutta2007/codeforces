#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int B[5] = {1, 1, 2, 7, 4};

int f[5];

int main() {
    int ans = 0, pos = 0, x;
    while (cin >> x) {
        f[pos] += x;
        pos = (pos + 1) % 5;
    }
    ans = 1000000;
    for (int i = 0; i < 5; ++i) ans = min(ans, f[i] / B[i]);
    cout << ans << endl;
    return 0;
}