#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        cout << min(
            rb <= rd ? rd - rb : 2 * n - rb - rd,
            cb <= cd ? cd - cb : 2 * m - cb - cd
        ) << '\n';
    }
    return 0;
}