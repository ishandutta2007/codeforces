#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x0, y0;
    int x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int dx = abs(x0 - x1);
    int dy = abs(y0 - y1);

    cout << max(dx, dy) << endl;

    return 0;
}