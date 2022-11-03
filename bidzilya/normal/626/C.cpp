#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const int MAX_A = 1e7;
    int c2 = 0;
    int c3 = 0;
    int c6 = 0;
    for (int i = 1; i < MAX_A; ++i) {
        if (i % 6 == 0) {
            ++c6;
        } else if (i % 2 == 0) {
            ++c2;
        } else if (i % 3 == 0) {
            ++c3;
        }

        int rn = n - min(n, c2);
        int rm = m - min(m, c3);

        if (rn + rm <= c6) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}