#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, t, r;
    cin >> m >> t >> r;

    vector<int> w(m);
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }

    if (t < r) {
        cout << -1 << endl;
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> qs;

    int result = 0;
    for (int i = 0; i < m; ++i) {
        while (!qs.empty() && qs.top() + t <= w[i]) {
            qs.pop();
        }

        if ((int) qs.size() >= r) {
            continue;
        } else {
            int need = r - (int) qs.size();
            for (int j = 1; j <= need; ++j) {
                qs.push(w[i] - j + 1);
            }
            result += need;
        }
    }

    cout << result << endl;

    return 0;
}