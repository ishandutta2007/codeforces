/**
 *  created: 11/12/2021, 12:09:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, a, b;

bool ok(const vector<int> &v, int n, int a, int b) {
    if (v.size() != n) {
        return 0;
    }
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        if (v[i] < 0 || v[i] >= n || used[v[i]]) {
            return 0;
        }
        used[v[i]] = 1;
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            --a;
        }
        if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
            --b;
        }
    }
    //cout << "#" << a << " " << b << endl;
    return a == 0 && b == 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        bool rev = 0;
        if (a < b) {
            swap(a, b);
            rev = 1;
        }
        const int A = a, B = b;
        vector<int> v;
        if (a != b && a != b + 1) {
            cout << "-1\n";
            continue;
        }
        if (a + b > n - 2) {
            cout << "-1\n";
            continue;
        }
        int x = 0, y = n - 1;
        if (a == b) {
            for (int i = 0; i < a; ++i) {
                v.push_back(x);
                v.push_back(y);
                ++x;
                --y;
            }
            for (int i = x; i <= y; ++i) {
                v.push_back(i);
            }
        } else {
            for (int i = 0; i < a; ++i) {
                v.push_back(x);
                v.push_back(y);
                ++x;
                --y;
            }
            for (int i = y; i >= x; --i) {
                v.push_back(i);
            }
        }
        if (!ok(v, n, A, B) && 0) {
            exit(228);
        } else {
            if (rev) {
                for (int &x : v) {
                    x = n - 1 - x;
                }
            }
            for (int x : v) {
                cout << x + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}