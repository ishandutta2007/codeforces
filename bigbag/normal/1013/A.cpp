#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, x, sum;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum -= x;
    }
    if (sum >= 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}