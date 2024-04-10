#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, ans;

int main() {
    cin >> n;
    if (n % 3 == 0) {
        ans = 2 * (n / 3);
    } else {
        ans = 1 + 2 * (n / 3);
    }
    cout << ans << endl;
    return 0;
}