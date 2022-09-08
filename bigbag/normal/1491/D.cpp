/**
 *  created: 28/02/2021, 16:31:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

bool get_bit(int x, int pos) {
    return (x >> pos) & 1;
}

bool solve(int from, int to) {
    if (from > to) {
        return false;
    }
    vector<int> a, b;
    for (int i = 0; i < 30; ++i) {
        if (get_bit(from, i)) {
            a.push_back(i);
        }
        if (get_bit(to, i)) {
            b.push_back(i);
        }
    }
    if (a.size() < b.size()) {
        return false;
    }
    for (int i = 0; i < b.size(); ++i) {
        if (a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &x, &y);
        if (solve(x, y)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}