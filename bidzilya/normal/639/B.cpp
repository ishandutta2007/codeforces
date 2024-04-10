#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, h;
    cin >> n >> d >> h;

    if (d == 1) {
        if (n > 2) {
            cout << -1 << endl;
        } else {
            cout << 1 << " " << 2 << endl;
        }
        return 0;
    }

    if (d > 2 * h) {
        cout << -1 << endl;
        return 0;
    }

    if (h == 1) {
        for (int i = 2; i <= n; ++i) {
            cout << 1 << " " << i << '\n';
        }
        cout.flush();
        return 0;
    }

    for (int i = 1; i <= h; ++i) {
        cout << i << " " << i + 1 << '\n';
    }

    if (h != d) {
        cout << 1 << " " << h + 2 << '\n';
        for (int i = h + 2; i <= d; ++i) {
            cout << i << " " << i + 1 << '\n';
        }
        for (int i = d + 2; i <= n; ++i) {
            cout << 1 << " " << i << '\n';
        }
    } else {
        for (int i = h + 2; i <= n; ++i) {
            cout << 2 << " " << i << '\n';
        }
    }
    cout.flush();

    return 0;
}