#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    vector<int> is_p(1000, 1);
    is_p[1] = 0;
    for (int i = 2; i < 1000; ++i) {
        if (is_p[i]) {
            for (int j = i + i; j < 1000; j += i) {
                is_p[j] = 0;
            }
        }
    }
    for (int i = 2; i < 1000; ++i) {
        if (is_p[i]) {
            for (int j = i; j < 1000; ++j) {
                if (is_p[j]) {
                    if (i * j == x) {
                        cout << i << j << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}