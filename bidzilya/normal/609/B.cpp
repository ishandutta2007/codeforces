#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> count(m, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++count[x - 1];
    }

    long long result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            result += count[i] * count[j];
        }
    }

    cout << result << endl;

    return 0;
}