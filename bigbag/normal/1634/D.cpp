/**
 *  created: 06/02/2022, 16:58:44
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;

int ask(int i, int j, int k) {
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int res;
    cin >> res;
    return res;
}

pair<int, int> proc(int x, int y) {
    int res = -1, val = -1;
    for (int i = 0; i < n; ++i) {
        if (i != x && i != y) {
            int q = ask(x, y, i);
            if (q > val) {
                res = i;
                val = q;
            }
        }
    }
    return {res, val};
}

void ans(int a, int b) {
    cout << "! " << a + 1 << " " << b + 1 << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        int a = proc(0, 1).first;
        auto [b, val] = proc(0, a);
        int ind = 1;
        while (ind == a || ind == b) {
            ++ind;
        }
        if (ask(0, a, ind) == val) {
            ans(0, a);
        } else if (ask(0, b, ind) == val) {
            ans(0, b);
        } else {
            ans(a, b);
        }
    }
    return 0;
}