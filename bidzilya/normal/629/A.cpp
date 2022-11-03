#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n, 0), r(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char x;
            cin >> x;
            if (x == 'C') {
                ++c[j];
                ++r[i];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += (r[i] * (r[i] - 1) / 2);
    }
    for (int i = 0; i < n; ++i) {
        result += (c[i] * (c[i] - 1) / 2);
    }
    cout << result << endl;

    return 0;
}