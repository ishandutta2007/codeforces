#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, s, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    --s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (a[0] == 0) {
        cout << "NO" << endl;
    } else if (a[s] == 1) {
        cout << "YES" << endl;
    } else if (b[s] == 0) {
        cout << "NO" << endl;
    } else {
        for (int i = s; i < n; ++i) {
            if (a[i] == 1 && b[i] == 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}