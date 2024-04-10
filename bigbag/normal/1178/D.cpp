#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, used[max_n];

void get_all_p() {
    used[0] = 1;
    used[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        if (!used[i]) {
            for (int j = i * i; j < max_n; j += i) {
                used[j] = 1;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_p();
    cin >> n;
    int cnt = n;
    for (int i = 0; i <= n / 2; ++i) {
        if (used[cnt + i] == 0) {
            cout << cnt + i << endl;
            cout << 1 << " " << n << endl;
            for (int j = 1; j < n; ++j) {
                cout << j << " " << j + 1 << endl;
            }
            for (int j = 1; j <= i; ++j) {
                cout << j << " " << j + n / 2 << endl;
            }
            return 0;
        }
    }
    return 0;
}