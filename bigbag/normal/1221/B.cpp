#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "BW"[(i % 2) ^ (j % 2)];
        }
        cout << "\n";
    }
    return 0;
}