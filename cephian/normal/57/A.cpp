#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n, x[2], y[2];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> x[0] >> y[0] >> x[1] >> y[1];

    if (x[0] == n - x[1])
        cout << n + min(y[0] + y[1], 2 * n - y[0] - y[1]);
    else if (y[0] == n - y[1])
        cout << n + min(x[0] + x[1], 2 * n - x[0] - x[1]);
    else
        cout << abs(x[0] - x[1]) + abs(y[0] - y[1]);
    cout << "\n";

    return 0;
}