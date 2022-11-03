#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> result(2 * n, -1);
    for (int i = 0, j = 1; j < n; ++i, j += 2) {
        result[i] = result[i + (n - j)] = j;
    }
    for (int i = n, j = 2; j < n; ++i, j += 2) {
        result[i] = result[i + (n - j)] = j;
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (result[i] == -1) {
            result[i] = n;
        }
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}