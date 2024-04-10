#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n;
pair<int, int> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int sum = 0, x;
        for (int j = 0; j < 4; ++j) {
            cin >> x;
            sum += x;
        }
        a[i] = {-sum, i};
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (a[i].second == 0) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    return 0;
}