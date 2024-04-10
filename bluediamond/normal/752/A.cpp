#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << (k + 2 * m - 1) / (2 * m) << ' ' << (k - ((k - 1) / (2 * m) * 2 * m) + 1) / 2 << ' ';
    if (k&1) {
        cout << 'L';
    }
    else {
        cout << 'R';
    }
    return 0;
}