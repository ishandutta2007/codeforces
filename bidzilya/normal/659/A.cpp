#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    --a;

    a += b;

    a %= n;
    if (a < 0) {
        a += n;
    }
    if (a >= n) {
        a -= n;
    }

    cout << a + 1 << endl;

    return 0;
}