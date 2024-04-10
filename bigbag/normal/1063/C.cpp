#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n;

bool query(int x, int y = 0) {
    cout << x << " " << y << endl;
    string res;
    cin >> res;
    return res == "black";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    bool first = query(0);
    int mx = 0, pw = (1 << (n - 2)), z = 1;
    int x = 0;
    for (int i = 1; i < n; ++i) {
        x += z * pw;
        bool res = query(x);
        if (res == first) {
            mx = x;
            z = 1;
        } else {
            z = -1;
        }
        pw /= 2;
    }
    if (mx == 0) {
        cout << "1 1 2 3" << endl;
    } else {
        cout << mx << " " << 1 << " " << mx - 1 << " " << 3 << endl;
    }
    return 0;
}