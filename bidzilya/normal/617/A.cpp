#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int y = 0;
    int result = 0;
    while (y != x) {
        result += 1;
        y = min(x, y + 5);
    }
    cout << result << endl;

    return 0;
}