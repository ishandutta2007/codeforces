#include <bits/stdc++.h>

using namespace std;

const int max_n = 25, inf = 1000111222;

int n, add[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    add[1] = 0;
    for (int i = 2; i < max_n; ++i) {
        add[i] = 2 * add[i - 1];
        if (i % 2 == 0) {
            ++add[i];
        }
        //cout << i << ": " << add[i] << endl;
    }
    cin >> n;
    int h = 1, cur = 1, x = 2;
    while (cur + x <= n) {
        cur += x;
        x *= 2;
        ++h;
    }
    if (cur + add[h] == n || cur + add[h] + 1 == n) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}