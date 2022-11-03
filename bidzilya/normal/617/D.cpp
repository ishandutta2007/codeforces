#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1;
    int x2, y2;
    int x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3)) {
        cout << 1 << endl;
        return 0;
    }

    if ((x1 == x2 && (y3 <= min(y1, y2) || y3 >= max(y1, y2))) ||
        (x1 == x3 && (y2 <= min(y1, y3) || y2 >= max(y1, y3))) ||
        (x2 == x3 && (y1 <= min(y2, y3) || y1 >= max(y2, y3))) ||
        (y1 == y2 && (x3 <= min(x1, x2) || x3 >= max(x1, x2))) ||
        (y1 == y3 && (x2 <= min(x1, x3) || x2 >= max(x1, x3))) ||
        (y2 == y3 && (x1 <= min(x2, x3) || x1 >= max(x2, x3))))
    {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;

    return 0;
}